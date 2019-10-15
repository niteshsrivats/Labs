/* Create a simple topology of four nodes separated by a point-to-point link. 
   Setup a UdpClient on Node1 and a UdpServer on Node2. Let the data rate be set 5 Mbps and the delay be 2 ms. 
   Now Setup another UdpClient on Node3 & Node 4 and a server instance on Node2. Let the data rate be set 7 Mbps and the delay be 1 ms. 
   Set the parameters for the clients. Run the simulation and observe the results. */

#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

using namespace ns3;

int main(int argc, char *argv[])
{
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    NodeContainer clients, servers;
    clients.Create(3);
    servers.Create(1);

    PointToPointHelper pointToPoint;
    NetDeviceContainer devicePairs[3];
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));
    devicePairs[0] = pointToPoint.Install(clients.Get(0), servers.Get(0));
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("7Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("1ms"));
    devicePairs[1] = pointToPoint.Install(servers.Get(0), clients.Get(1));
    devicePairs[2] = pointToPoint.Install(servers.Get(0), clients.Get(2));

    InternetStackHelper stack;
    stack.Install(servers);
    stack.Install(clients);

    Ipv4AddressHelper address;
    Ipv4InterfaceContainer interfaces[3];
    address.SetBase("10.1.1.0", "255.255.255.0");
    interfaces[0] = address.Assign(devicePairs[0]);
    address.SetBase("10.1.2.0", "255.255.255.0");
    interfaces[1] = address.Assign(devicePairs[1]);
    address.SetBase("10.1.3.0", "255.255.255.0");
    interfaces[2].Add(address.Assign(devicePairs[2]));

    UdpEchoServerHelper *echoServer[2] = {new UdpEchoServerHelper(9), new UdpEchoServerHelper(35432)};
    UdpEchoClientHelper *echoClients[3] = {new UdpEchoClientHelper(interfaces[0].GetAddress(1), 9),
                                           new UdpEchoClientHelper(interfaces[1].GetAddress(0), 35432),
                                           new UdpEchoClientHelper(interfaces[2].GetAddress(0), 35432)};

    for (UdpEchoClientHelper *echoClient : echoClients)
    {
        echoClient->SetAttribute("MaxPackets", UintegerValue(1));
        echoClient->SetAttribute("Interval", TimeValue(Seconds(1.0)));
        echoClient->SetAttribute("PacketSize", UintegerValue(1024));
    }

    ApplicationContainer serverApps[2] = {echoServer[0]->Install(servers.Get(0)),
                                          echoServer[1]->Install(servers.Get(0))};
    ApplicationContainer clientApps[3] = {echoClients[0]->Install(clients.Get(0)),
                                          echoClients[1]->Install(clients.Get(1)),
                                          echoClients[2]->Install(clients.Get(2))};

    for (ApplicationContainer serverApp : serverApps)
    {
        serverApp.Start(Seconds(0.0));
        serverApp.Stop(Seconds(10.0));
    }

    for (int i = 0; i < *(&clientApps + 1) - clientApps; i++)
    {
        clientApps[i].Start(Seconds(i));
        clientApps[i].Stop(Seconds(10.0));
    }

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
