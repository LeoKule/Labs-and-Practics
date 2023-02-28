#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    long long А;
    long long В;
    long long С;
    cout << "Ввидите число\n";
    cin >> А;
    cout << "Ввидите число\n";
    cin >> В;
    cout << "Ввидите число\n";
    cin >> С;
    if (А < В and В > С) {
        long long proiz = С - В - А;
        cout << "Вот что получилось\n";
        cout << proiz;
    }
    else if (А % С == 0) {
        long long j = А / (С + В);
        cout << "Вот что получилось\n";
        cout << j;
    }
    else {
        long long sum = А + В + С;
        cout << "Вот что получилось\n";
        cout << sum;
    }
}
