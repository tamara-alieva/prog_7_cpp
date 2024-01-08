#pragma once
#include "../Passenger.h"
#include "../Driver.h"
#include "../Car.h"
#include <string>

class Order
{
private:
	static int min_payment;
	int status;
public:
	Order(bool rate, bool congestion, Passenger passenger, Driver driver, Car<std::string> car);
	static std::string* rateString(bool rate, std::string* result);
	static std::string& congestionString(bool congestion, std::string& result);
};

