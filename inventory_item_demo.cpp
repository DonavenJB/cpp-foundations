#include <iostream>
#include <iomanip>
#include <string>

class ItemRecord
{
private:
    int itemNumber_;
    int quantity_;
    double unitPrice_;

public:
    ItemRecord() : itemNumber_(0), quantity_(0), unitPrice_(0.0) {}
    ItemRecord(int itemNumber, int quantity, double unitPrice)
        : itemNumber_(itemNumber), quantity_(quantity), unitPrice_(unitPrice) {}
    int itemNumber() const { return itemNumber_; }
    int quantity() const { return quantity_; }
    double unitPrice() const { return unitPrice_; }
    void setItemNumber(int itemNumber) { itemNumber_ = itemNumber; }
    void setQuantity(int quantity) { quantity_ = quantity; }
    void setUnitPrice(double unitPrice) { unitPrice_ = unitPrice; }
    double totalCost() const { return quantity_ * unitPrice_; }
};

int main()
{
    ItemRecord part1;

    int defaultItemNumber = 1234;
    int defaultQuantity = 10;
    double defaultUnitPrice = 2.5;
    ItemRecord part2(defaultItemNumber, defaultQuantity, defaultUnitPrice);

    std::cout << "Enter data for the new item number: " << std::endl;
    int newItemNumber, newQuantity;
    double newUnitPrice;
    std::cin >> newItemNumber;

    do
    {
        std::cout << "Quantity: " << std::endl;
        std::cin >> newQuantity;
        if (newQuantity < 0)
        {
            std::cout << "Value must be greater than zero: " << std::endl;
            std::cin >> newQuantity;
        }
    } while (newQuantity < 0);

    do
    {
        std::cout << "Price: " << std::endl;
        std::cin >> newUnitPrice;
        if (newUnitPrice < 0)
        {
            std::cout << "Value must be greater than zero: " << std::endl;
            std::cin >> newUnitPrice;
        }
    } while (newUnitPrice < 0);

    ItemRecord part3(newItemNumber, newQuantity, newUnitPrice);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nPart Number : " << part1.itemNumber() << std::endl;
    std::cout << "Units On Hand : " << part1.quantity() << std::endl;
    std::cout << "Price : $" << part1.unitPrice() << std::endl;
    std::cout << "Total Cost : $" << part1.totalCost() << std::endl;

    std::cout << "\nPart Number : " << part2.itemNumber() << std::endl;
    std::cout << "Units On Hand : " << part2.quantity() << std::endl;
    std::cout << "Price : $" << part2.unitPrice() << std::endl;
    std::cout << "Total Cost : $" << part2.totalCost() << std::endl;

    std::cout << "\nPart Number : " << part3.itemNumber() << std::endl;
    std::cout << "Units On Hand : " << part3.quantity() << std::endl;
    std::cout << "Price : $" << part3.unitPrice() << std::endl;
    std::cout << "Total Cost : $" << part3.totalCost() << std::endl;

    return 0;
}
