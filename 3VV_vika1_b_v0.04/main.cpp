#include <iostream>
#include "include/SuperHero.h"
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    SuperHero hero;                         // The default constructor.
    //SuperHero hero("Phill", 39, 'n');     // The constructor with variables.

    /// Receives input for a new hero.
    cout << "Enter information about a super hero:" << endl;
    cin >> hero;

    hero.setName("Günter");

    /// Writes the hero to a file.
    fout << hero;

    /// Writes the hero to the console.
    cout << endl;

    /// Writes all the heros from the file to the console.
    hero.readLines();



    ///=========================================================



    /// Receives and verifies input for the number of new heros.
    int n = 0;
    do {
        cout << "How many heros? ";
        cin >> n;
    } while(n < 0);

    SuperHero* heros = new SuperHero[n];

    /// Receives input for the new heros.
    for(int i = 0; i < n; i++) {
        cin >> heros[i];
    }

    /// Writes the new heros to a file.
    fout.open("SuperHeros2.dat", ios::binary|ios::app);
    fout.write((char*)(heros), n * sizeof(SuperHero));
    fout.close();

    /// Writes out all the heros from a file to the console.
    fin.open("SuperHeros2.dat", ios::binary);
    fin.seekg(0, fin.end);
    int recordCount = fin.tellg() / sizeof(SuperHero);
    fin.seekg(0, fin.beg);

    /// Reads all the heros from a file.
    SuperHero* heros2 = new SuperHero[recordCount];
    fin.read((char*)(heros2), recordCount * sizeof(SuperHero));
    fin.close();

    cout << endl;

    /// Writes all the heros to the console.
    for(int i = 0; i < recordCount; i++) {
        cout << heros2[i];
    }

    delete[] heros;
    delete[] heros2;
    return 0;
}
