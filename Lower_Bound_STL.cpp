#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    vector<int> v;

    cin >> N;
    cin.ignore();

    string s;
    getline(cin, s);
    stringstream ss(s);

    for (int i = 0; i < N; i++) {
        int tmp;
        char ch;
        ss >> tmp;
        v.push_back(tmp);
    }

    cin >> N;
    vector<int>::iterator it;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        it = lower_bound(v.begin(), v.end(), tmp);
        if (*it == tmp)
            cout << "Yes " << it - v.begin() + 1 << endl;
        else
            cout << "No " << it - v.begin() + 1 << endl;
    }

    return 0;
}