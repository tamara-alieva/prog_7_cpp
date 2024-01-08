#pragma once
#include <string>

class Person {
protected:
	std::string type;
	std::string name;
	int balance;
public:
	Person();
	Person(std::string name);
	Person(int balance);
	Person(std::string name, int balance);
	void setName(std::string name);
	void setBalance(int balance);
	void setInfo(std::string name, int balance);
	std::string getType();
	std::string getName() const ;
	int getBalance();
	virtual void input();
	void output();
	void test_virtual();
	void test_non_virtual();
	std::ostream& operator << (std::ostream& os);
	bool operator<(Person& person);
};