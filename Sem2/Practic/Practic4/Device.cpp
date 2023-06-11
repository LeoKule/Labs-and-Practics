#include "Device.h"
#include <iostream>

// Класс EnergyMeter

EnergyMeter::EnergyMeter(const std::string& name) : name(name) {}

void EnergyMeter::poll() {
    std::cout << "Счетчики электрической энергии: " << name << std::endl;
    // Реализация получения данных от счетчика электрической энергии
}

// Класс InputBlock

InputBlock::InputBlock(const std::string& name) : name(name) {}

void InputBlock::poll() {
    std::cout << "Блоки ввода дискретных сигналов: " << name << std::endl;
    // Реализация получения данных от блока ввода дискретных сигналов
}

// Класс HeatingControlBlock

HeatingControlBlock::HeatingControlBlock(const std::string& name) : name(name) {}

void HeatingControlBlock::poll() {
    std::cout << "Блоки управления отоплением: " << name << std::endl;
    // Реализация получения данных от блока управления отоплением
}
