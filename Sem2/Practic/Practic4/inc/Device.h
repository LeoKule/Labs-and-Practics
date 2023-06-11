#pragma once
#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

// ������� ����� ��� ���� ��������
class Device {
public:
    virtual void poll() = 0;
};

// ����� ��� ��������� ������������� �������
class EnergyMeter : public Device {
public:
    explicit EnergyMeter(const std::string& name);

    void poll() override;

private:
    std::string name;
};

// ����� ��� ������ ����� ���������� ��������
class InputBlock : public Device {
public:
    explicit InputBlock(const std::string& name);

    void poll() override;

private:
    std::string name;
};

// ����� ��� ������ ���������� ����������
class HeatingControlBlock : public Device {
public:
    explicit HeatingControlBlock(const std::string& name);

    void poll() override;

private:
    std::string name;
};

#endif  // DEVICE_HPP
