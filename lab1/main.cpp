#include <iostream>
#include "derivative.hpp"
#include "derivative.cpp"


int main() {

    std::function<double(double)> func = [](double x) { return x * x; };
    double x = 3.0;

    RightDerivativeCalculator rightDerivative(0.1);
    double derivative = rightDerivative.Calc(func, x);
    std::cout << derivative << std::endl;

    LeftDerivativeCalculator leftDerivative(0.1);
    derivative = leftDerivative.Calc(func, x);
    std::cout << derivative << std::endl;

    MidpointDerivativeCalculator midpointDerivative(0.1);
    derivative = midpointDerivative.Calc(func, x);
    std::cout << derivative << std::endl;

    return 0;
}