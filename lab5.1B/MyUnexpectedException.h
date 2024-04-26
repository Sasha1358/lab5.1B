#pragma once
#include <iostream>
#include <stdexcept>
class MyUnexpectedException : public std::runtime_error {
public:
    MyUnexpectedException(const std::string& message) : std::runtime_error(message) {}
};

