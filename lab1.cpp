#include <iostream>   
#include <vector>     

class Derivative   
{
public:
    Derivative(double x, double h)    
    {
        _x = x;
        _h = h;
    }

    ~Derivative()   
    {
    }

    double func(double a)    
    {
        return a * a; 
    }

    virtual void calculate() = 0;   

    double value() const  
    {
        return _derivative;
    }
  

protected:
    double _derivative = 0;  
    double _x;   
    double _h;   

};

class Left : public Derivative    
{
public:
    Left(double x, double h) : Derivative(x, h)   
    {}
    ~Left()   
    {}
    void calculate() override  
    {
        _derivative = (func(_x) - func(_x - _h)) / _h;
    }
};

class Right : public Derivative  
{
public:
    Right(double x, double h) : Derivative(x, h) 
    {
       
    }
    ~Right()   
    {
       
    }
    void calculate() override 
    {
        _derivative = (func(_x + _h) - func(_x)) / _h;
    }
};

class Center : public Derivative  
{
public:
    Center(double x, double h) : Derivative(x, h)
    {
       
    }
    ~Center()  
    {
    }
    void calculate() override 
    {
        _derivative = (func(_x + _h) - func(_x - _h)) / (2 * _h);
    }
};

void main() 
{
   
    std::vector<Derivative*> derivatives;  

    derivatives.push_back(new Left(1, 0.1));  
    derivatives.push_back(new Right(1, 0.1));
    derivatives.push_back(new Center(1, 0.1)); 

    for (const auto& derivative : derivatives) 
    {
        derivative->calculate(); 
        std::cout << derivative->value() << std::endl;
    }

    for (auto& derivative : derivatives)  
        delete derivative; 
    derivatives.clear(); 
}
