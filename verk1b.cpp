#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout;
    string input;

    fout.open("textOutput.txt", ios::app);
    do {
        getline(cin, input);

        if(input[0] != '\\') {
            fout << input << endl;

        }

    }while(input[0] != '\\');
    return 0;
}
