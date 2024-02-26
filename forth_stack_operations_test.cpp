#include <iostream>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

// Define a class for integer stack operations
class int_stack_t {
private:
    std::vector<int> stack; // Using a vector to implement the stack
public:
    // Pushes a value onto the stack
    void push(int value) {
        stack.push_back(value);
    }

    // Pops a value from the stack
    int pop() {
        if (stack.empty()) {
            throw std::out_of_range("Stack underflow"); // Throws an exception if the stack is empty
        }
        int value = stack.back(); // Retrieves the top element
        stack.pop_back(); // Removes the top element
        return value;
    }

    // Returns the top value of the stack without removing it
    int top() const {
        if (stack.empty()) {
            throw std::out_of_range("Stack is empty"); // Throws an exception if the stack is empty
        }
        return stack.back();
    }

    // Checks if the stack is empty
    bool empty() const {
        return stack.empty();
    }

    // Returns the size of the stack
    size_t size() const {
        return stack.size();
    }

    // Additional FORTH stack operations

    // Duplicates the top element of the stack
    void dup() {
        if (stack.empty()) {
            throw std::out_of_range("Stack underflow"); // Throws an exception if the stack is empty
        }
        push(top()); // Pushes a copy of the top element onto the stack
    }

    // Swaps the top two elements of the stack
    void swap() {
        if (stack.size() < 2) {
            throw std::out_of_range("Insufficient elements for swap"); // Throws an exception if there are not enough elements on the stack
        }
        int a = pop();
        int b = pop();
        push(a); // Pushes the previously popped elements in reverse order
        push(b);
    }

    // Copies the second element from the top and pushes it onto the stack
    void over() {
        if (stack.size() < 2) {
            throw std::out_of_range("Insufficient elements for over"); // Throws an exception if there are not enough elements on the stack
        }
        int a = pop();
        int b = top();
        push(a); // Pushes the previously popped element back onto the stack
        push(b);
    }

    // Rotates the top three elements of the stack
    void rot() {
        if (stack.size() < 3) {
            throw std::out_of_range("Insufficient elements for rotation"); // Throws an exception if there are not enough elements on the stack
        }
        int a = pop();
        int b = pop();
        int c = pop();
        push(b); // Reorders the popped elements and pushes them back onto the stack
        push(a);
        push(c);
    }

    // Drops the top element of the stack
    void drop() {
        if (stack.empty()) {
            throw std::out_of_range("Stack underflow"); // Throws an exception if the stack is empty
        }
        stack.pop_back(); // Removes the top element from the stack
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
