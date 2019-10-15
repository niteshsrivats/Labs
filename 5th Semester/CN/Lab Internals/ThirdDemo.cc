#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

// Default Network Topology
//
//       10.1.1.0                                   30.1.3.0
// n0 - n1 -------------- n2   n3   n4   n5 -------------- n6 - n7
//    point-to-point  |    |    |    |           point-to-point
//                    ================
//                      LAN 20.1.2.0

using namespace ns3;

int main(int argc, char *argv[])
{

    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    NodeContainer p2pNodes1, p2pNodes2, csmaNodes;
    p2pNodes1.Create(3);
    p2pNodes2.Create(3);

    csmaNodes.Add(p2pNodes1.Get(2));
    csmaNodes.Create(2);
    csmaNodes.Add(p2pNodes2.Get(0));

    PointToPointHelper pointToPoint;
    CsmaHelper csma;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));
    csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

    NetDeviceContainer p2pDevices1, p2pDevices2, csmaDevices;
    p2pDevices1 = pointToPoint.Install(p2pNodes1.Get(2), p2pNodes1.Get(1));
    p2pDevices1.Add(pointToPoint.Install(p2pNodes1.Get(1), p2pNodes1.Get(0)));
    p2pDevices2 = pointToPoint.Install(p2pNodes2.Get(0), p2pNodes2.Get(1));
    p2pDevices2.Add(pointToPoint.Install(p2pNodes2.Get(1), p2pNodes2.Get(2)));
    csmaDevices = csma.Install(csmaNodes);

    InternetStackHelper stack;
    stack.Install(p2pNodes1);
    stack.Install(p2pNodes2);
    stack.Install(csmaNodes.Get(1));
    stack.Install(csmaNodes.Get(2));

    Ipv4AddressHelper address;
    Ipv4InterfaceContainer p2pInterfaces1, p2pInterfaces2, csmaInterfaces;

    address.SetBase("10.1.1.0", "255.255.255.0");
    p2pInterfaces1 = address.Assign(p2pDevices1);
    address.SetBase("30.1.3.0", "255.255.255.0");
    p2pInterfaces2 = address.Assign(p2pDevices2);
    address.SetBase("20.1.2.0", "255.255.255.0");
    csmaInterfaces = address.Assign(csmaDevices);

    UdpEchoServerHelper echoServer(9);
    UdpEchoClientHelper *echoClients[4] = {new UdpEchoClientHelper(csmaInterfaces.GetAddress(1), 9),
                                           new UdpEchoClientHelper(csmaInterfaces.GetAddress(1), 9),
                                           new UdpEchoClientHelper(csmaInterfaces.GetAddress(1), 9),
                                           new UdpEchoClientHelper(csmaInterfaces.GetAddress(1), 9)};

    for (UdpEchoClientHelper *echoClient : echoClients)
    {
        echoClient->SetAttribute("MaxPackets", UintegerValue(1));
        echoClient->SetAttribute("Interval", TimeValue(Seconds(1.0)));
        echoClient->SetAttribute("PacketSize", UintegerValue(1024));
    }

    ApplicationContainer clientApps[4] = {echoClients[0]->Install(p2pNodes1.Get(0)),
                                          echoClients[1]->Install(p2pNodes1.Get(1)),
                                          echoClients[2]->Install(p2pNodes2.Get(1)),
                                          echoClients[3]->Install(p2pNodes2.Get(2))};

    ApplicationContainer serverApp = echoServer.Install(csmaNodes.Get(1));
    serverApp.Start(Seconds(0.0));
    serverApp.Stop(Seconds(10.0));

    for (int i = 0; i < *(&clientApps + 1) - clientApps; i++)
    {
        clientApps[i].Start(Seconds(i));
        clientApps[i].Stop(Seconds(10.0));
    }

    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
