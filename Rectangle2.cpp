#include <iostream>
#include <cmath>
using namespace std;

double perimetr(double le, double wi) { //ф-я нахождения Периметра прямоугольника
    return (le + wi) * 2;
}

double square(double le, double wi) { //ф-я нахождения Площади прямоугольника
    return le * wi;
}

double diagonal(double le, double wi) { //ф-я нахождения Диагонали прямоугольника
    return sqrt((le * le) + (wi * wi));
}

int main() {
    double lenght, width;
    
    cout << "Введите значение длины: ";
    cin >> lenght;
    if (cin.fail()) {  // проверяем, число ли ввели
        cout << "Ошибка, нужно вводить числа" << endl;
        return 1;
    }
    
    cout << "Введите значение ширины: ";
    cin >> width;
    if (cin.fail()) { // проверяем, число ли ввели
        cout << "Ошибка, нужно вводить числа" << endl;
        return 1;
    }
    
    if (lenght > 0 && width > 0) {
        cout << "Периметр прямоугольника = " << perimetr(lenght, width) << endl;
        cout << "Площадь прямоугольника = " << square(lenght, width) << endl;
        cout << "Диагональ прямоугольника = " << diagonal(lenght, width) << endl;
    } else {
        cout << "Введены неверные данные" << endl;
    }
    
    return 1;
}