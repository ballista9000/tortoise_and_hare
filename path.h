#pragma once
#include <iostream>
#include "step.h"
#include <vector>

using namespace std;

class Path {
private:
	//Step steps[70];
	vector<Step> steps;
	int tortoise_position;
	int hare_position;
public:
	void print_path();
	int move(int, int);
	int get_tortoise_position();
	int get_hare_position();
	int get_occupation(int);
	void set_steps(int, int);
	Path();
};