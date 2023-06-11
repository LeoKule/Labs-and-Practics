#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Device.h"

int main() {
    setlocale(LC_ALL, "Rus");
    // ������ �������� �������� �� �����
    std::ifstream file("devices.txt");
    if (!file) {
        std::cerr << "Failed to open devices.txt" << std::endl;
        return 1;
    }

    std::vector<Device*> devices;

    std::string line;
    while (std::getline(file, line)) {
        // �������� ������� �� ������ ������������ ��������
        if (line == "�������� 230" || line == "���� ��314" || line == "���������� CE308") {
            devices.push_back(new EnergyMeter(line));
        } else if (line == "Reallab NL-16HV" || line == "������������� PRE-16" || line == "������������ ����-1-24") {
            devices.push_back(new InputBlock(line));
        } else if (line == "Ouman S203" || line == "���� ���232") {
            devices.push_back(new HeatingControlBlock(line));
        } else {
            std::cerr << "Unknown device: " << line << std::endl;
        }
    }

    // ����� ������ poll ��� ������� �������
    for (Device* device : devices) {
        device->poll();
    }

    // ������������ ������
    for (Device* device : devices) {
        delete device;
    }

    return 0;
}
