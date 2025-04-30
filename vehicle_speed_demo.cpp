#include <iostream>
#include <string>

class Car
{
private:
    int modelYear;
    std::string make;
    int speed;

public:
    Car(int year, const std::string &makeVal) : modelYear(year), make(makeVal), speed(0) {}

    int getModelYear() const { return modelYear; }
    std::string getMake() const { return make; }
    int getSpeed() const { return speed; }

    void accelerate() { speed += 5; }

    void accelerate(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            accelerate();
            displaySpeed();
        }
    }

    void brake() { speed = speed >= 5 ? speed - 5 : 0; }

    void brake(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            brake();
            displaySpeed();
        }
    }

    void displaySpeed() const
    {
        std::cout << getModelYear() << " " << getMake()
                  << " - current speed : " << getSpeed() << std::endl;
    }
};

int main()
{
    Car myCar(1967, "Ford Mustang");
    myCar.accelerate(5);
    std::cout << std::endl;
    myCar.brake(5);
    return 0;
}
