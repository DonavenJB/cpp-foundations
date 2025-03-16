#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string movieTitle;
    int adultTicketCount;
    int childTicketCount;
    const double kAdultTicketPrice = 6.00;
    const double kChildTicketPrice = 3.00;
    double grossRevenue;
    double distributorRate = 0.8;
    double netRevenue;

    cout << "Please enter the name of the movie:" << endl;
    cin >> movieTitle;
    cout << "How many ADULT tickets sold:" << endl;
    cin >> adultTicketCount;
    cout << "How many CHILD tickets sold:" << endl;
    cin >> childTicketCount;

    grossRevenue = (childTicketCount * kChildTicketPrice) + (adultTicketCount * kAdultTicketPrice);
    double distributorPayout = grossRevenue * distributorRate;
    netRevenue = grossRevenue - distributorPayout;

    cout << "Movie Name: " << movieTitle << endl;
    cout << "Adult Tickets Sold: " << setw(3) << adultTicketCount << endl;
    cout << "Child Tickets Sold: " << setw(3) << childTicketCount << endl;

    cout << fixed << showpoint << setprecision(2);
    cout << "Gross Box Office Profit: $" << setw(6) << grossRevenue << endl;
    cout << "Amount Paid to Distributor: $" << setw(6) << distributorPayout << endl;
    cout << "Net Box Office Profit: $" << setw(5) << netRevenue << endl;
    return 0;
}
