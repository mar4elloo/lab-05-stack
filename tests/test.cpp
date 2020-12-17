// Copyright 2020 Artamonov Mark <a.mark.2001@mail.ru>

#include <gtest/gtest.h>
#include "header.hpp"
#include <string>

TEST(The_stack, check_push) {
    The_stack<int> a_stack;
    const int a_value = 10;
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            0);
    a_stack.push(a_value);
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            1);
    a_stack.push(-10);
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            2);
    a_stack.push(0);
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            3);
    a_stack.push(10);
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            4);
}

TEST(The_stack, check_pop) {
    The_stack<int> a_stack;
    a_stack.push(1);
    a_stack.push(2);
    a_stack.push(3);
    a_stack.push(4);
    a_stack.push(5);
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            5);
    a_stack.pop();
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            4);
    a_stack.pop();
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            3);
    a_stack.pop();
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            2);
    a_stack.pop();
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            1);
    a_stack.pop();
    EXPECT_EQ(a_stack.
            get_the_size_of_the_stack(),
            0);
}

TEST(The_stack, check_head) {
    The_stack<int> a_stack;
    a_stack.push(0);
    EXPECT_EQ(a_stack.head(),
              0);
    a_stack.push(1);
    EXPECT_EQ(a_stack.head(),
              1);
    a_stack.push(2);
    EXPECT_EQ(a_stack.head(),
              2);
    a_stack.pop();
    EXPECT_EQ(a_stack.head(),
              1);
}

TEST(The_stack, check_push_emplace) {
    The_stack<std::string> a_stack;
    a_stack.push_emplace("0");
    EXPECT_EQ(a_stack.head(),
              "0");
    a_stack.push_emplace("1");
    EXPECT_EQ(a_stack.head(),
              "1");
    a_stack.push_emplace("2");
    EXPECT_EQ(a_stack.head(),
              "2");
    a_stack.push_emplace("3");
    EXPECT_EQ(a_stack.head(),
              "3");
}

TEST(The_stack, is_the_stack_empty) {
    The_stack<int> a_stack;
    EXPECT_EQ(a_stack.
    is_the_stack_empty(),
              true);
    a_stack.push(0);
    EXPECT_EQ(a_stack.
    is_the_stack_empty(),
              false);
}

TEST(The_stack,
        get_the_size_of_the_stack) {
    The_stack<int> a_stack;
    EXPECT_EQ(a_stack.
    get_the_size_of_the_stack(),
    0);
    a_stack.push(1);
    EXPECT_EQ(a_stack.
    get_the_size_of_the_stack(),
    1);
    a_stack.push(1);
    EXPECT_EQ(a_stack.
    get_the_size_of_the_stack(),
    2);
    a_stack.pop();
    EXPECT_EQ(a_stack.
    get_the_size_of_the_stack(),
    1);
    a_stack.pop();
    EXPECT_EQ(a_stack.
    get_the_size_of_the_stack(),
    0);
}
