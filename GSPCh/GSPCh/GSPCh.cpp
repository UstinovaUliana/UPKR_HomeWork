#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <fstream>
using namespace std;

void saveResult(string ofileName,vector <float> result, int minPer, int duration, int kolvo, float ngd, float vgd, float scale)
{
    ofstream fout;
    fout.open(ofileName + ".txt", ios::out);

    if (fout.is_open()) {
        fout << "Generated "<<kolvo << " numbers from " << ngd << " to " << vgd << " with accuracy " << scale << "." << endl;
        for (auto& i : result) {
            fout << i << endl;
        }
        if (minPer == result.size()) fout << "Period: >=";
        else fout << "Period: ";
        fout << minPer << "." << endl << "Duration: " << duration<<" mks." << endl;
        fout.close();
    }
}

vector <float> loadDano()
{
    vector <float> dannie;
    ifstream fin;
    cout << "Enter file name: ";
    string ifileName;
    cin >> ws;
    getline(cin, ifileName);
    fin.open(ifileName + ".txt", ios::in);
    if (fin.is_open())
    {
        float dano;
        while (!fin.eof()) {
            fin >> dano;
            dannie.push_back(dano);
        }
        fin.close();
    }
    else cout << "Can't open the file." << endl;
    return dannie;
}

using alg = vector<float>(*)(int kolvo, float ngd, float vgd, float scale);
vector<float> Maklaren(int kolvo, float ngd, float vgd, float scale);
vector <float> Psevdo(int kolvo, float ngd, float vgd, float scale);
vector <float> BBS_algorithm(int kolvo, float ngd, float vgd, float scale);

void checkAlg(string name, alg algoritm, int kolvo, float ngd, float vgd, float scale) {
    auto start = chrono::system_clock::now();
    vector<float> result = algoritm(kolvo,ngd,vgd,scale);
    auto stop = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    for (auto i : result) {
        cout << i << endl;
    }

    vector <int> period;
    for (int i = 0; i < result.size()-3; i++) {
        for (int j = i+1; j < result.size()-2; j++) {
            if (result[j]==result[i] && result[j+1]==result[i+1] && result[j+2]==result[i+2]) {
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
    if (minPer == result.size()) cout << "Period: >=";
    else cout << "Period: ";
    cout << minPer << endl << "Duration (mks): " << duration << endl;
    saveResult(name, result, minPer, (int)duration, kolvo, ngd, vgd, scale);
}

int main()
{
        int kolvo;
        float ngd;
        float vgd;
        float scale;
        vector <float> dannie = loadDano();
        int iters = dannie.size() / 4;
        for (int i = 0; i < iters; i++) {
            kolvo = dannie[4 * i]; //0 4 8 12 16
            ngd = dannie[4 * i + 1];// 1 5 9 13 17
            vgd = dannie[4 * i + 2];//2 6 10 14 18
            scale = dannie[4 * i + 3];//3 7 11 15 19
            cout << "McLaren-Marsaglia generator" << endl;
            checkAlg("McLaren-Marsaglia generator_" + to_string(i+1), Maklaren, kolvo, ngd, vgd, scale);
            cout << "Inverse transform method" << endl;
            checkAlg("Inverse transform method_" + to_string(i+1), Psevdo, kolvo, ngd, vgd, scale);
            checkAlg("Blum-Blum-Shub algorithm_" + to_string(i+1), BBS_algorithm, kolvo, ngd, vgd, scale);
        }
}
