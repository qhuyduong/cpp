#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        /* Enter your code here */
        cout << setw(0) << nouppercase;
        cout << "0x" << hex << (long)A << endl;
        cout << right << setfill('_') << setw(15) << fixed << setprecision(2)
             << showpos << B << endl;
        cout << noshowpos << scientific << uppercase << setprecision(9) << C
             << endl;
    }

    return 0;
}