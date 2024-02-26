#include <iostream>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

class int_stack_t {
private:
    std::vector<int> stack;
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

    // Additional FORTH stack operations
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

    // Testing helper functions
    void clear() {
        stack.clear();
    }
};

// GoogleTest cases
TEST(IntStackTest, PushPop) {
    int_stack_t stack;
    stack.push(5);
    EXPECT_EQ(stack.pop(), 5);
    EXPECT_TRUE(stack.empty());
}

TEST(IntStackTest, Dup) {
    int_stack_t stack;
    stack.push(5);
    stack.dup();
    EXPECT_EQ(stack.top(), 5);
}

// Add more test cases for other operations...

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

