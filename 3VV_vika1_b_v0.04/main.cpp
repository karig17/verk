#include <iostream>
#include "../include/SuperHero.h"
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
/*
    SuperHero hero;
    //SuperHero hero("Phill", 39, 'n');

    cin >> hero;

    fout << hero;

    cout << endl;

    hero.readLines();
*/

    ///----------------------------------------------


    int n = 1;
    cout << "How many heros? ";
    cin >> n;

    SuperHero* heros = new SuperHero[n];

    for(int i = 0; i < n; i++) {
        cin >> heros[i];
    }
    fout.open("SuperHeros2.dat", ios::binary|ios::app);
    fout.write((char*)(&heros), sizeof(SuperHero));
    fout.close();


    fin.open("SuperHeros2.dat", ios::binary);

    fin.seekg(0, fin.end);
    int recordCount = fin.tellg() / sizeof(SuperHero);
    fin.seekg(0, fin.beg);


    SuperHero* heros2 = new SuperHero[recordCount];
    fin.read((char*)(&heros2), sizeof(SuperHero));

    fin.close();

    for(int i = 0; i < recordCount; i++) {
        cout << heros2[i];
    }


    delete[] heros;
    delete[] heros2;
    return 0;
}
