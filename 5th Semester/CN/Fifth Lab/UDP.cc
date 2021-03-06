#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("FirstScriptExample");

int main(int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  Time::SetResolution(Time::NS);
  LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer clients;
  clients.Create(2);

  NodeContainer servers;
  servers.Create(1);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
  pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

  NetDeviceContainer firstDevices;
  firstDevices = pointToPoint.Install(clients.Get(0), servers.Get(0));

  pointToPoint.SetDeviceAttribute("DataRate", StringValue("7Mbps"));
  pointToPoint.SetChannelAttribute("Delay", StringValue("1ms"));

  NetDeviceContainer secondDevices;
  secondDevices = pointToPoint.Install(clients.Get(1), servers.Get(0));

  InternetStackHelper stack;
  stack.Install(clients);
  stack.Install(servers);

  Ipv4AddressHelper address;
  address.SetBase("10.1.1.0", "255.255.255.0");
  Ipv4AddressHelper address2;
  address2.SetBase("10.1.2.0", "255.255.255.0");

  Ipv4InterfaceContainer firstInterfaces = address.Assign(firstDevices);
  Ipv4InterfaceContainer secondInterfaces = address2.Assign(secondDevices);

  UdpEchoServerHelper echoServerProcess1(9);
  UdpEchoServerHelper echoServerProcess2(35432);

  ApplicationContainer serverApps1 = echoServerProcess1.Install(servers.Get(0));
  serverApps1.Start(Seconds(0.0));
  serverApps1.Stop(Seconds(10.0));

  ApplicationContainer serverApps2 = echoServerProcess2.Install(servers.Get(0));
  serverApps2.Start(Seconds(0.0));
  serverApps2.Stop(Seconds(10.0));

  UdpEchoClientHelper echoClient1(firstInterfaces.GetAddress(1), 9);
  echoClient1.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient1.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient1.SetAttribute("PacketSize", UintegerValue(1024));

  UdpEchoClientHelper echoClient2(secondInterfaces.GetAddress(1), 35432);
  echoClient2.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient2.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient2.SetAttribute("PacketSize", UintegerValue(1024));

  ApplicationContainer clientApps1 = echoClient1.Install(clients.Get(0));
  clientApps1.Start(Seconds(1.0));
  clientApps1.Stop(Seconds(10.0));

  ApplicationContainer clientApps2 = echoClient2.Install(clients.Get(1));
  clientApps2.Start(Seconds(1.0));
  clientApps2.Stop(Seconds(10.0));

  Simulator::Run();
  Simulator::Destroy();
  return 0;
}
