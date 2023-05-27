#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
int reorder(int* a, int n, int start) {
    int i = start;

    while (i < n - 1) {
        if (a[i] == i + 1)
            start = i;
        if (a[i] > a[i + 1]) {
            if (a[i] - 1 - i > 2) {
                return -1;
            }
            break;
        }

        i++;
    }

    if (i == n - 1) {
        return 0;
    }

    swap(a[i], a[i + 1]);
    int tmp = reorder(a, n, start);
    if (tmp == -1)
        return -1;

    return tmp + 1;
}

void minimumBribes(vector<int> q) {
    int bribes = reorder(&q[0], q.size(), 0);

    if (bribes == -1)
        cout << "Too chaotic" << endl;
    else
        cout << bribes << endl;
}

int main() {
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item;
            cin >> q_item;
            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}