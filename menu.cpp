#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <random>

#include "1.cpp"
#include "2.cpp"
#include "3.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int choice;
    cout << "Выберите игру:\n";
    cout << "1. Найти НОК чисел\n";
    cout << "2. Найти недостающий элемент геометрической прогрессии\n";
    cout << "3. Простое ли число?\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    switch (choice) {
        case 1:
            game1();
            break;
        case 2:
            game2();
            break;
        case 3:
            game3();
            break;
        default:
            cout << "Неверный выбор!\n";
            break;
    }
    return 0;
}