#pragma once
#include <iostream>
#include <stdexcept>

class MyException : public std::invalid_argument {
public:
    MyException(const std::string& message) : std::invalid_argument(message) {}
};