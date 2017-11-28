#include <iostream>
#include "SuperHero.h"
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    SuperHero hero("Batman", 32, 'n');

    fin >> hero;
    cout << hero;

    hero.setAge(99);
    hero.setPowerChar('f');
    cout << hero;

    cin >> hero;

    fout << hero;
    cout << hero;

    return 0;
}
