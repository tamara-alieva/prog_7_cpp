#pragma once
#include <string>

class Fuel {
private:
	bool capacity;
public:
	Fuel();
	Fuel(bool capacity);
	void setCapacity(bool capacity);
	bool getCapacity();
	void input();
	void fill();
	void empty();
	std::ostream& operator << (std::ostream& os);
};