#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;
    size_t capacity;

public:
    explicit Stack(size_t capacity) : capacity(capacity) {
        try {
            data.reserve(capacity);
        } catch (const std::bad_alloc& e) {
            throw;
        }
    }

    size_t size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

    void push(const T& element) {
        if (data.size() >= capacity) {
            throw std::overflow_error("Stack overflow");
        }
        data.push_back(element);
    }

    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T topElement = data.back();
        data.pop_back();
        return topElement;
    }

    T top() const {
        if (data.empty()) {
            throw std::logic_error("Stack is empty");
        }
        return data.back();
    }
};

#endif  // STACK_H
