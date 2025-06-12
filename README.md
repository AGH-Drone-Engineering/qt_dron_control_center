# Qt Drone Telemetry Receiver
![Zrzut ekranu z 2025-06-05 02-28-27](https://github.com/user-attachments/assets/ea8e8aba-3089-4a41-bb49-5ed03235a711)

Aplikacja napisana w Qt (C++) służąca do odbioru telemetrii z wielu dronów (ESP32) poprzez protokół UDP. Odbierane dane są przypisane do konkretnego drona na podstawie jego adresu IP.

## ✈️ Funkcje

- Odbiór danych UDP z portu `12345`
- Obsługa do 4 dronów o stałych adresach IP
- Mapowanie adresu IP do ID drona
- Asynchroniczny odbiór danych z użyciem `QUdpSocket`
- Przetwarzanie i wyświetlanie danych telemetrycznych (w konsoli lub GUI)

## 🛠️ Użyte technologie

- **Qt 5** (C++)
- **QUdpSocket** – komunikacja UDP
- **Sygnały i sloty Qt** (`readyRead`)
- GUI – QML lub QtWidgets (opcjonalne)

---

## 🧱 Budowanie aplikacji

### 🔧 Wymagania

- Qt 5.15+ lub Qt 6.x
- CMake 3.14+
- Kompilator C++ z obsługą C++17

### 📦 Kroki

```bash
git clone https://github.com/twoj-projekt/qt-drone-telemetry.git
cd qt-drone-telemetry

mkdir build
cd build

cmake ..
make -j$(nproc)

./qt-drone-telemetry
