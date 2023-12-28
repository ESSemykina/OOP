#pragma once
#include <functional>


class DerivativeCalculator {
public:
    DerivativeCalculator(double step) : step_(step) {}

    virtual double Calc(std::function<double(double)> func, double x) = 0;

protected:
    double step_;
};