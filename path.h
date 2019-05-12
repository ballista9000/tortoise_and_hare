#pragma once
#include <iostream>
#include "step.h"

using namespace std;

class Path {
private:
	Step steps[70];
	int tortoise_position;
	int hare_position;
public:
	void print_path();
	int move(int, int);
	int get_tortoise_position();
	int get_hare_position();
	int get_occupation(int);

	Path();
	~Path();
};