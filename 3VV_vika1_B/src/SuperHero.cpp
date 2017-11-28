#include "SuperHero.h"

SuperHero::SuperHero() {
    heroName = "";
    heroAge = 0;
    heroPowerChar = 'n';
}

SuperHero::SuperHero(string name, int age, char power) {
    heroName = name;
    heroAge = age;
    heroPowerChar = power;
}

string SuperHero::getName() {
    return heroName;
}

int SuperHero::getAge() {
    return heroAge;
}

char SuperHero::getPowerChar() {
    return heroPowerChar;
}

void SuperHero::setName(string newName) {
    heroName = newName;
}

void SuperHero::setAge(int newAge) {
    heroAge = newAge;
}

void SuperHero::setPowerChar(char newPowerChar) {
    heroPowerChar = newPowerChar;
}

string SuperHero::heroPower() const {
           if(heroPowerChar == 'f') {
        return "Flying";
    } else if(heroPowerChar == 'g') {
        return "Giant";
    } else if(heroPowerChar == 'h') {
        return "Hacker";
    } else if(heroPowerChar == 'n') {
        return "None";
    } else {
        return "Weakling";
    }
}

istream& operator >> (istream& in, SuperHero& hero) {
    cin >> hero.heroName >> hero.heroAge >> hero.heroPowerChar;
    return in;
}

ostream& operator << (ostream& out, const SuperHero& hero) {
    cout << hero.heroName << " (" << hero.heroAge << "): " << hero.heroPower() << endl;
    return out;
}

ifstream& operator >> (ifstream& fin, SuperHero& hero) {
    fin.open("SuperHeros.txt");
    if(fin.is_open()) {
        fin >> hero.heroName;
        fin >> hero.heroAge;
        fin >> hero.heroPowerChar;
    } else {
        cout << "Unable to read file" << endl;
    }
    fin.close();
    return fin;
}

ofstream& operator << (ofstream& fout, const SuperHero& hero) {
    fout.open("SuperHeros.txt", ios::app);
    fout << hero.heroName << "\t" << hero.heroAge << "\t" << hero.heroPowerChar << endl;
    fout.close();
    return fout;
}
