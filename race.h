#pragma once
#include <iostream>
#include "tortoise.h"
#include "hare.h"
#include "path.h"

using namespace std;

class Race {
private :
public :
	int update();
	Path path;
	Tortoise tortoise;
	Hare hare;
};
