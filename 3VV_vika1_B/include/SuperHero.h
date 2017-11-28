#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class SuperHero
{
    private:
        string heroName;
        int heroAge;
        char heroPowerChar;

        string heroPower() const;

    public:
        SuperHero();
        SuperHero(string name, int age, char power);

        string getName();
        int getAge();
        char getPowerChar();

        void setName(string newName);
        void setAge(int newAge);
        void setPowerChar(char newPowerChar);

        friend istream&  operator >> (istream& in, SuperHero& hero);
        friend ostream&  operator << (ostream& out, const SuperHero& hero);
        friend ifstream& operator >> (ifstream& fin, SuperHero& hero);
        friend ofstream& operator << (ofstream& fout, const SuperHero& hero);

};

#endif // SUPERHERO_H
