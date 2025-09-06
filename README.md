# 🔍 Proyecto: Escáner de Puertos en C++

## 📝 Descripción general
Proyecto de **escaner de puertos rapido** desarrollado en C++ para **Windows**, utilizando la biblioteca **Boost.Asio**.
Permite escanear rangos de puertos o listas especificas de manera eficiente.

---

## 👥 Integrantes del equipo
    - Angel Adrian Alvarez Flores               [angelaf2005]
    - Abraham Alejandro Carrreon Soriano        [Abraham-Carreon]
    - Jesus Kenneth Maurizio Martinez Vazquez   []
    - Raul Alejandro Rios Turrubiates           [RSKR0]


## 🖥️ Instrucciones de compilación y ejecución

### ✅ Requisitos
    - Sistema operativo: Windows
    - Compilador: g++
    - Librerías necesarias: Boost.Asio

### ⚙️ Instalación
1. Clonar el repositorio:
```bash
git clone https://github.com/Angelaf2005/Esc-ner-C--.git
cd Esc-ner-C--
```

2. Compilar:
Asegurate de tener instalado Boost.Asio y un compilador compatible con C++ (ej. g++ de MinGW).
```bash
g++ .\src\main.cpp .\src\validaciones.cpp .\src\registro.cpp .\src\art.cpp .\src\escaneo.cpp -o portscaner.exe -lws2_32
```
Nota: -lws2_32 es necesesario para la libreria de sockets en Windows.

3. Uso:
Ejecutar el binario generado.
```bash
./portscanner.exe
```
El programa pedira la dirección IP y un rango o lista de puertos, luego mostrara el estado de cada puerto.

## 📝 Librerias del proyecto
Boost.Asio -> Manejo de conexiones TCP/UDP.
Librerias estandar de C++.

## 💡 Recomendaciones
Tener en cuenta que algunos antivirus podrían detectar el binario como malicioso.

## 📄 Licencia
Este proyecto está bajo la **MIT License** - mira el archivo [LICENSE](LICENSE) para más detalles.
