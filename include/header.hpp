// Copyright 2020 Artamonov Mark <a.mark.2001@mail.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <type_traits>
#include <utility>
#include <cstddef>
#include <stdexcept>

using namespace std;

template <typename T>
class The_stack {
public:
    The_stack();
    The_stack(
            The_stack const& a_stack)
                    = delete;
    The_stack& operator=(
            The_stack const& a_stack)
                    = delete;
    The_stack(
            The_stack&& a_stack)
                    noexcept;
    The_stack& operator=(
            The_stack&& a_stack)
                    noexcept;
    ~The_stack();
    size_t get_the_size_of_the_stack();
    bool is_the_stack_empty();
    void push(T&& a_value);
    void push(const T& a_value);
    void pop();
    const T& head() const;
    template <typename... Args>
    void push_emplace(
            Args&&... a_value);
private:
    struct The_node {
        T the_value_of;
        The_node* the_previous_one;
    };
    size_t the_size_of_stack;
    The_node* the_head_of_stack;
};

template <typename T>
The_stack<T>::The_stack(){
    the_head_of_stack = nullptr;
    the_size_of_stack = 0;
}

template <typename T>
The_stack<T>::The_stack(
        The_stack&& a_stack) noexcept {
    the_head_of_stack =
            a_stack.the_head_of_stack;
    a_stack.the_head_of_stack = nullptr;
    the_size_of_stack =
            a_stack.the_size_of_stack;
    a_stack.the_size_of_stack = 0;
}

template <typename T>
The_stack<T>& The_stack<T>::operator=(
        The_stack&& a_stack) noexcept {
    if (&a_stack != this) {
        swap(the_size_of_stack,
                a_stack.the_size_of_stack);
        swap(the_head_of_stack,
                a_stack.the_head_of_stack);
    }
    return *this;
}

template <typename T>
The_stack<T>::~The_stack() {
    auto a_head = the_head_of_stack;
    while (a_head != nullptr) {
        auto a_new_head =
                a_head->
                the_previous_one;
        delete a_head;
        a_head = a_new_head;
    }
}

template <typename T>
size_t The_stack<T>::
        get_the_size_of_the_stack() {
    return the_size_of_stack;
}

template <typename T>
bool The_stack<T>::
        is_the_stack_empty() {
    return the_size_of_stack == 0;
}


template <typename T>
void The_stack<T>::
push(const T& a_value) {
    the_head_of_stack =
            new The_node{
        a_value, the_head_of_stack};
    the_size_of_stack++;
}

template <typename T>
void The_stack<T>::push(T&& a_value) {
    the_head_of_stack =
            new The_node{
        a_value, the_head_of_stack};
    a_value = 0;
    the_size_of_stack++;
}

template <typename T>
void The_stack<T>::pop() {
    auto const a_head =
            the_head_of_stack;
    if (a_head == nullptr) {
        return;
    }
    auto a_new_head = a_head->
            the_previous_one;
    if (a_new_head == nullptr) {
        the_size_of_stack = 0;
        the_head_of_stack =
                nullptr;
    } else {
        the_head_of_stack =
                a_new_head;
        the_size_of_stack--;
    }
    delete a_head;
}

template <typename T>
const T& The_stack<T>::head() const {
    auto const a_head =
            the_head_of_stack;
    if (a_head == nullptr){
        throw out_of_range
        ("Error, stack is empty!");
    }
    return the_head_of_stack
    ->the_value_of;
}

template <typename T>
template <typename... Args_T>
void The_stack<T>::
        push_emplace(
                Args_T&&...
                a_value) {
    the_head_of_stack =
            new The_node{
        T{forward<Args_T>(
                a_value)...},
                the_head_of_stack};
    the_size_of_stack++;
}

#endif // INCLUDE_HEADER_HPP_