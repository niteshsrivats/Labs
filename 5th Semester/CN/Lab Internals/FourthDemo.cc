#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

// Default Network Topology
//
//       20.1.1.0
// n0 - n1 -------------- n2   n3   n4   n5
//    point-to-point  |    |    |    |
//                    ================
//                      LAN 30.1.2.0

using namespace ns3;

int main(int argc, char *argv[])
{

    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    NodeContainer p2pNodes, csmaNodes;
    p2pNodes.Create(3);

    csmaNodes.Add(p2pNodes.Get(2));
    csmaNodes.Create(3);

    PointToPointHelper pointToPoint;
    CsmaHelper csma;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));
    csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

    NetDeviceContainer p2pDevices, csmaDevices;
    p2pDevices = pointToPoint.Install(p2pNodes.Get(2), p2pNodes.Get(1));
    p2pDevices.Add(pointToPoint.Install(p2pNodes.Get(1), p2pNodes.Get(0)));
    csmaDevices = csma.Install(csmaNodes);

    InternetStackHelper stack;
    stack.Install(csmaNodes);
    stack.Install(p2pNodes.Get(0));
    stack.Install(p2pNodes.Get(1));

    Ipv4AddressHelper address;
    Ipv4InterfaceContainer p2pInterfaces, csmaInterfaces;

    address.SetBase("20.1.1.0", "255.255.255.0");
    p2pInterfaces = address.Assign(p2pDevices);
    address.SetBase("30.1.2.0", "255.255.255.0");
    csmaInterfaces = address.Assign(csmaDevices);

    UdpEchoServerHelper echoServer(9);
    UdpEchoClientHelper *echoClients[2] = {new UdpEchoClientHelper(csmaInterfaces.GetAddress(1), 9),
                                           new UdpEchoClientHelper(csmaInterfaces.GetAddress(1), 9)};

    for (UdpEchoClientHelper *echoClient : echoClients)
    {
        echoClient->SetAttribute("MaxPackets", UintegerValue(1));
        echoClient->SetAttribute("Interval", TimeValue(Seconds(1.0)));
        echoClient->SetAttribute("PacketSize", UintegerValue(1024));
    }

    ApplicationContainer clientApps[2] = {echoClients[0]->Install(p2pNodes.Get(0)),
                                          echoClients[1]->Install(p2pNodes.Get(1))};

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
