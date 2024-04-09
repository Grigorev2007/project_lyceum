#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <random>

using namespace std;

int NOD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int NOK(int a, int b) {
    return a / NOD(a, b) * b;
}

int game1() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Welcome to the Brain Games!" << '\n';
    cout << "May I have your name?" << '\n';
    string name;
    cin >> name;
    cout << "Hello, " << name << '!' << '\n';
    bool check = true;
    int count = 0;
    while (check) {
        cout << "Find the smallest common multiple of given numbers." << '\n';
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 20);
        int n1 = dis(gen);
        int n2 = dis(gen);
        int n3 = dis(gen);
        cout << "Question: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
        cout << "Your answer: ";
        int ans;
        cin >> ans;
        if (ans == NOK(NOK(n1, n2), n3)) {
            cout << "Correct!" << '\n';
            check = false;
        } else {
            cout << "Wrong!" << '\n';
            cout << "The correct answer is: " << NOK(NOK(n1, n2), n3) << '\n';
            ++count;
            if (count != 3) {
                cout << "Let's try again, Sam!" << '\n';
            } else {
                check = false;
            }
        }
    }
    cout << "Game over" << '\n';
}