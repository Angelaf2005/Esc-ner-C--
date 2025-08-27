#include <iostream>
#include "validaciones.h"
#include <string>
#include <regex>
#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;
using boost::asio::ip::tcp;
std::mutex cout_mutex;

bool validar_ip(){
    /// Aquí planeaba usar regex para validar, solo hay que ver qué onda con la excepción de errores
    return true;
}


objetivo* obtener_datos(){
    objetivo* Dir_escaneo = new objetivo;

    std::cout << "Ingresa direccion IP objetivo para el escaneo: " << std::endl;
    std::cin >> Dir_escaneo->ip;
    /// esta función reserva un espacio para el struct que contiene la dirección IP que se asignará al struct

    return Dir_escaneo;
}

bool scanPort(const string& ip, int port, int timeout_ms = 500)
{
    try
    {
        boost::asio::io_context io;
        tcp::endpoint endpoint(boost::asio::ip::make_address(ip), port);
        tcp::socket socket(io);

        boost::asio::steady_timer timer(io);
        bool connected = false;

        socket.async_connect(endpoint, [&](const boost::system::error_code& ec)
        {
            if (!ec) connected = true;
            timer.cancel();
        });

        timer.expires_after(chrono::milliseconds(timeout_ms));
        timer.async_wait([&](const boost::system::error_code& ec){ if (!ec) socket.cancel(); } );

        io.run();
        return connected;
    }

    catch (...)
    {
        return false;
    }
}

void scan(const string& ip, int startPort, int endPort)
{
    vector<thread> threads;

    for (int port = startPort; port <= endPort; ++port)
    {
        threads.emplace_back([ip, port]()
            {
            if (scanPort(ip, port))
            {
                lock_guard<mutex> lock(cout_mutex);
                cout << "Puerto abierto: " << port << endl;
            }
        });
    }

    for (auto& t : threads) t.join();
}
