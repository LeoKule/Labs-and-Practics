#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Device.h"

int main() {
    setlocale(LC_ALL, "Rus");
    // Чтение названий приборов из файла
    std::ifstream file("devices.txt");
    if (!file) {
        std::cerr << "Failed to open devices.txt" << std::endl;
        return 1;
    }

    std::vector<Device*> devices;

    std::string line;
    while (std::getline(file, line)) {
        // Создание прибора на основе прочитанного названия
        if (line == "Меркурий 230" || line == "Нева МТ314" || line == "Энергомера CE308") {
            devices.push_back(new EnergyMeter(line));
        } else if (line == "Reallab NL-16HV" || line == "Приборэлектро PRE-16" || line == "Энергосервис ЭНМВ-1-24") {
            devices.push_back(new InputBlock(line));
        } else if (line == "Ouman S203" || line == "Овен ТРМ232") {
            devices.push_back(new HeatingControlBlock(line));
        } else {
            std::cerr << "Unknown device: " << line << std::endl;
        }
    }

    // Вызов метода poll для каждого прибора
    for (Device* device : devices) {
        device->poll();
    }

    // Освобождение памяти
    for (Device* device : devices) {
        delete device;
    }

    return 0;
}
