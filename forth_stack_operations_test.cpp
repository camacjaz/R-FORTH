#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <gtest/gtest.h>

class int_stack_t {
private:
    std::vector<int> stack;
    std::unordered_map<std::string, int> variables;
    std::unordered_map<std::string, int> constants;

public:
    void push(int value) {
        stack.push_back(value);
    }

    int pop() {
        if (stack.empty()) {
            throw std::out_of_range("Stack underflow");
        }
        int value = stack.back();
        stack.pop_back();
        return value;
    }

    int top() const {
        if (stack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return stack.back();
    }

    bool empty() const {
        return stack.empty();
    }

    size_t size() const {
        return stack.size();
    }

    // Define a variable with a given name and value
    void define_variable(const std::string& name, int value) {
        variables[name] = value;
    }

    // Define a constant with a given name and value
    void define_constant(const std::string& name, int value) {
        constants[name] = value;
    }

    // Retrieve the value of a variable or constant by name
    int get_value(const std::string& name) const {
        if (variables.find(name) != variables.end()) {
            return variables.at(name);
        } else if (constants.find(name) != constants.end()) {
            return constants.at(name);
        } else {
            throw std::out_of_range("Variable or constant not found");
        }
    }

    // Stack manipulation operations

    void dup() {
        if (stack.empty()) {
            throw std::out_of_range("Stack underflow");
        }
        push(top());
    }

    void swap() {
        if (stack.size() < 2) {
            throw std::out_of_range("Insufficient elements for swap");
        }
        int a = pop();
        int b = pop();
        push(a);
        push(b);
    }

    void over() {
        if (stack.size() < 2) {
            throw std::out_of_range("Insufficient elements for over");
        }
        int a = pop();
        int b = top();
        push(a);
        push(b);
    }

    void rot() {
        if (stack.size() < 3) {
            throw std::out_of_range("Insufficient elements for rotation");
        }
        int a = pop();
        int b = pop();
        int c = pop();
        push(b);
        push(a);
        push(c);
    }

    void drop() {
        if (stack.empty()) {
            throw std::out_of_range("Stack underflow");
        }
        stack.pop_back();
    }

    // Testing helper function to clear the stack
    void clear() {
        stack.clear();
    }
};

// GoogleTest cases for testing the int_stack_t class
TEST(IntStackTest, PushPop) {
    int_stack_t stack;
    stack.push(5);
    EXPECT_EQ(stack.pop(), 5); // Tests pushing and popping an element
    EXPECT_TRUE(stack.empty()); // Tests if the stack is empty after popping
}

TEST(IntStackTest, Dup) {
    int_stack_t stack;
    stack.push(5);
    stack.dup();
    EXPECT_EQ(stack.top(), 5); // Tests duplicating the top element
}

// Add more test cases for other operations...

// Main function to run all the GoogleTest cases
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

