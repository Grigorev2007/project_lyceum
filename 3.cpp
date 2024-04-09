#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <random>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int game3() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Welcome to the Brain Games!" << '\n';
    cout << "May I have your name?" << '\n';
    string name;
    cin >> name;
    cout << "Hello, " << name << '!' << '\n';
    int count = 0;
    while (count < 3) {
        if (count > 0) {
            cout << "Lets try again!\n";
        }
        cout << "If given number is prime answer 'yes', otherwise answer 'no'." << '\n';
        cout << "Question: ";
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 300);
        int n = dis(gen);
        cout << n << '\n';
        if (isPrime(n)) {
            string ans;
            cin >> ans;
            if (ans == "yes") {
                cout << "Correct!\n";
                break;
            } else {
                cout << "Incorrect!\n";
                ++count;
            }
        } else {
            string ans;
            cin >> ans;
            if (ans == "no") {
                cout << "Correct!\n";
                break;
            } else {
                cout << "Incorrect!\n";
                ++count;
            }
        }
    }
    cout << "Game over" << '\n';
}