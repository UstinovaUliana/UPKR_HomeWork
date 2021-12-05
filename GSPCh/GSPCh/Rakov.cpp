#include <iostream>
#include<chrono>
#include<math.h>
#include <cmath>
#include<algorithm>
using namespace std;
void Psevdo();
int main()
{
    Psevdo();
}

void Psevdo()
{
    //e^x;
    float P_arr[1000] = {};
    float size = sizeof(P_arr) / sizeof(P_arr[0]);;
    float Y_rand;
    float lyambda = 1 / size;
    float* first(&P_arr[0]);
    float* last(&P_arr[1000]);
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int a = 0; a < size; a++)
    {
        Y_rand = (float)rand() / (float)RAND_MAX;
        P_arr[a] = ((-1) * log(Y_rand)) / lyambda;//X
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();;
    //sort(first, last, [](float a, float b){
    //       return a < b;});
    for (int a = 0; a < size; a++)
    {
        cout << P_arr[a] << endl;
    }
    cout << "insert(mks): " << duration << endl;
}

