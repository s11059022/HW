#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> m;
    int mark = 0;
    cout << "Enter the marks obtained by students: ";
    while (true) {
        cin >> mark;
        if (mark < 0) {
            break;
        }
        m.push_back(mark);
    }
    int maxMark = m[0];
    for (unsigned int i = 1; i < m.size(); i++) {
        if (m[i] > maxMark) {
            maxMark = m[i];
        }
    }
    if (maxMark % 10 != 0) {
        maxMark = ((maxMark / 10) + 1) * 10;
    }
    //for(unsigned int i = 0; i<m.size(); i++){
        //m[i] = m[i]/5;
    //}
    cout << endl;
    cout << "Printing Histogram: ";
    cout << endl;
    for (unsigned int i = 0; i < m.size(); i++) {
        cout << m[i] << ":      ";
        for (int j = 1; j <= m[i] / 5; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}