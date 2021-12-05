#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <math.h>
using namespace std;

int RandNum(int& x0, int m) {
	int nextRandNum = (x0 * x0) % m;
	x0 = nextRandNum;
	return nextRandNum;
}

vector <float> BBS_algorithm(int kolvo, float ngd, float vgd, float scale) {
	vector <float> BBS;
	int random;
	int p = 111;
	int q = 77;
	int x0 = 13;
	int m = p * q;
	cout << "Blum-Blum-Shub algorithm\n";
	cout << "Generate ";
	cout << kolvo;
	cout << " random numbers: ";

	for (int i = 0; i < kolvo; i++) {
		random = ngd + RandNum(x0, m) % vgd;
		BBS.push_back((float)random);
	}

	for (auto& i : BBS) {
		i = floor(i * scale) / scale;
	}

	return BBS;
}