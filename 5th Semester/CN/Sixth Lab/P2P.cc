#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1   n2   n3   n4
//    point-to-point  |    |    |    |
//                    ================
//                      LAN 10.1.2.0

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("SecondScriptExample");

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

  NodeContainer p2pNodes1, p2pNodes2, csmaNodes;
  p2pNodes1.Create(2);
  p2pNodes2.Create(2);

  csmaNodes.Add(p2pNodes1.Get(1));
  csmaNodes.Create(nCsma);
  csmaNodes.Add(p2pNodes2.Get(1));

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
  pointToPoint.SetChannelAttribute("Delay", StringValue("1500ms"));

  NetDeviceContainer p2pDevices1, p2pDevices2, csmaDevices;
  p2pDevices1 = pointToPoint.Install(p2pNodes1);
  p2pDevices2 = pointToPoint.Install(p2pNodes2);

  CsmaHelper csma;
  csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
  csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

  csmaDevices = csma.Install(csmaNodes);

  InternetStackHelper stack;
  stack.Install(p2pNodes1.Get(0));
  stack.Install(p2pNodes2.Get(0));
  stack.Install(csmaNodes);

  Ipv4AddressHelper address;
  Ipv4InterfaceContainer p2pInterfaces1, p2pInterfaces2, csmaInterfaces;

  address.SetBase("10.1.1.0", "255.255.255.0");
  p2pInterfaces1 = address.Assign(p2pDevices1);

  address.SetBase("10.1.2.0", "255.255.255.0");
  p2pInterfaces2 = address.Assign(p2pDevices2);

  address.SetBase("10.1.3.0", "255.255.255.0");
  csmaInterfaces = address.Assign(csmaDevices);

  UdpEchoServerHelper echoServer(9);

  ApplicationContainer serverApps = echoServer.Install(csmaNodes.Get(2));
  serverApps.Start(Seconds(1.0));
  serverApps.Stop(Seconds(10.0));

  UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(2), 9);
  echoClient.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient.SetAttribute("PacketSize", UintegerValue(1024));

  UdpEchoClientHelper echoClient2(csmaInterfaces.GetAddress(2), 9);
  echoClient2.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient2.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient2.SetAttribute("PacketSize", UintegerValue(1024));

  ApplicationContainer clientApps = echoClient.Install(p2pNodes1.Get(0));
  clientApps.Start(Seconds(2.0));
  clientApps.Stop(Seconds(10.0));

  ApplicationContainer clientApps2 = echoClient2.Install(p2pNodes2.Get(0));
  clientApps2.Start(Seconds(5.0));
  clientApps2.Stop(Seconds(10.0));

  Ipv4GlobalRoutingHelper::PopulateRoutingTables();

  pointToPoint.EnablePcapAll("second");
  csma.EnablePcap("second", csmaDevices.Get(1), true);

  Simulator::Run();
  Simulator::Destroy();
  return 0;
}
