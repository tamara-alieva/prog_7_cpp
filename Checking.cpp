#include "Checking.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool Checking::nameCheck(string name) {
    bool f = 1;
	f = regex_match(name, regex("^[A-Za-z]+$"));
	return f;
}
bool Checking::intCheck(string balance) {
    int i = 0; bool f = 1;
	for (i = 0; i < balance.length(); i++) {
		if (balance[i] >= '0' && balance[i] <= '9') f = 1;
		else {
			f = 0;
			break;
		}
	}
	return f;
}
bool Checking::boolCheck(string str) {
    bool f;
    f = !str.empty() && (str == "0" || str == "1");
    return f;
}