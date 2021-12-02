#include<iostream>
#include "Kunitsyna.h"
using namespace std;

int main() {
    const int p = 7;
    const int q = 19;
    const int x0 = 6;

    BBS NumberGenerate(p, q, x0);

    cout << "Generate 10 random numbers: ";
    for (int i = 0; i < 10; i++) {
        cout << NumberGenerate.RandNum() << " ";
    }
   
    cout << endl;

    cout << "Generate 10 random bits: ";
    for (int i = 0; i < 10; i++) {
        cout << NumberGenerate.RandBit() << " ";
    }

    return 0;
}