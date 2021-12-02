#include <cmath>
#include<iostream>

class BBS {

private:
	int p, q, m, x0;

public:
	BBS();
	~BBS();
	BBS(int p, int q, int x0);
	int RandBit();
	int RandNum();
	void setParametrs(int p, int q, int x0);
};
