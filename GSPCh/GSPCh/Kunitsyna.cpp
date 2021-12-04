#include "Kunitsyna.h"
using namespace std;

BBS::BBS() {
	p = 0;
	q = 0;
	x0 = 0;
	m = p * q;
}

void BBS::setParametrs(int p, int q, int x0) {
	this->p;
	this->q;
	this->x0;
	this->m = p * q;
}

BBS::BBS(int p, int q, int x0) {
	setParametrs(p, q, x0);
}

int BBS::RandNum() {
	int nextRandNum = (x0 * x0) % m;
	x0 = nextRandNum;
	return nextRandNum;
}

int BBS::RandBit() {
	return RandNum() % 2;
}

BBS::~BBS() {}