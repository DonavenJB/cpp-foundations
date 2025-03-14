#include <iostream>
using namespace std;
int main()
{
    int num_sold_candy;
    double cost_per_bar;
    double total_earned;

    cout << "Please enter the number of candy bars sold :" << endl;
    cin >> num_sold_candy;

    cout << "What is the amount the organization earns for each candy bar sold? : " << endl;
    cin >> cost_per_bar;

    total_earned = cost_per_bar * num_sold_candy;

    cout << "The total amount earned" << " " << total_earned;

    return 0;
}
