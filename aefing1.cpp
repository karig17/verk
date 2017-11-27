#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream fin;
  char c;
  fin.open("bla.txt");
  if (fin.is_open()) {
    for (int i = 0; i < 10; i++) {
      fin >> c;
      cout << c << endl;
    }
    fin.close();
  }

}
