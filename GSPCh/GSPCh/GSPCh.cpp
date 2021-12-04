#include "Kunitsyna.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
<<<<<<< HEAD
#include "Kunitsyna.cpp"
#include <math.h>
#include <random>
using namespace std;

vector <float> Maklaren(); 
=======
#include <vector>
using namespace std;

>>>>>>> ed2fec4198affb2b0ea1a45267b480f9af475508

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

using alg = vector<float>(*)()/*(int dano)*/;
//vector <int> Kunitsyna(int dano);
//vector <int> Kunitsyna(int dano);

void checkAlg(/*string name, */alg algoritm/*, int dano[3]*/) {
    auto start = chrono::system_clock::now();
    vector<float> result = algoritm()/*(dano[3])*/;
    auto stop = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    for (auto i : result) {
        cout << i << endl;
    }
    int period;
    for (int i =0; i < result.size()-1; i++) {
        for (int j = i+1; j < result.size(); j++) {
            if (result[j]==result[i]) {
                period = j - i;
                break;
            }
            else  period = result.size();
        }
    }
<<<<<<< HEAD
    cout << period << endl << duration << endl;
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


=======
>>>>>>> ed2fec4198affb2b0ea1a45267b480f9af475508
}

int main()
{
    setlocale(LC_ALL, "Russian");
<<<<<<< HEAD
   /* int kolvo;
=======
    int kolvo;
    /*
>>>>>>> ed2fec4198affb2b0ea1a45267b480f9af475508
    int ngd;
    int vgd;
    */
    int range;
    int p;
    int q;
    int x0;
    int m;
    cout << "Введите количество случайных чисел: ";
    kolvo = getInt();
    cout << endl << "Введите диапазон: ";
    range = getInt();
    /*
    cout << endl << "От: ";
    ngd = getInt();
    cout << endl << "До: ";
    vgd = getInt();
<<<<<<< HEAD
    int dano[3] = { kolvo,ngd,vgd };*/
    /*vector<double> outputSequence = Maklaren();
    for (auto i : outputSequence) {
        cout << i << endl;
    }*/
   checkAlg(Maklaren);
    /*checkAlg(Kunitsyna);
    checkAlg(Peklova);
    checkAlg(Rakov);*/
}
//Период - это когда числа начинают повторяться
//Быстрота получения Xn+1 элемента последовательности чисел при задании Xn элемента для I любой величины; 
//Функции запуска алгоритмов доделать
=======
    int dano[3] = { kolvo,ngd,vgd };
    */

    cout << "Алгоритм Блюм-Блюма-Шуба\n";
    cout << "Введите p: ";
    p = getInt();
    cout << "Введите q: ";
    q = getInt();
    cout << "Введите x0: ";
    x0 = getInt();
    m = p * q;

    BBS NumberGenerate(p, q, x0);

    cout << "Генерация ";
    cout << kolvo;
    cout << " случайных чисел: ";

    for (int i = 0; i < kolvo; i++) {
        cout << NumberGenerate.RandNum() % range << " ";
    }

    cout << endl;

    cout << "Генерация ";
    cout << kolvo;
    cout << " случайных битов: ";

    for (int i = 0; i < kolvo; i++) {
        cout << NumberGenerate.RandBit() << " ";
    }
    return 0;
}


>>>>>>> ed2fec4198affb2b0ea1a45267b480f9af475508
