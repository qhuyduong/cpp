#include <iostream>
#include <vector>
using namespace std;

#define toStr(str) #str
#define io(v) cin >> v
#define FUNCTION(name, op)                                                     \
    void name(int& current, int candidate) {                                   \
        if (candidate op current) {                                            \
            current = candidate;                                               \
        }                                                                      \
    }
#define INF 10000000
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    foreach (v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach (v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}