#include <bits/stdc++.h>
using namespace std;

#define DEBUG

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a - 1; i >= (b); --i)
#define trav(a, x) for(auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#define deb(x) cerr << #x << " = " << (x) << endl
#define deb2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debv(a) cerr << #a << ": [ "; trav(i,(a)) { cout << i << " "; } cout << "]" << endl
#else
#define deb(x)
#define deb2(x, y)
#define debv(a)
#endif

#define prt(a) cout << a << endl
#define gtz(a, b) ((a) > 0 ? (b) : 0)
#define amin(a, b) a = min((a), (b))
#define amax(a, b) a = max((a), (b))
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

void solve() {

}

int main() {
    fast();

    int n,k;
    cin >> n >> k;
    vi c(n);
    rep(i,0,n) { cin >> c[i]; }

    vvi lu(k + 1);
    rep(i,0,n) {
        lu[c[i]].pb(i);
    }

    ll mt = LLONG_MAX - 1;
    trav(s,lu[1]) {
        ll t = 1;
        int in = s;
        int v = 1;
        while (v < k) {
            bool found = false;
            trav(j,lu[v + 1]) {
                if (j > in) {
                    t += (ll)(j - in);
                    in = j;
                    v++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                t += (ll)(n - (in - lu[v + 1][0]));
                in = lu[v + 1][0];
                v++;
            }
        }

        amin(mt, t);
    }

    prt(mt);

    return 0;
}
