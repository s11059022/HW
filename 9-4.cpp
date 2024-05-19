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

    // 去掉最後一個多餘的空格
   string result = oss.str();
    if (!result.empty()) {
        result.pop_back();
    }

    input = result;
}

int main() {
   string input;
   
   cout << "請輸入一個字串: (標點需和單詞分開)";
   getline(cin, input);

    replaceFourLetterWords(input);

    cout << "修改後的字串: " << input << std::endl;

    return 0;
}