#include <iostream>
#include <string>
#include <Windows.h>
#include "path.h"
#include "pch.h"
#include <vector>
#include "util.h"


using namespace std;

Path::Path() {
	int k;
	for (k = 0; k < 70; k++)
		steps.push_back(Step());
	for (k = 0; k < 70; k++)
		if (k % 10 != 0) steps[k].set_occupation(0);
		else steps[k].set_occupation(3);
}

int Path::get_occupation(int s) {
	return steps[s].get_occupation();
}

void Path::set_steps(int pos, int value) {
	if (pos >= 0 && pos < 70 && value >= 0 && value < 4) steps[pos].set_occupation(value);
}

void Path::print_path() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k;
	for (k = 0; k < 70; k++) {
		if (steps[k].get_occupation() == 0) {
			SetConsoleTextAttribute(hConsole, 0);
			cout << ".";
			SetConsoleTextAttribute(hConsole, 15);
		}
		if (steps[k].get_occupation() == 1) {
			SetConsoleTextAttribute(hConsole, 10);
			cout << "T";
			SetConsoleTextAttribute(hConsole, 15);
		}
		if (steps[k].get_occupation() == 2) {
			SetConsoleTextAttribute(hConsole, 13);
			cout << "H";
			SetConsoleTextAttribute(hConsole, 15);
		}
		if (steps[k].get_occupation() == 3) cout << " ";
		if (steps[k].get_occupation() == -1) cout << "e"; // если ошибка
	}
}

int Path::move(int new_tpos, int new_hpos) {
	if ((tortoise_position + new_tpos) >= 70) {
		steps[tortoise_position].set_occupation(0);
		tortoise_position = 69;
		steps[tortoise_position].set_occupation(1);
		print_path();
		cout << endl << "Tortoise win!" << endl;
		cout << face_turtle;
		return 1;
	}

	if ((hare_position + new_hpos) >= 70) {
		steps[hare_position].set_occupation(0);
		hare_position = 69;
		steps[hare_position].set_occupation(2);
		print_path();
		cout << endl << "Hare win!" << endl;
		cout << face_hare;
		return 1;
	}

	steps[tortoise_position].set_occupation(0);
	steps[hare_position].set_occupation(0);

	if ((tortoise_position + new_tpos) > 0) {
		tortoise_position = tortoise_position + new_tpos;
		steps[tortoise_position].set_occupation(1);
	}
	else {
		steps[0].set_occupation(1);
		tortoise_position = 0;
	}

	if ((hare_position + new_hpos) > 0) {
		hare_position = hare_position + new_hpos;
		steps[hare_position].set_occupation(2);
	}
	else {
		steps[0].set_occupation(2);
		hare_position = 0;
	}
	return 0;
}

int Path::get_tortoise_position() { return tortoise_position; }
int Path::get_hare_position() { return hare_position; }

