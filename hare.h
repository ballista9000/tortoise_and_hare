#pragma once
#include <iostream>

using namespace std;

class Hare {
private:
	int energy;
	bool down;
public:
	int movement(int);
	int get_energy();
	int set_energy(int);
	void restore_energy();

	Hare();
	~Hare();
};