#pragma once
#include <iostream>
#include "occupation.h"

using namespace std;

class Step {
private: Occupation occupation;
public:
	void set_occupation(int);
	int get_occupation();
};