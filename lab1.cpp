#include <iostream>
#include <cmath>
using namespace std; 

double ploshad(double a, double b, double h) { 
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
            cin.ignore(100, '\n');
        }
    }
    
    return x;
}
bool proverka(double a, double b, double c, double d, double h) {
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || h <= 0) {
        cout << "Ошибка! Все стороны и высота должны быть положительными!\n";
        return false;
    }
    if (a >= b) {
        cout << "Ошибка! Верхнее основание должно быть меньше нижнего!\n";
        return false;
    }
    if (h >= c || h >= d) {
        cout << "Ошибка! Высота должна быть меньше боковых сторон!\n";
        return false;
    }
    double proekciya_c = sqrt(c*c - h*h);
    double proekciya_d = sqrt(d*d - h*h);
    double raznost = b - a;
    
    if (abs(proekciya_c + proekciya_d - raznost) > 0.1) {
        cout << "Ошибка! Трапеция с такими параметрами не существует!\n";
        return false;
    }
    return true;
}

int main() {
    double a, b, c, d, h;
    bool cor = false;
    
    cout << "Введите данные для трапеции:\n";
    cout << "================================\n\n";
    
    while (!cor) {
        a = vvod("Верхнее основание (a): ");
        b = vvod("Нижнее основание (b): ");
        c = vvod("Левая боковая сторона (c): ");
        d = vvod("Правая боковая сторона4 (d): ");
        h = vvod("Высота (h): ");
        
        cor = proverka(a, b, c, d, h);
        
        if (!cor) {
            cout << "\nПопробуйте ввести данные заново:\n";
            cout << "--------------------------------\n";
        }
    }
    
    cout << "\n================================\n";
    cout << "Результаты:\n";
    cout << "Площадь = " << ploshad(a, b, h) << endl;
    cout << "Периметр = " << perimetr(a, b, c, d) << endl;
    cout << "Средняя линия = " << srednLin(a, b) << endl;
    
    return 0;
}
