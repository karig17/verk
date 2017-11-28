#include <iostream>
#include "../include/SuperHero.h"
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    SuperHero hero;
    //SuperHero hero("Phill", 39, 'n');

    cin >> hero;

    fout << hero;

    cout << endl;

    hero.readLines();
    return 0;
}
