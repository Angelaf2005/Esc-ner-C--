#include <iostream>
#include "registro.h"
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <mutex>
#include <map>

using namespace std;
using boost::asio::ip::tcp;
std::mutex cout_mutex;

// Top ports - Todos - Lista - Rango


map <int, string> topPorts =
{
    {20, "FTP Data"},
    {21, "FTP Control"},
    {22, "SSH"},
    {23, "Telnet"},
    {25, "SMTP"},
    {53, "DNS"},
    {67, "DHCP"},
    {68, "DHCP"},
    {80, "HTTP"},
    {110, "POP3"},
    {143, "IMAP"},
    {443, "HTTPS"},
    {3306, "MySQL"},
    {3389, "RDP"},
    {5900, "VNC"},
    {8080, "HTTP Proxy"}
};



int scanPort(const string& ip, int port, int timeout_ms = 1000)
{
    try
    {
        boost::asio::io_context io;
        tcp::endpoint endpoint(boost::asio::ip::make_address(ip), port);
        tcp::socket socket(io);

        boost::asio::steady_timer timer(io);
        int connected;

        socket.async_connect(endpoint, [&](const boost::system::error_code& ec)
        {
			// 1 - Abierto
			// 2 - Cerrado

            if (!ec) connected = 1;
    		else connected = 2;
            timer.cancel();
        });

        timer.expires_after(chrono::milliseconds(timeout_ms));
        timer.async_wait([&](const boost::system::error_code& ec) { if (!ec) socket.cancel(); } );

        io.run();
        return connected;
    }

    catch (...)
    {
        return 3;
    }
}

void scan(const string& ip, int mode = 0 ,int startPort=0, int endPort=0, const vector<int>& ports = {})
{
    vector<thread> threads;
    map<int, int> res;
    mutex res_m;
    vector<int> scanPorts;

    if (mode == 0)
	{ // Rango
        for (int port = startPort; port <= endPort; ++port)
            scanPorts.push_back(port);
    }
	else if (mode == 1)
	{ // Lista
        scanPorts = ports;
    }
	else if (mode == 2)
	{ // Top ports
        for (const auto& p : topPorts)
            scanPorts.push_back(p.first);
    }
	else if (mode == 3)
	{ // Todos
        for (int port = 1; port <= 65535; ++port)
            scanPorts.push_back(port);
    }

    for (int port : scanPorts)
	{
        threads.emplace_back([ip, port, &res, &res_m]()
		{
            int resP = scanPort(ip, port);
            lock_guard<mutex> lock(res_m);
            res[port] = resP;
        });
    }

    for (auto& t : threads) t.join();

    for (int port : scanPorts)
	{
        int resP;
        lock_guard<mutex> lock(res_m);
		resP = res[port];

        // Guardar resultados en el archivo
        saveFile(port, resP, ip);

        switch (resP)
		{
            case 1: cout << "Puerto abierto: " << port << endl; break;
            case 2: cout << "Puerto cerrado: " << port << endl; break;
            default: cout << "Puerto desconocido: " << port << endl; break;
        }

    }
}
