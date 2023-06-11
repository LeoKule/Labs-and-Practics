#pragma once
#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

// Базовый класс для всех приборов
class Device {
public:
    virtual void poll() = 0;
};

// Класс для счетчиков электрической энергии
class EnergyMeter : public Device {
public:
    explicit EnergyMeter(const std::string& name);

    void poll() override;

private:
    std::string name;
};

// Класс для блоков ввода дискретных сигналов
class InputBlock : public Device {
public:
    explicit InputBlock(const std::string& name);

    void poll() override;

private:
    std::string name;
};

// Класс для блоков управления отоплением
class HeatingControlBlock : public Device {
public:
    explicit HeatingControlBlock(const std::string& name);

    void poll() override;

private:
    std::string name;
};

#endif  // DEVICE_HPP
