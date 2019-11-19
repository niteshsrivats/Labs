
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/animation-interface.h"

using namespace ns3;

int main(int argc, char *argv[])
{

  LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer p2pNodes, csmaNodes;
  p2pNodes.Create(2);
  csmaNodes.Add(p2pNodes.Get(1));
  csmaNodes.Create(2);

  PointToPointHelper pointToPoint;
  CsmaHelper csma;
  pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
  pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));
  csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
  csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(5)));

  NetDeviceContainer p2pDevices, csmaDevices;
  p2pDevices = pointToPoint.Install(p2pNodes);
  csmaDevices = csma.Install(csmaNodes);

  InternetStackHelper stack;
  stack.Install(p2pNodes.Get(0));
  stack.Install(csmaNodes);

  Ipv4AddressHelper address;
  Ipv4InterfaceContainer p2pInterfaces, csmaInterfaces;
  address.SetBase("10.1.1.0", "255.255.255.0");
  p2pInterfaces = address.Assign(p2pDevices);
  address.SetBase("20.1.2.0", "255.255.255.0");
  csmaInterfaces = address.Assign(csmaDevices);

  UdpEchoServerHelper echoServer(9);

  ApplicationContainer serverApps = echoServer.Install(csmaNodes.Get(2));
  serverApps.Start(Seconds(1.0));
  serverApps.Stop(Seconds(10.0));

  UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(2), 9);
  echoClient.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient.SetAttribute("PacketSize", UintegerValue(1024));

  ApplicationContainer clientApps = echoClient.Install(p2pNodes.Get(0));
  clientApps.Start(Seconds(2.0));
  clientApps.Stop(Seconds(10.0));

  Ipv4GlobalRoutingHelper::PopulateRoutingTables();

  // pointToPoint.EnablePcapAll ("second");
  // csma.EnablePcap ("second", csmaDevices.Get (1), true);

  AnimationInterface anim("anim_sec.xml");
  anim.SetConstantPosition(p2pNodes.Get(0), 0, 0);
  anim.SetConstantPosition(p2pNodes.Get(1), 25.0, 25.0);
  anim.SetConstantPosition(csmaNodes.Get(1), 50, 50);
  anim.SetConstantPosition(csmaNodes.Get(2), 75, 75);
  anim.EnablePacketMetadata(true);

  Simulator::Run();
  Simulator::Destroy();
  return 0;
}