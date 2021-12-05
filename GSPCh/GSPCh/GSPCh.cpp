#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
using namespace std;


int getInt()
{
    int input;
    while (1) {
        cin >> input;
        if (!cin.fail())
            return input;
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Ошибка, повторите ввод" << endl;
    }
}
float getFloat()
{
    float input;
    while (1) {
        cin >> input;
        if (!cin.fail())
            return input;
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Ошибка, повторите ввод" << endl;
    }
}


using alg = vector<float>(*)(int kolvo, float ngd, float vgd, float scale)/*(int dano)*/;
//vector <int> Kunitsyna(int dano);
//vector <int> Kunitsyna(int dano);
vector<float> Maklaren(int kolvo, float ngd, float vgd, float scale);
bool compLess(int a, int b)
{
    return (a < b);
}
void checkAlg(/*string name, */alg algoritm, int kolvo, float ngd, float vgd, float scale) {
    auto start = chrono::system_clock::now();
    vector<float> result = algoritm(kolvo,ngd,vgd,scale)/*(dano[3])*/;
    auto stop = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    for (auto i : result) {
        cout << i << endl;
    }

    vector <int> period;
    for (int i = 0; i < result.size()-1; i++) {
        for (int j = i+1; j < result.size(); j++) {
            if (result[j]==result[i]) {
                period.push_back(j - i);
            }
        }
    }
    int minPer=result.size(); 
    for (int i = 0; i < period.size(); i++) {
        if (period[i] < minPer) {
            minPer = period[i];
        }
    }
    cout << "Period: " << minPer << endl <<"Duration (mks): " << duration << endl;
    //равномерное распределение
    //float raspr = 1./dano[3]-dano[2];
    //float srper; //средний период
    //float srznach=sumres/ result.size(); //среднее значение
    //int s=result.size()-1;
    //vector <int> di;
    //for (int i = 1; i < result.size(); i++) {
    //    // map <i, appearence count> ;
    //    //

    //    di.push_back(result[i + 1] - result[i]);
    //    int sumdi=0;
    //    for (auto j : di) {
    //        sumdi += j;
    //    }
    //    srper = sumdi / s;
    //}


}

int main()
{
    int kolvo;
    float ngd;
    float vgd;
    float scale;
   /*
    int range;
    int p;
    int q;
    int x0;
    int m; */
    cout << "Enter quantity: ";
    kolvo = getInt();
    cout << endl << "Enter limit: ";
    cout << endl << "From: ";
    ngd = getFloat();
    cout << endl << "To: ";
    vgd = getFloat();
    cout << endl << "Enter nubers after point: ";
    scale = getFloat();
    /*vector<double> outputSequence = Maklaren();
    for (auto i : outputSequence) {
        cout << i << endl;
    }*/
    cout << "Maklaren" << endl;
   checkAlg(Maklaren,kolvo,ngd,vgd,scale);
    /*checkAlg(Kunitsyna);
    checkAlg(Peklova);
    checkAlg(Rakov);*/
}
//Период - это когда числа начинают повторяться
//Быстрота получения Xn+1 элемента последовательности чисел при задании Xn элемента для I любой величины; 
//Функции запуска алгоритмов доделать
