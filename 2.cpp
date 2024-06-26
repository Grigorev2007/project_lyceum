#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <random>

using namespace std;

int game2() {
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
        cout << "What number is missing in the progression?" << '\n';
        cout << "Question: ";
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 10);
        int n = dis(gen);
        vector<int> a(n);
        int a1 = dis(gen);
        int k = dis(gen);
        uniform_int_distribution<> dim(0, n - 1);
        int point = dim(gen);
        a[0] = a1;
        for (int i = 1; i < a.size(); ++i) {
            a[i] = a[i - 1] * k;
        }
        int aim = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (i == point) {
                cout << " .. ";
                if (i < a.size() - 1) {
                    aim = a[i + 1] / k;
                } else {
                    aim = a[i - 1] / k;
                }
            } else {
                cout << a[i] << ' ';
            }
        }
        int ans;
        cin >> ans;
        if (ans == aim) {
            cout << "OK" << '\n';
            check = false;
        } else {
            cout << "not OK" << '\n';
            ++count;
            if (count == 3) {
                check = false;
            }
        }
    }
    cout << "Game over" << '\n';
}