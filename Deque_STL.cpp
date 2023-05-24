#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

void printKMax(int arr[], int n, int k) {
    // Write your code here.
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        for (auto it = dq.begin(); it != dq.end(); it++) {
            if (dq.empty())
                break;
            if ((i - *it) > k - 1)
                dq.erase(it);
        }
        while (!dq.empty() && arr[*(dq.end() - 1)] < arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            cout << arr[*dq.begin()] << " ";
    }
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}