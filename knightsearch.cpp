#include <bits/stdc++.h>
#include <queue>
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
#define mmap multimap
#define un_mmap unordered_multimap
#define un_set unordered_set
#define mset multiset
#define un_mset unordered_multiset
#define F first
#define S second

#define PI 3.1415926535897932

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

int n;
string s;

bool bfs(int p, int d) {
    if (d == 10) return true;
    string tar = "ICPCASIASG";
    rep(i,-2,3) {
        if (i == 0) continue;
        if ((p / n) + i < 0 || (p / n) + i >= n) continue;
        rep(j,-2,3) {
            if (j == 0) continue;
            if ((p % n) + j < 0 || (p % n) + j >= n) continue;

            if (s[p + i * n + j] == tar[d]) {
                if (bfs(p + i * n + j, d + 1)) return true;
            }
        }
    }

    return false;
}

int main() {
    fast();

    cin >> n;
    cin >> s;

    rep(i,0,n*n) {
        if (s[i] == 'I' && bfs(i, 1)) {
            prt("YES");
            return 0;
        }
    }

    prt("NO");

    return 0;
}
