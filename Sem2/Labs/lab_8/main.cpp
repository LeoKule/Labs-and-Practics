#include <iostream>
#include "stack.h"

int main() {
    try {
        Stack<int> stack(5);

        std::cout << "Stack size: " << stack.size() << std::endl;
        std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Stack size: " << stack.size() << std::endl;
        std::cout << "Top element: " << stack.top() << std::endl;

        stack.pop();

        std::cout << "Stack size: " << stack.size() << std::endl;
        std::cout << "Top element: " << stack.top() << std::endl;

        stack.pop();
        stack.pop();
        stack.pop(); // Trying to pop from an empty stack

        std::cout << "Stack size: " << stack.size() << std::endl;
        std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "Failed to allocate memory for the stack: " << e.what() << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "Stack overflow: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Stack is empty: " << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Stack is empty: " << e.what() << std::endl;
    }

    return 0;
}
