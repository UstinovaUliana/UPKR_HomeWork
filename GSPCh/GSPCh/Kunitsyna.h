#include <cmath>
#include<iostream>

class BBS {

public:
	int p, q, m, x0;
	BBS();
	~BBS();
	BBS(int p, int q, int x0);
	int RandBit();
	int RandNum();
	void setParametrs(int p, int q, int x0);
};
