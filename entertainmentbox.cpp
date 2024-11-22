#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <set>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a - 1; i >= (b); --i)
#define trav(a, x) for(auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define deb(x) cout << #x << " = " << (x) << endl
#define deb2(x, y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debv(a) cout << #a << ": [ "; trav(i,(a)) { cout << i << " "; } cout << "]" << endl
#define prt(a) cout << a << endl
#define gtz(a, b) ((a) > 0 ? (b) : 0)
#define pb push_back
#define un_map unordered_map
#define un_set unordered_set
#define F first
#define S second

#define PI 3.1415926535897932

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

int main() {
    fast();

    int n, k;
    cin >> n >> k;

    vpii shows(n);
    rep(i,0,n) {
        cin >> shows[i].F >> shows[i].S;
    }

    int re = 0;

    sort(all(shows), [](pii a, pii b) { return a.S < b.S; });

    multiset<int> be;
    rep(i,0,k) be.emplace(1);

    trav(sh,shows) {
        multiset<int>::iterator it = be.lower_bound(-sh.F);
        if (it == be.end()) continue;

        be.erase(it);
        be.emplace(-sh.S);
        re++;
    }

    prt(re);

    return 0;
}
