#include <iostream>
#include "race.h"
#include "random.h"
#include "pch.h"

using namespace std;

int Race::update() {
	if (hare.get_energy() == 0) {
		hare.set_energy(10);
		return 0;
	}

	if (tortoise.get_energy() == 0) {
		tortoise.set_energy(10);
		return 0;
	}

	int rate = random(10);
	int t_m = tortoise.movement(rate);
	rate = random(10);
	int h_m = hare.movement(rate);

	if (path.get_hare_position() == path.get_tortoise_position()) hare.set_energy(-3);
	int status = path.move(t_m, h_m);

	if (path.get_occupation(path.get_tortoise_position()) == 3) {
		tortoise.restore_energy();
		path.set_steps(path.get_tortoise_position(), 0);
	}

	if (path.get_occupation(path.get_hare_position()) == 3) {
		tortoise.restore_energy();
		path.set_steps(path.get_hare_position(), 0);
	}
	return status;
}