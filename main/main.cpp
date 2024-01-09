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
    cout << "--------------------------------------------------------------------------------------------------" << endl << endl;
}

bool ascending_compare(Person* first, Person* second) {
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

bool descending_compare(Person* first, Person* second) {
    bool flag = 0;
    if (first->getType() != second->getType())
        flag = first->getType() > second->getType();
    else
    {
        if (first->getName() != second->getName())
            flag = first->getName() > second->getName();
        else
        {
            if (first->getBalance() != second->getBalance())
                flag = first->getBalance() > second->getBalance();
            else
            {
                if (first->getType() == "Driver") // Driver - Driver
                {
                    Driver* driver_first = (Driver*)first;
                    Driver* driver_second = (Driver*)second;
                    if (getExperience(*driver_first) != getExperience(*driver_second))
                        flag = getExperience(*driver_first) > getExperience(*driver_second);
                    else
                    {
                        flag = getOrderAmount(*driver_first) > getOrderAmount(*driver_second);
                    }
                }
                else
                {
                    if (first->getType() == "Passenger") // Passenger - Passenger
                    {
                        Passenger* pass_first = (Passenger*)first;
                        Passenger* pass_second = (Passenger*)second;
                        flag = pass_first->getMethod() > pass_second->getMethod();
                    }
                }

            }
        }
    }

    return flag;
}

void search(vector <Person*> v, Person* element) {
    int n = v.size(); int i, count = 0;
    string element_type = element->getType();
    string vector_type, buffer = ""; bool flag = 1;
    cout << "Search result: ";
    for (i = 0; i < n; i++) 
    {
        flag = 1;
        vector_type = v[i]->getType();
        if (element_type == vector_type) 
        {
            if (element->getName() != "")
            {
                flag = element->getName() == v[i]->getName() && element->getBalance() == v[i]->getBalance();
            }
            else {
                flag = element->getBalance() == v[i]->getBalance();
            }
            if (element_type == "Driver")
            {
                Driver* vector_driver = (Driver*)v[i];
                Driver* element_driver = (Driver*)element;
                flag = flag * (getExperience(*vector_driver) == getExperience(*element_driver) && getOrderAmount(*vector_driver) == getOrderAmount(*element_driver));
            }
            if (element_type == "Passenger")
            {
                Passenger* vector_passenger = (Passenger*)v[i];
                Passenger* element_passenger = (Passenger*)element;
                flag = flag * (vector_passenger->getMethod() == element_passenger->getMethod());
            }
            if (flag)
            {
                count++;
                if (count == 1)
                {
                    cout << endl << "--------------------------------------------------------------------------------------------------" << endl;
                    cout.setf(ios::fixed);
                    cout << "| " << left << setw(15) << "Type" << setw(15) << "Name" << setw(14) << "Balance" << setw(15) << "Experience" << setw(20) << "Order Amount" << setw(15) << "Method" << " |" << endl;
                    cout << "--------------------------------------------------------------------------------------------------" << endl;
                }
                if (v[i]->getType() == "Person")
                {
                    cout << "| " << left << setw(15) << "Person" << setw(15) << v[i]->getName() << setw(14) << v[i]->getBalance() << setw(15) << "-" << setw(20) << "-" << setw(16) << "-" << "|" << endl;
                }
                if (v[i]->getType() == "Driver")
                {
                    Driver* driver = (Driver*)v[i];
                    cout << "| " << left << setw(15) << "Driver" << setw(15) << driver->getName() << setw(14) << driver->getBalance() << setw(15) << getExperience(*driver) << setw(20) << getOrderAmount(*driver) << setw(16) << "-" << "|" << endl;
                }
                if (v[i]->getType() == "Passenger")
                {
                    Passenger* passenger = (Passenger*)v[i];
                    if (passenger->getMethod()) buffer = "Credit card";
                    else buffer = "Cash";
                    cout << "| " << left << setw(15) << "Passenger" << setw(15) << passenger->getName() << setw(14) << passenger->getBalance() << setw(15) << "-" << setw(20) << "-" << setw(16) << buffer << "|" << endl;
                }
            }
        }
    }
    if (count)
    {
        cout << "--------------------------------------------------------------------------------------------------" << endl << endl;
    }
    else cout << "not found" << endl << endl;
}

int main() {
    cout << "TESTS:" << endl;
    
    vector <Person*> v;
    v.push_back(new Passenger("Anna", 6000, true));
    v.push_back(new Passenger("Irina", 6000, false));
    v.push_back(new Driver("Ivan", 7000, 10, 600));
    v.push_back(new Driver("Sergey", 6000, 7, 350));
    v.push_back(new Passenger("Yuriy", 8000, true));
    v.push_back(new Driver("Ivan", 7000, 10, 560));
    v.push_back(new Passenger("Kirill", 6000, false));
    v.push_back(new Person("Kirill", 8000));
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
    // Sorting
    cout << "Sorting in the ascending order:" << endl;
    sort(v.begin(), v.end(), ascending_compare);
    vector_output(v);

    cout << "Sorting in the descending order:" << endl;
    sort(v.begin(), v.end(), descending_compare);
    vector_output(v);

    // Search_1
    Passenger search1{ 6000 };
    pass_ptr = &search1;
    Person* ptr = (Person*)pass_ptr;
    search(v, ptr);

    // Search_2
    Driver search2{ "Sergey", 6000, 7, 350 };
    driver_ptr = &search2;
    ptr = (Person*)driver_ptr;
    search(v, ptr);

    // Search_3
    Person search3{ "Kirill", 8000 };
    ptr = &search3;
    search(v, ptr);

    // Search_4
    Person search4{ 100000 };
    ptr = &search4;
    search(v, ptr);

    return 0;
}