#define _CRT_SECURE_NO_WARNINGS
#include "../Fuel.h"
#include "../Car.h"
#include "../Driver.h"
#include "../Passenger.h"
#include "Order.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "TESTS:" << endl << endl;
    
    cout << "## Overloaded Passenger::setInfo(...) method (with calling Person::setInfo(...) method)" << endl;
    Passenger passenger1{};
    passenger1.setInfo("Ivan", 5000, false);
    passenger1 << cout;

    cout << "## Overloaded Driver::setInfo(...) method (without calling Person::setInfo(...) method)" << endl;
    Driver driver1{};
    driver1.setInfo("Leonid", 8700, 14, 390);
    driver1 << cout;

    cout << "## Calling base (Person) class's constructor" << endl;
    Passenger passenger2{ "Georgiy", 5000, true };
    passenger2 << cout;

    cout << "## Overloaded operator= for Derived classes" << endl;
    Person person1{ "Kirill", 7000 };
    Passenger passenger3{};
    passenger3 = person1;
    passenger3 << cout;
    
    cout << "## Virtual and non-virtual functions" << endl << endl;

    cout << "# Calling virtual function for dynamic object" << endl;
    Person* person_ptr{ &person1 };
    Driver driver2{ "Andrey" };
    person_ptr = &driver2;
    person_ptr->input();

    cout << "# Calling non-virtual function for dynamic object" << endl;
    Passenger passenger4{"Nikolay", 7000, true};
    person_ptr = &passenger4;
    person_ptr->output();

    cout << endl << "# Calling virtual function from non-virtual" << endl;
    person_ptr = &driver2;
    person_ptr->test_virtual();

    cout << "# Calling non-virtual function from non-virtual" << endl;
    person_ptr = &passenger4;
    person_ptr->test_non_virtual();

    cout << endl << "## Abstract class Engine -> class Car" << endl;
    Car<string> car1{ "12345fh", "Volvo", true };
    cout << "Pure virtual method getBrand: " << car1.getBrand() << endl;

    cout << endl << "## Class template (Car)" << endl;
    Car<int> car2{ 12345, "Volvo", true };
    car2 << cout;

    return 0;
}