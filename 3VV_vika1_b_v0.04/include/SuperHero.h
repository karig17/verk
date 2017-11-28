#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class SuperHero
{
    private:
        static const int MAX_STRING_LENGTH = 32;

        char heroName[MAX_STRING_LENGTH];
        int heroAge;
        char heroPowerChar;

        string heroPower() const;

    public:
        SuperHero();
        SuperHero(string name, int age, char power);

        string getName();
        int getAge();
        char getPowerChar();

        void readLines();

        void setName(string newName);
        void setAge(int newAge);
        void setPowerChar(char newPowerChar);

        friend istream&  operator >> (istream& in, SuperHero& hero);
        friend ostream&  operator << (ostream& out, const SuperHero& hero);
        friend ifstream& operator >> (ifstream& fin, SuperHero& hero);
        friend ofstream& operator << (ofstream& fout, const SuperHero& hero);

};

#endif // SUPERHERO_H
