#pragma once

#include "Engine.h"
#include "Fuel.h"
#include "Checking.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Car : public Engine {
private:
	T id;
	std::string brand;
	bool rate;
	static int numberOfCars;
public:
	Fuel fuel;
	Car();
	Car(std::string brand);
	Car(bool rate);
	Car(std::string brand, bool rate);
	Car(T id, std::string brand, bool rate);
	void setBrand(std::string brand);
	void setRate(bool rate);
	void setID(T id);
	std::string getBrand() override;
	bool getRate();
	T getID();
	static int getNumberOfCars();
	void input();
	std::ostream& operator << (std::ostream& os);
};

template <typename T>
int Car<T>::numberOfCars = 0; // static member initialization

template <typename T>
Car<T>::Car() {
	this->fuel = new Fuel();
	this->brand = "";
	this->rate = 0;
	numberOfCars++;
}

template <typename T>
Car<T>::Car(string brand) {
	this->fuel = new Fuel();
	this->brand = brand;
	this->rate = 0;
	numberOfCars++;
}

template <typename T>
Car<T>::Car(bool rate) {
	this->fuel = new Fuel();
	this->brand = "";
	this->rate = rate;
	numberOfCars++;
}

template <typename T>
Car<T>::Car(string brand, bool rate) {
	this->fuel = new Fuel();
	this->brand = brand;
	this->rate = rate;
	numberOfCars++;
}

template <typename T>
Car<T>::Car(T id, string brand, bool rate) {
	this->fuel = new Fuel();
	this->id = id;
	this->brand = brand;
	this->rate = rate;
	numberOfCars++;
}

template <typename T>
void Car<T>::setBrand(string brand) {
	this->brand = brand;
}

template <typename T>
void Car<T>::setRate(bool rate) {
	this->rate = rate;
}

template <typename T>
void Car<T>::setID(T id) {
	this->id = id;
}

template <typename T>
string Car<T>::getBrand() {
	return this->brand;
}

template <typename T>
bool Car<T>::getRate() {
	return this->rate;
}

template <typename T>
T Car<T>::getID() {
	return this->id;
}

template <typename T>
int Car<T>::getNumberOfCars() {
	return numberOfCars;
}

template <typename T>
void Car<T>::input() {
	string temp; bool flag;
	cout << "** Car data entry **" << endl;
	cout << "ID: ";
	cin >> this->id;
	do {
		cout << "Brand: ";
		cin >> this->brand;
		flag = Checking::nameCheck(this->brand);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	do {
		cout << "Rate (0 - Economy, 1 - Comfort): ";
		cin >> temp;
		flag = Checking::boolCheck(temp);
		if (!flag) cout << "Please try again.. ";
	} while (!flag);
	this->rate = stoi(temp);
	cout << "The data are entered successfully!" << endl << endl;
}

template <typename T>
ostream& Car<T>::operator << (ostream& os) {
	string buffer;
	if (!(this->brand.empty())) {
		return os << "Car data:\n- ID: " << this->id << "\n- Brand: " << "\n- Rate (0 - Economy, 1 - Comfort): " << this->rate << endl;
	}
	else
		throw string{"The Car brand is missing!"};
}