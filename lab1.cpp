#include <iostream>
using namespace std; //

double ploshad(double a, double b, double h) { //
    return (a + b) * h / 2;
}

double perimetr(double a, double b, double c, double d) {
    return a + b + c + d;
}

double srednLin(double a, double b) {
    return (a + b) / 2;
}

double vvod(const char* text) {
    double x;
    
    while (true) {
        cout << text;
        
        if (cin >> x) {
            break;
        } else {
            cout << "Ошибка! Введите число: ";
            cin.clear(); 
            cin.ignore(1000, '\n');
        }
    }
    
    return x;
}

int main() {
    double a, b, c, d, h;
    
    cout << "Введите данные для трапеции:\n";
    
    a = vvod("Верхнее основание (a): ");
    b = vvod("Нижнее основание (b): ");
    c = vvod("Левая боковая сторона (c): ");
    d = vvod("Правая боковая сторона (d): ");
    h = vvod("Высота (h): ");
    
    cout << "\nРезультаты:\n";
    cout << "Площадь = " << ploshad(a, b, h) << endl;
    cout << "Периметр = " << perimetr(a, b, c, d) << endl;
    cout << "Средняя линия = " << srednLin(a, b) << endl;
    
    return 0;
}
