#include "Order.h"
#include "../Passenger.h"
#include "../Driver.h"
#include "../Car.h"
#include <iostream>
#include <string>
using namespace std;

int min_payment = 200; // static member initialization

void increasePayment();
int calculatePayment(bool rate, bool congestion);

Order::Order(bool rate, bool congestion, Passenger passenger, Driver driver, Car<string> car) {
	cout << "ORDER" << endl;
	int payment;
	payment = calculatePayment(rate, congestion);

	this->status = 0;
	if (passenger.getBalance() < payment) {
		cout << "The Passenger balance is insufficient! (Cost of the trip: " << payment << ")" << endl;
	}
	else {
		if (car.fuel.getCapacity() == false) {
			cout << "The car tank is not filled!" << endl;
		}
		else {
			if (rate) { // Comfort tariff
				if (getExperience(driver) < 10 || getOrderAmount(driver) < 30) {
					cout << "The Driver doesn\'t have enough experience years or completed orders for the Comfort ride!";
				}
				else {
					if (car.getRate() == false) {
						cout << "The car rate is not high enough for the Comfort ride!" << endl;
					}
					else { // Economy tariff
						this->status = 1;
					}
				}
			}
			else { // Economy tariff
				this->status = 1;
			}
		}
	}
	if (this->status == 1) {
		passenger.takePayment(payment);
		givePayment(payment, driver);
		increaseOrderAmount(driver);
		car.fuel.empty();
		cout << "Order is completed successfully! Details:" << endl << endl;
		string buffer;
		string* rate_str = Order::rateString(rate, &buffer);
		cout << "Tariff: " << *rate_str << endl;
		string congestion_str = Order::congestionString(congestion, buffer);
		cout << "Road congestion: " << congestion_str << endl;
		cout << "Cost of the trip: " << payment << endl << endl;
		passenger << cout;
		driver << cout;
		car << cout;
	}
}

void increasePayment() {
	min_payment += 300;
}

int calculatePayment(bool rate, bool congestion) {
	int price;
	price = min_payment;
	if (rate) {
		price += 300; // Comfort tariff
	}
	if (congestion) {
		price *= 2; // if roads are loaded
	}
	return price;
}

string* Order::rateString(bool rate, string* result) {
	if (rate)
		*result = "Comfort";
	else
		*result = "Economy";
	return result;
}

string& Order::congestionString(bool congestion, string& result) {
	if (congestion)
		result = "Yes";
	else
		result = "No";
	return result;
}