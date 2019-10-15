/* Create a simple topology of four nodes separated by a point-to-point link. 
   Setup a UdpClient on Node1 and a UdpServer on Node2. Let the data rate be set 8 Mbps and the delay be 3ms. 
   Now Setup another UdpClient on Node4 and a server instance on Node3. Let the data rate be set 7 Mbps and the delay be 1 ms. 
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

    // Can use nodes.Create(4)
    NodeContainer clients;
    clients.Create(2);
    Node *server = new Node();

    PointToPointHelper pointToPoint;
    NetDeviceContainer devicePairs[2];
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("8Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("3ms"));
    devicePairs[0] = pointToPoint.Install(clients.Get(0), server);
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("7Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("1ms"));
    devicePairs[1] = pointToPoint.Install(server, clients.Get(1)); //1

    InternetStackHelper stack;
    stack.Install(server);
    stack.Install(clients);

    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");

    Ipv4InterfaceContainer interfaces[2];
    interfaces[0] = address.Assign(devicePairs[0]);
    interfaces[1] = address.Assign(devicePairs[1].Get(1));
    interfaces[1].Add(interfaces[0].Get(0));

    UdpEchoServerHelper *echoServer[2] = {new UdpEchoServerHelper(9), new UdpEchoServerHelper(35432)};
    UdpEchoClientHelper *echoClients[2] = {new UdpEchoClientHelper(interfaces[0].GetAddress(1), 9),
                                           new UdpEchoClientHelper(interfaces[0].GetAddress(1), 9)}; //35432

    for (UdpEchoClientHelper *echoClient : echoClients)
    {
        echoClient->SetAttribute("MaxPackets", UintegerValue(1));
        echoClient->SetAttribute("Interval", TimeValue(Seconds(1.0)));
        echoClient->SetAttribute("PacketSize", UintegerValue(1024));
    }

    ApplicationContainer serverApp = echoServer[0]->Install(server); //2
    // echoServer[1]->Install(servers.Get(1))};
    ApplicationContainer clientApps[2] = {echoClients[0]->Install(clients.Get(0)), echoClients[1]->Install(clients.Get(1))};

    serverApp.Start(Seconds(0.0));
    serverApp.Stop(Seconds(10.0));

    for (int i = 0; i < *(&clientApps + 1) - clientApps; i++)
    {
        clientApps[i].Start(Seconds(i));
        clientApps[i].Stop(Seconds(10.0));
    }

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
