#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a - 1; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debv(a) cout << #a << ": [ "; rep(i,0,sz(a)) { cout << a[i] << " "; } cout << "]" << endl;
#define pb push_back
#define un_map unordered_map
#define un_set unordered_set

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long> vl;
typedef vector<vector<long>> vvl;
typedef vector<bool> vb;
typedef vector<bool> vvb;
typedef vector<pair<int, int>> vpii;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

void solve(int a, int b) {
    if (a + b == 13) cout << "Never speak again." << endl;
    else if (a > b) cout << "To the convention." << endl;
    else if (a < b) cout << "Left beehind." << endl;
    else cout << "Undecided." << endl;
}

int main() {
    fast();

    int x, y;
    while (true) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        solve(x, y);
    }

    return 0;
}
