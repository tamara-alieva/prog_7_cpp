#define _CRT_SECURE_NO_WARNINGS
#include "../Fuel.h"
#include "../Car.h"
#include "../Driver.h"
#include "../Passenger.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "TESTS:" << endl << endl;
    
    vector <Person*> v;
    v.push_back(new Driver("Ivan", 7000, 10, 560));
    v.push_back(new Passenger("Yuriy", 5000, true));
    v.push_back(new Person("Elena", 5500));
    v.push_back(new Passenger("Anna", 6000, false));
    v.push_back(new Person("Andrey", 3000));
    v.push_back(new Driver("Dmitriy", 1000, 5, 120));
    v.push_back(new Driver("Sergey", 4000, 7, 340));

    return 0;
}