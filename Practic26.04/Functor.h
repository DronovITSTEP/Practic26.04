#pragma once
#include <iostream>
using namespace std;

class Functor {
	int delta;
	int current;
public:
	Functor(int num, int from = 0):delta{num}, current{from}{}

	int operator()() {
		return current += delta;
	}
};
