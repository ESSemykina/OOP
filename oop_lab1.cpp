//Задание 1.
//Написать родительский класс и унаследовать от него классы от него.
//Наследники должны считать правую, левую и центральную производную.

#include <iostream>
#include <functional>
#include <memory>
#include <utility>

// базовый класс для классов расчета производных
class Calcer {
private:
public:
    double _x, _x0; 
    std::function<double(double)> _f; 

    Calcer(double x, double x0, std::function<double(double)> f) {
        _x = x; _x0 = x0; _f = std::move(f);
    };

    virtual double calcDiff() {
        return 0;
    };
};

// класс для расчета левой производной
class CalcerLeft : public Calcer {
public:

    CalcerLeft(double x, double x0, std::function<double(double)> f) : Calcer(x, x0, f) {};


    double calcDiff() override {
        return ((_f(_x) - _f(_x - _x0)) / _x0);
    };
};

// класс для расчета правой производной
class CalcerRight : public Calcer {
public:

    CalcerRight(double x, double x0, std::function<double(double)> f) : Calcer(x, x0, f) {};

    double calcDiff() override {
        return (_f(_x + _x0) - _f(_x)) / _x0;
    };
};

// класс для расчета центральной производной
class MiddleCalcer : public Calcer {
public:

    MiddleCalcer(double x, double x0, std::function<double(double)> f) : Calcer(x, x0, f) {};


    double calcDiff() override {
        return (_f(_x + _x0) - _f(_x - _x0)) / (2 * _x0);
    };
};
int main() {

    setlocale(LC_ALL, "Russian");

    std::function<double(double)> f = [](double x) {
        return x * x;
    };

    double x = 2;      
    double  x0 = 0.2;  


    std::unique_ptr<Calcer> calcr = std::make_unique<CalcerLeft>(CalcerLeft(x, x0, f));
    std::unique_ptr<Calcer> calcr2 = std::make_unique<CalcerRight>(CalcerRight(x, x0, f));
    std::unique_ptr<Calcer> calcr3 = std::make_unique<MiddleCalcer>(MiddleCalcer(x, x0, f));

    std::cout << "Левая производная = " << calcr->calcDiff() << std::endl;
    std::cout << "Правая производная = " << calcr2->calcDiff() << std::endl;
    std::cout << "Центральная производная = " << calcr3->calcDiff() << std::endl;

    return 0;
}