#include <functional>
#include "derivative.hpp"

class LeftDerivativeCalculator : public DerivativeCalculator {
public:
    LeftDerivativeCalculator(double step) : DerivativeCalculator(step) {}

    double Calc(std::function<double(double)> func, double x) {

        return (func(x) - func(x - step_)) / step_;
    }
};

class MidpointDerivativeCalculator : public DerivativeCalculator {
public:
    MidpointDerivativeCalculator(double step) : DerivativeCalculator(step) {}

    double Calc(std::function<double(double)> func, double x) {

        return (func(x + step_) - func(x - step_)) / (2 * step_);
    }
};

class RightDerivativeCalculator : public DerivativeCalculator {
public:
    RightDerivativeCalculator(double step) : DerivativeCalculator(step) {}

    double Calc(std::function<double(double)> func, double x) {

        return (func(x + step_) - func(x)) / step_;
    }
};