#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


void saveFile(int port, int status, const string& ip, string filename) {
    // Verificar si el archivo ya existe
    bool archivo_existe = false;
    ifstream infile(filename);

    if (infile.good()) {
        archivo_existe = true;
    }
    infile.close();

    // Abrir el archivo en modo append+
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error al abrir el archivo " << filename << " para escribir." << endl;
        return;
    }

    // Si el archivo no existe, escribir la fecha y hora actuales
    if (archivo_existe == false) {
        time_t now = time(0);
        tm* local_time = localtime(&now);
        outfile << "Fecha y hora: "
                << local_time->tm_mday << "/"
                << (local_time->tm_mon + 1) << "/"
                << (local_time->tm_year + 1900) << " "
                << local_time->tm_hour << ":"
                << local_time->tm_min << ":"
                << local_time->tm_sec << endl
                << "Objetivo: " << ip << endl
                << "Resultados del escaneo de puertos:" << endl << endl;
    }

    // Escribir el resultado en el archivo
    outfile << "Puerto " << port << ": " << (status == 1 ? "abierto" : "cerrado") << endl;
    outfile.close();
}
