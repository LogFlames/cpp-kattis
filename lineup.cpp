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

int sign(int a) {
    return (a == 0 ? 0 : (a > 0 ? 1 : -1));
}

int order(string a, string b) {
    rep(i,0,min(sz(a), sz(b))) {
        if (a[i] == b[i]) continue;
        return sign(a[i] - b[i]);
    }
    return sign(sz(a) - sz(b));
}

int main() {
    fast();

    int n;
    cin >> n;
    vector<string> names(n);

    int ord = 0;
    cin >> names[0];
    rep(i,1,n) {
        cin >> names[i];
        int o = order(names[i], names[i - 1]);
        if (ord == 0) {
            ord = o;
        } else {
            if (ord != o) {
                cout << "NEITHER" << endl;
                return 0;
            }
        }
    }

    if (ord == -1) {
        cout << "DECREASING" << endl;
    } else if (ord == 1) {
        cout << "INCREASING" << endl;
    }

    return 0;
}
