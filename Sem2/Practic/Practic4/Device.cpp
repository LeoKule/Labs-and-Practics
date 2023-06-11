#include "Device.h"
#include <iostream>

// ����� EnergyMeter

EnergyMeter::EnergyMeter(const std::string& name) : name(name) {}

void EnergyMeter::poll() {
    std::cout << "�������� ������������� �������: " << name << std::endl;
    // ���������� ��������� ������ �� �������� ������������� �������
}

// ����� InputBlock

InputBlock::InputBlock(const std::string& name) : name(name) {}

void InputBlock::poll() {
    std::cout << "����� ����� ���������� ��������: " << name << std::endl;
    // ���������� ��������� ������ �� ����� ����� ���������� ��������
}

// ����� HeatingControlBlock

HeatingControlBlock::HeatingControlBlock(const std::string& name) : name(name) {}

void HeatingControlBlock::poll() {
    std::cout << "����� ���������� ����������: " << name << std::endl;
    // ���������� ��������� ������ �� ����� ���������� ����������
}
