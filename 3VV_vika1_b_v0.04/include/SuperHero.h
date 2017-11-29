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

        /// Returns the Superpower associated with a power character.
        string heroPower() const;

    public:
        SuperHero();
        SuperHero(string name, int age, char power);

        /// A set of functions that get a SuperHero's aspect in it's current state.
        string getName();
        int getAge();
        char getPowerChar();

        /// Writes out all of the SuperHeros from a file to the console.
        void readLines();

        /// A set of functions that set a SuperHero's aspect to a given state.
        void setName(string newName);
        void setAge(int newAge);
        void setPowerChar(char newPowerChar);

        /// Overloads the >> operator so one can read in a SuperHero from the console.
        friend istream&  operator >> (istream& in, SuperHero& hero);
        /// Overloads the << operator so one can write out a SuperHero to the console.
        friend ostream&  operator << (ostream& out, const SuperHero& hero);
        /// Overloads the >> operator so one can read in a SuperHero from a file.
        friend ifstream& operator >> (ifstream& fin, SuperHero& hero);
        /// Overloads the << operator so one can write out a SuperHero to a file.
        friend ofstream& operator << (ofstream& fout, const SuperHero& hero);
};

#endif // SUPERHERO_H
