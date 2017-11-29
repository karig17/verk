#include "../include/SuperHero.h"

SuperHero::SuperHero() {
    heroName[0] = '\0';
    heroAge = 0;
    heroPowerChar = 'n';
}

SuperHero::SuperHero(string name, int age, char power) {
    strToCharArr(name);
    heroAge = age;
    heroPowerChar = power;
}


/// A set of functions that return a SuperHero's aspect in its current state.
string SuperHero::getName() const{
    return heroName;
}

int SuperHero::getAge() const{
    return heroAge;
}

char SuperHero::getPowerChar() const{
    return heroPowerChar;
}


/// Converts strings to a character array.
void SuperHero::strToCharArr(string name) {
    for(unsigned int i = 0; i < name.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        heroName[i] = name.at(i);
    }
    heroName[name.size()] = '\0';                   // Adds the esc.character after the end of the string.
    heroName[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}


/// Writes out all of the SuperHeros from a file to the console.
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


/// A set of functions that set a SuperHero's aspect to a given state.
void SuperHero::setName(string newName) {
    strToCharArr(newName);
}

void SuperHero::setAge(int newAge) {
    heroAge = newAge;
}

void SuperHero::setPowerChar(char newPowerChar) {
    heroPowerChar = newPowerChar;
}


/// Returns the Superpower associated with a power character.
string SuperHero::getHeroPower() const {
           if(heroPowerChar == 'a') {
        return "Armour";
    } else if(heroPowerChar == 'b') {
        return "Boy wonder";
    } else if(heroPowerChar == 'c') {
        return "Crime fighter";
    } else if(heroPowerChar == 'e') {
        return "Electric";
    } else if(heroPowerChar == 'f') {
        return "Flying";
    } else if(heroPowerChar == 'g') {
        return "Giant";
    } else if(heroPowerChar == 'h') {
        return "Hacker";
    } else if(heroPowerChar == 'i') {
        return "Ice";
    } else if(heroPowerChar == 'j') {
        return "Jedi";
    } else if(heroPowerChar == 'k') {
        return "Killer";
    } else if(heroPowerChar == 'n') {
        return "None";
    } else if(heroPowerChar == 'r') {
        return "Rich";
    } else if(heroPowerChar == 's') {
        return "Strong";
    } else if(heroPowerChar == 't') {
        return "Totally not Batman";
    } else {
        return "Weakling";
    }
}

/// Overloads the >> operator so one can read in a SuperHero from the console.
istream& operator >> (istream& in, SuperHero& hero) {
    string nameStr;
    cout << "Enter name:  ";
    cin >> ws;
    getline(cin, nameStr);

    hero.strToCharArr(nameStr);

    cout << "Enter age:   ";
    cin >> hero.heroAge;
    cout << "Enter Power: ";
    cin >> hero.heroPowerChar;
    return in;
}

/// Overloads the << operator so one can write out a SuperHero to the console.
ostream& operator << (ostream& out, const SuperHero& hero) {
    cout << hero.heroName << " (" << hero.heroAge << "): " << hero.getHeroPower() << endl;
    return out;
}

/// Overloads the >> operator so one can read in a SuperHero from a file.
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

/// Overloads the << operator so one can write out a SuperHero to a file.
ofstream& operator << (ofstream& fout, const SuperHero& hero) {
    fout.open("SuperHeros.dat", ios::binary|ios::app);
    fout.write((char*)(&hero), sizeof(SuperHero));
    fout.close();
    return fout;
}
