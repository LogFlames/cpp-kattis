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

int main() {
    fast();

    int n;
    cin >> n;

    vector<set<int>> gr(n);
    vb isl(n, false);
    rep(i,0,n) {
        int m;
        cin >> m;
        gr[i] = set<int>();
        rep(j,0,m) {
            int nei;
            cin >> nei;
            gr[i].emplace(nei);
        }
        if (m == 1) isl[i] = true;
    }

    set<int> hlfs;

    rep(i,0,n) {
        trav(j,gr[i]) {
            if (isl[j]) {
                hlfs.emplace(i);
                break;
            }
        }
    }

    int st = 0;
    while (sz(hlfs) > 0) {
        set<int> nhlfs;
        trav(h,hlfs) {
            trav(n,gr[h]) {
                if (isl[n]) {
                    gr[h].erase(n);
                    break;
                }
            }

            if (sz(gr[h]) == 1) {
                isl[h] = true;
                nhlfs.emplace(*gr[h].begin());
            } else if (sz(gr[h]) > 1) {
                trav(j,gr[h]) {
                    if (isl[j]) {
                        nhlfs.emplace(h);
                        break;
                    }
                }
            }
        }

        hlfs = nhlfs;
        st++;
    }
    prt(st);


    return 0;
}
