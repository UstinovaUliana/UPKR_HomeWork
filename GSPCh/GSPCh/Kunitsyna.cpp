#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <math.h>
using namespace std;

int p = 111;
int q = 77;
int x0 = 13;
int m = p * q;
int kolvo, i, random, ngd, vgd;

int RandNum(int& x0, int m) {
	int nextRandNum = (x0 * x0) % m;
	x0 = nextRandNum;
	return nextRandNum;
}

vector <int> algorithm() {
	vector <int> BBS = {};
	cout << "Blum-Blum-Shub algorithm\n";
	cout << "Generate ";
	cout << kolvo;
	cout << " random numbers: ";

	for (int i = 0; i < kolvo; i++) {
		random = ngd + RandNum(x0, m) % vgd;
		cout << random << " ";
		BBS.push_back((float)random);
	}
	cout << endl;
	return BBS;
}