#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    const double kYenPerDollar = 105.64;
    const double kEuroPerDollar = 0.80;

    double amountUsd;
    double amountYen;
    double amountEuro;

    cout << "Currency Conversion Machine" << endl;

    cout << "Enter amount in US Dollars: $";
    cin >> amountUsd;

    amountYen = amountUsd * kYenPerDollar;
    amountEuro = amountUsd * kEuroPerDollar;

    cout << fixed << setprecision(1);
    cout << "Your amount in YEN: " << amountYen << '\n';
    cout << setprecision(0);
    cout << "Your amount in EURO: " << amountEuro << '\n';

    return 0;
}
