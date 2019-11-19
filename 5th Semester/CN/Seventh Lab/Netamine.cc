#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("SecondLabProgram");

int main(int argc, char *argv[])
{
  bool verbose = true;
  uint32_t nCsma = 2;

  CommandLine cmd;
  cmd.AddValue("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
  cmd.AddValue("verbose", "Tell echo applications to log if true", verbose);

  cmd.Parse(argc, argv);

  if (verbose)
  {
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
  }

  nCsma = nCsma == 0 ? 1 : nCsma;

  NodeContainer p2pNodes1, p2pNodes2;
  p2pNodes1.Create(2);
  p2pNodes2.Create(2);

  NodeContainer csmaNodes;
  csmaNodes.Add(p2pNodes1.Get(1));
  csmaNodes.Add(p2pNodes2.Get(0));
  csmaNodes.Create(nCsma);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
  pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

  NetDeviceContainer p2pDevices1, p2pDevices2;
  p2pDevices1 = pointToPoint.Install(p2pNodes1);
  p2pDevices2 = pointToPoint.Install(p2pNodes2);

  CsmaHelper csma;
  csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
  csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

  NetDeviceContainer csmaDevices;
  csmaDevices = csma.Install(csmaNodes);

  InternetStackHelper stack;
  stack.Install(p2pNodes1.Get(0));
  stack.Install(csmaNodes);
  stack.Install(p2pNodes2.Get(1));

  Ipv4AddressHelper address;
  address.SetBase("10.1.1.0", "255.255.255.0");
  Ipv4InterfaceContainer p2pInterfaces1;
  p2pInterfaces1 = address.Assign(p2pDevices1);

  address.SetBase("10.1.2.0", "255.255.255.0");
  Ipv4InterfaceContainer csmaInterfaces;
  csmaInterfaces = address.Assign(csmaDevices);

  address.SetBase("10.1.3.0", "255.255.255.0");
  Ipv4InterfaceContainer p2pInterfaces2;
  p2pInterfaces2 = address.Assign(p2pDevices2);

  UdpEchoServerHelper echoServer(9);

  ApplicationContainer serverApps = echoServer.Install(csmaNodes.Get(nCsma));
  serverApps.Start(Seconds(1.0));
  serverApps.Stop(Seconds(10.0));

  UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(nCsma), 9);
  echoClient.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient.SetAttribute("PacketSize", UintegerValue(1024));

  ApplicationContainer clientApps1 = echoClient.Install(p2pNodes1.Get(0));
  clientApps1.Start(Seconds(2.0));
  clientApps1.Stop(Seconds(10.0));

  ApplicationContainer clientApps2 = echoClient.Install(p2pNodes2.Get(1));
  clientApps2.Start(Seconds(2.0));
  clientApps2.Stop(Seconds(10.0));

  Ipv4GlobalRoutingHelper::PopulateRoutingTables();

  pointToPoint.EnablePcapAll("second");
  csma.EnablePcap("second", csmaDevices.Get(1), true);

  AnimationInterface anim("animation.xml");
  anim.SetConstantPosition(p2pNodes1.Get(0), 0, 5);
  anim.SetConstantPosition(csmaNodes.Get(0), 10, 5);
  anim.SetConstantPosition(csmaNodes.Get(1), 20, 5);
  anim.SetConstantPosition(csmaNodes.Get(2), 30, 5);
  anim.SetConstantPosition(csmaNodes.Get(3), 40, 5);
  anim.SetConstantPosition(p2pNodes2.Get(1), 50, 5);
  anim.EnablePacketMetadata(true);

  Simulator::Run();
  Simulator::Destroy();
  return 0;
}
