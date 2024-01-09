#define _CRT_SECURE_NO_WARNINGS
#include "../Fuel.h"
#include "../Car.h"
#include "../Driver.h"
#include "../Passenger.h"
#include "Order.h"
#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

void vector_output(vector <Person*> v) {
    int n = v.size(); string buffer;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout.setf(ios::fixed);
    cout << "| " << left << setw(15) << "Type" << setw(15) << "Name" << setw(14) << "Balance" << setw(15) << "Experience" << setw(20) << "Order Amount" << setw(15) << "Method" << " |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    int i;
    for (i = 0; i < n; i++) {
        if (v[i]->getType() == "Person") {
            cout << "| " << left << setw(15) << "Person" << setw(15) << v[i]->getName() << setw(14) << v[i]->getBalance() << setw(15) << "-" << setw(20) << "-" << setw(16) << "-" << "|" << endl;
        }
        if (v[i]->getType() == "Driver") {
            Driver* driver = (Driver*)v[i];
            cout << "| " << left << setw(15) << "Driver" << setw(15) << driver->getName() << setw(14) << driver->getBalance() << setw(15) << getExperience(*driver) << setw(20) << getOrderAmount(*driver) << setw(16) << "-" << "|" << endl;
        }
        if (v[i]->getType() == "Passenger") {
            Passenger* passenger = (Passenger*)v[i];
            if (passenger->getMethod()) buffer = "Credit card";
            else buffer = "Cash";
            cout << "| " << left << setw(15) << "Passenger" << setw(15) << passenger->getName() << setw(14) << passenger->getBalance() << setw(15) << "-" << setw(20) << "-" << setw(16) << buffer << "|" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
}

bool compare(Person* first, Person* second) {
    bool flag = 0;
    if (first->getType() != second->getType()) 
        flag = first->getType() < second->getType();
    else 
    {
        if (first->getName() != second->getName())
            flag = first->getName() < second->getName();
        else 
        {
            if (first->getBalance() != second->getBalance())
                flag = first->getBalance() < second->getBalance();
            else 
            {
                if (first->getType() == "Driver") // Driver - Driver
                {
                    Driver* driver_first = (Driver*)first;
                    Driver* driver_second = (Driver*)second;
                    if (getExperience(*driver_first) != getExperience(*driver_second))
                        flag = getExperience(*driver_first) < getExperience(*driver_second);
                    else
                    {
                        flag = getOrderAmount(*driver_first) < getOrderAmount(*driver_second);
                    }
                }
                else 
                {
                    if (first->getType() == "Passenger") // Passenger - Passenger
                    {
                        Passenger* pass_first = (Passenger*)first;
                        Passenger* pass_second = (Passenger*)second;
                        flag = pass_first->getMethod() < pass_second->getMethod();
                    } 
                }
                    
            }
        }
    }
        
    return flag;
}

int main() {
    cout << "TESTS:" << endl;
    
    vector <Person*> v;
    v.push_back(new Passenger("Anna", 6000, true));
    v.push_back(new Driver("Ivan", 7000, 10, 600));
    v.push_back(new Passenger("Yuriy", 8000, true));
    v.push_back(new Driver("Ivan", 7000, 10, 560));
    v.push_back(new Passenger("Yuriy", 5000, true));
    v.push_back(new Person("Andrey", 5000));
    v.push_back(new Driver("Sergey", 6000, 7, 350));
    v.push_back(new Person("Elena", 5500));
    v.push_back(new Passenger("Anna", 6000, false));
    v.push_back(new Person("Andrey", 3000));
    v.push_back(new Driver("Dmitriy", 1000, 5, 120));
    v.push_back(new Driver("Sergey", 4000, 7, 340));

    vector_output(v);

    Driver* driver_ptr;
    Passenger* pass_ptr;

    sort(v.begin(), v.end(), compare);
    
    cout << endl << "Sorting in the ascending order:" << endl;

    vector_output(v);

    /*driver_ptr = (Driver*)v[0];
    *driver_ptr << cout;

    pass_ptr = (Passenger*)v[3];
    *pass_ptr << cout;

    *v[2] << cout;*/

    return 0;
}