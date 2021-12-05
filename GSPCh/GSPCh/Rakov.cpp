#include <iostream>
#include<math.h>
#include<vector>
using namespace std;
vector <float> Psevdo(const int& arr_size)
{
    //y=5^x
    vector<float> P_arr = {};
    float Y_rand, digit;
    float lyambda = (float)1 / arr_size;
    for (int a = 0; a < arr_size; a++)
    {
        Y_rand = (float)rand() / (float)RAND_MAX;
        digit = -1 * ((float)log(Y_rand) / (float)log(5)) / lyambda;//X=logY/log5
        P_arr.push_back(digit);
    }
    return P_arr;
}