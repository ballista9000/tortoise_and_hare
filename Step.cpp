#include <iostream>
#include "step.h"
#include "pch.h"

void Step::set_occupation(int p) {
	if (p == 0) Step::occupation =Occupation::empty;
	else if (p==1) Step::occupation = tortoise;
	else if (p==2) Step::occupation = hare;
	else if (p==3) Step::occupation = snack;
	
	else cout << "ERROR!!" << endl;

}
int Step::get_occupation() {
	if (occupation == Occupation::empty) return 0;
	if (occupation == tortoise) return 1;
	if (occupation == hare) return 2;
	if (occupation == snack) return 3;
	return -1;
}