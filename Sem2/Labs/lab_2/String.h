#ifndef LAB_2_STRING_H
#define LAB_2_STRING_H
#include <iostream>
#include <cstring>

class String {
public:
    String() : m_data(nullptr), m_size(0) {}

    String(const char* str) {
        m_size = std::strlen(str);
        m_data = new char[m_size + 1];
        std::copy(str, str + m_size + 1, m_data);
    }

    String(const String& other) {
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        std::copy(other.m_data, other.m_data + m_size + 1, m_data);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new char[m_size + 1];
            std::copy(other.m_data, other.m_data + m_size + 1, m_data);
        }
        return *this;
    }

    String operator+(const String& other) const {
        String result;
        result.m_size = m_size + other.m_size;
        result.m_data = new char[result.m_size + 1];
        std::copy(m_data, m_data + m_size, result.m_data);
        std::copy(other.m_data, other.m_data + other.m_size, result.m_data + m_size);
        result.m_data[result.m_size] = '\0';
        return result;
    }

    String& operator+=(const String& other) {
        std::size_t new_size = m_size + other.m_size;
        char* new_data = new char[new_size + 1];
        std::copy(m_data, m_data + m_size, new_data);
        std::copy(other.m_data, other.m_data + other.m_size, new_data + m_size);
        new_data[new_size] = '\0';
        delete[] m_data;
        m_data = new_data;
        m_size = new_size;
        return *this;
    }


    char& operator[](size_t index) {
        return m_data[index];
    }

    const char& operator[](size_t index) const {
        return m_data[index];
    }

    bool operator==(const String& other) const {
        return (std::strcmp(m_data, other.m_data) == 0);
    }

    bool operator<(const String& other) const {
        return (std::strcmp(m_data, other.m_data) < 0);
    }

    bool operator>(const String& other) const {
        return (std::strcmp(m_data, other.m_data) > 0);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        for (std::size_t i = 0; i < str.m_size; ++i) {
            os << str.m_data[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& str) {
        const std::size_t buffer_size = 4096;
        char buffer[buffer_size];
        std::size_t i = 0;
        char c;
        while (is.get(c) && !std::isspace(c)) {
            if (i < buffer_size - 1) {
                buffer[i] = c;
                ++i;
            }
        }
        buffer[i] = '\0';
        str = buffer;
        return is;
    }

    size_t length() const {
        return m_size;
    }

    const char* c_str() const {
        return m_data;
    }

    size_t find(char c) const {
        char* result = std::strchr(m_data, c);
        if (result) {
            return result - m_data;
        }
        else {
            return std::string::npos;
        }
    }

    char& at(size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("index out of range");
        }
        return m_data[index];
    }

    const char& at(size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("index out of range");
        }
        return m_data[index];
    }

private:
    char* m_data;
    size_t m_size;
};



#endif //LAB_2_STRING_H
