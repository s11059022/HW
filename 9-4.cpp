#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void replaceFourLetterWords(string& input) {
    istringstream iss(input);
    ostringstream oss;
    string word;

    while (iss >> word) {
        if (word.length() == 4) {
            word = "love";
        }
        oss << word << ' ';
    }

    // �h���̫�@�Ӧh�l���Ů�
   string result = oss.str();
    if (!result.empty()) {
        result.pop_back();
    }

    input = result;
}

int main() {
   string input;
   
   cout << "�п�J�@�Ӧr��: (���I�ݩM������})";
   getline(cin, input);

    replaceFourLetterWords(input);

    cout << "�ק�᪺�r��: " << input << std::endl;

    return 0;
}