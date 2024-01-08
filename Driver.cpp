#include "Driver.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

Driver::Driver() : Person(0) {
	this->experience = 0;
	this->orderAmount = 0;
}
Driver::Driver(string name) : Person(name, 0) {
	this->experience = 0;
	this->orderAmount = 0;
}
Driver::Driver(int balance) : Person(balance) {
	this->experience = 0;
	this->orderAmount = 0;
}
Driver::Driver(string name, int balance, int experience, int orderAmount) : Person(name, balance) {
	this->experience = experience;
	this->orderAmount = orderAmount;
}
void Driver::setInfo(std::string name, int balance, int experience, int amount) {
	this->name = name;
	this->balance = balance;
	this->experience = experience;
	this->orderAmount = amount;
}
void Driver::input() {
	string temp; bool flag;
	cout << "** Driver data entry: " << this->name << " **" << endl;
	do {
		cout << "Years of experience: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->experience = stoi(temp);
	do {
		cout << "Amount of completed orders: ";
		cin >> temp;
		flag = Checking::intCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->orderAmount = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}

// friend functions
void setExperience(int experience, Driver& driver) {
	driver.experience = experience;
}
void setOrderAmount(int orderAmount, Driver& driver) {
	driver.orderAmount = orderAmount;
}
int getExperience(Driver& driver) {
	return driver.experience;
}
int getOrderAmount(Driver& driver) {
	return driver.orderAmount;
}
void givePayment(int payment, Driver& driver) {
	int old_balance = driver.getBalance();
	driver.setBalance(old_balance + payment);
}
void increaseOrderAmount(Driver& driver) {
	int old_amount = getOrderAmount(driver);
	setOrderAmount(old_amount + 1, driver);
}
void output(Driver& driver) {
	if (!((driver.getName()).empty())) {
		cout << "Driver data:" << endl << "- Name: " << driver.getName() << endl;
		cout << "- Balance: " << driver.getBalance() << endl;
		cout << "- Years of experience: " << getExperience(driver) << endl;
		cout << "- Amount of completed orders: " << getOrderAmount(driver) << endl << endl;
	}
	else
		throw string{"The Driver name is missing!"};
}
// operator overload
Driver& Driver::operator=(Person& person) {
	this->name = person.getName();
	this->balance = person.getBalance();
	return *this;
}

Driver operator + (Driver& driver1, Driver& driver2) // operator +
{
	return Driver(driver1.getBalance() + driver2.getBalance());
}
Driver& operator++ (Driver& driver) // prefix operator ++
{
	setExperience(getExperience(driver) + 1, driver);
	return driver;
}
Driver operator++ (Driver& driver, int) // postfix operator ++
{
	Driver copy(driver);
	++driver;
	return copy;
}
ostream& Driver::operator << (ostream& os) {
	if (!(this->name.empty())) {
		return os << "Driver data:" << endl << "- Name: " << this->name << endl << "- Balance: " << this->balance << endl << "- Years of experience: " << this->experience << endl << "- Amount of completed orders: " << this->orderAmount << endl << endl;
	}
	else
		throw string{"The Driver name is missing!"};
}