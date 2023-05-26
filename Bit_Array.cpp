#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, S, P, Q;

    cin >> N >> S >> P >> Q;

    unsigned int current, prev;
    prev = S % (1LL << 31);
    int count = 1;
    for (int i = 1; i < N; i++) {
        current = (prev * P + Q) % (1LL << 31);
        if (current != prev)
            count++;
        prev = current;
    }
    cout << count << endl;

    return 0;
}