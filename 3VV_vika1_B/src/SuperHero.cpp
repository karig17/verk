#include "../include/SuperHero.h"

SuperHero::SuperHero() {
    heroName[0] = '\0';
    heroAge = 0;
    heroPowerChar = 'n';
}

SuperHero::SuperHero(string name, int age, char power) {
    for(int i = 0; i < name.size(); i++) {
        heroName[i] = name.at(i);
    }
    heroName[name.size()] = '\0';
    heroName[31] = '\0';
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

void SuperHero::readLines() {
    ifstream fin;
    fin.open("SuperHeros.dat", ios::binary);
    if(fin.is_open()) {
        SuperHero tempHero;

        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(SuperHero);
        fin.seekg(0, fin.beg);

        for(int i = 0; i < recordCount; i++) {
            fin.read((char*)(&tempHero), sizeof(SuperHero));
            cout << tempHero;
        }
        cout << endl;
    }
    fin.close();
}

void SuperHero::setName(string newName) {
    for(int i = 0; i < MAX_STRING_LENGTH; i++) {
        heroName[i] = newName.at(i);
    }
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
    cout << "Enter name:  ";
    cin >> hero.heroName;
    cout << "Enter age:   ";
    cin >> hero.heroAge;
    cout << "Enter Power: ";
    cin >> hero.heroPowerChar;
    return in;
}

ostream& operator << (ostream& out, const SuperHero& hero) {
    cout << hero.heroName << " (" << hero.heroAge << "): " << hero.heroPower() << endl;
    return out;
}


ifstream& operator >> (ifstream& fin, SuperHero& hero) {
    fin.open("SuperHeros.dat", ios::binary);
    if(fin.is_open()) {
        fin.read((char*)(&hero), sizeof(SuperHero));
    } else {
        cout << "Unable to read file" << endl;
    }
    fin.close();
    return fin;
}

ofstream& operator << (ofstream& fout, const SuperHero& hero) {
    fout.open("SuperHeros.dat", ios::binary|ios::app);
    fout.write((char*)(&hero), sizeof(SuperHero));
    fout.close();
    return fout;
}

/*
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
*/
