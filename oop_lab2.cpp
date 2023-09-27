//Задание 2.
//Создать класс натуральная дробь.
//Добавить методы для сложения, вычитания, деления, умножения,выделение целой части,перевод в десятичную дробь.

#include <iostream> 
#include <string> 
using namespace std; 

class Fraction
{
public:

    Fraction() {
        numer = 0; 
        denom = 0; 
        whole = 0; 
    }

    Fraction(int n, int d) {
        numer = n; 
        denom = d; 
        whole = 0; 
    }

    int getNumer() const { return numer; } 
    int getDenom() const { return denom; } 


    void set(int n, int d) {
        numer = n; 
        denom = d; 
    }

    //метод вывода дроби в консоль
    void print() {
        if (whole != 0) 
            cout << whole << "+"; 
        cout << numer << '/' << denom << endl; 
    }

    //метод ввода дроби с консоли
    void read() {
        string str; 
        getline(cin, str); 
        int sep = str.find('/');
        this->set(stoi(str.substr(0, sep)), stoi(str.substr(sep + 1))); 
    }

    //метод сокращения дроби
    void simplify() {
        for (int i = 1; i <= min(abs(numer), abs(denom)); ++i) { 
            if (numer % i == 0 && denom % i == 0) {
                numer /= i; 
                denom /= i; 
            }
        }
    }

    //метод перевода дроби в десятичную форму
    float toDecimal() {
        cout << "Перевод в десятичную дробь" << endl;
        float tmp = float(numer) / float(denom); 
        return tmp; 
    }

    //метод выделения целой части дроби
    Fraction wholePart() {
        cout << "Выделение целой части" << endl;
        Fraction tmp; 
        if (numer < denom) 
            tmp = *this; 
        else {
            tmp.whole = numer / denom;
            tmp.numer = numer - denom * tmp.whole; 
            tmp.denom = denom; 
        }
        return tmp; 
    }


    //оператор присваивания
    void operator=(const Fraction& r) {
        numer = r.getNumer(); 
        denom = r.getDenom(); 
    }

    //оператор сложения
    Fraction operator+(const Fraction& r) {
        Fraction tmp; 
        tmp.numer = numer * r.getDenom() + denom * r.getNumer(); 
        tmp.denom = denom * r.getDenom(); 
        tmp.simplify(); 
        return tmp; 
    }

    // метод сложения дробей
    Fraction add(const Fraction& r) {
        cout << "сложение" << endl;
        Fraction tmp = *this + r; 
        return tmp; 
    }

    //оператор вычитания
    Fraction operator-(const Fraction& r) {
        Fraction tmp; 
        tmp.numer = numer * r.getDenom() - denom * r.getNumer(); 
        tmp.denom = denom * r.getDenom(); 
        tmp.simplify(); 
        return tmp; 
    }

    //метод вычитания дробей
    Fraction subtract(const Fraction& r) {
        cout << "вычитание" << endl;
        Fraction tmp = *this - r; 
        return tmp; 
    }

    //оператор умножения
    Fraction operator*(const Fraction& r) {
        Fraction tmp; 
        tmp.numer = numer * r.getNumer(); 
        tmp.denom = denom * r.getDenom(); 
        tmp.simplify(); 
        return tmp; 
    }

    //метод умножения дробей
    Fraction multiply(const Fraction& r) {
        cout << "умножение" << endl;
        Fraction tmp = *this * r; 
        return tmp; 
    }

    //оператор деления
    Fraction operator/(const Fraction& r) {
        Fraction tmp; 
        tmp.numer = numer * r.getDenom(); 
        tmp.denom = denom * r.getNumer(); 
        tmp.simplify(); 
        return tmp; 
    }

    //метод деления дробей
    Fraction divide(const Fraction& r) {
        cout << "деление" << endl;
        Fraction tmp = *this / r; 
        return tmp; 
    }

private:
    int whole; 
    int numer; 
    int denom; 
};


int main()
{
    setlocale(LC_ALL, "Russian"); 
    Fraction x, y; 
    cout << "Введите первую дробь: ";
    x.read();
    cout << "Введите вторую дробь: ";
    y.read(); 
    cout << endl;
    Fraction z = x.add(y); 
    z.print(); 
    z.wholePart().print(); 
    cout << z.toDecimal() << endl;; 
    x.subtract(y).print(); 
    x.multiply(y).print(); 
    x.divide(y).print(); 
    return 0; 
}



