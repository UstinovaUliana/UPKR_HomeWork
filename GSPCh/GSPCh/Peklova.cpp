#include <iostream>
#include <vector>
#include <math.h>
#include <random>

using namespace std;


double GMM(vector<double>& v, double firstRandomNum, double secondRandomNum)
{
    int k = v.size();
    double res;
    int j;

    j = int(secondRandomNum * k);
    if (j < 1)
        j = 1;

    res = v[j];
    v[j] = firstRandomNum; //случайное заполнение новым числом
    return res;
}


vector<float> Maklaren(int outputSequenceLen, float numberMinLimit, float numberMaxLimit, float scale)
{
    int k = 128; //размер матрицы V

    int i = 0;

    vector<double> secondaryMatrix; //вспомогательная матрица
    vector<double> outputSequence; //выходная последовательность4

    //https://www.delftstack.com/howto/cpp/how-to-generate-random-doubles-cpp/
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(0.0, 1.0);

    for (int i = 0; i < k; i++)
        secondaryMatrix.push_back(distr(eng)); //Инициализация матрицы secondaryMatrix

    for (int i = 0; i < outputSequenceLen; i++)
    {
        double val = GMM(secondaryMatrix, distr(eng), distr(eng));

        //пересчитываем значение из диапазона [0.0, 1.0] в [numberMinLimit, numberMaxLimit]
        val = ((val - 0.0) / (1.0 - 0.0)) * (numberMaxLimit - numberMinLimit) + numberMinLimit;

        outputSequence.push_back(val);
    }

    vector<float> outVect;
    copy(outputSequence.begin(), outputSequence.end(), back_inserter(outVect));
    for (auto& i : outVect) {
        i = floor(i * scale) / scale;
    }
    return outVect;
}
