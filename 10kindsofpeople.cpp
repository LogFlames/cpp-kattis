#include <bits/stdc++.h>
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
#define amin(a, b) a = min((a), (b))
#define amax(a, b) b = max((a), (b))
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

int root(vi& points, int a) {
    if (points[a] == a) {
        return a;
    }

    int ans = root(points, points[a]);
    points[a] = ans;
    return ans;
}

void join(vi& points, int a, int b) {
    int ar = root(points, a);
    int br = root(points, b);

    points[a] = min(ar, br);
    points[b] = min(ar, br);
}

bool same(vi& points, int a, int b) {
    int ar = root(points, a);
    int br = root(points, b);

    return ar == br;
}

int main() {
    fast();

    int r, c;
    cin >> r >> c;

    vi grid(r * c);
    rep(i,0,r) {
        string s;
        cin >> s;
        rep(j,0,c) {
            grid[i * c + j] = s[j] - '0';
        }
    }

    vi points(r * c);
    rep(i,0,r*c) {
        points[i] = i;
    }

    rep(i,0,r) {
        rep(j,0,c) {
            if (j < c - 1 && grid[i * c + j] == grid[i * c + j + 1]) {
                join(points, i * c + j, i * c + j + 1);
            }
            if (j > 0 && grid[i * c + j] == grid[i * c + j - 1]) {
                join(points, i * c + j, i * c + j - 1);
            }
            if (i < r - 1 && grid[i * c + j] == grid[(i + 1) * c + j]) {
                join(points, i * c + j, (i + 1) * c + j);
            }
            if (i > 0 && grid[i * c + j] == grid[(i - 1) * c + j]) {
                join(points, i * c + j, (i - 1) * c + j);
            }
        }
    }

    /*
    rep(i,0,r) {
        rep(j,0,c) {
            root(points, i * c + j);
            cout << points[i * c + j] << " ";
        }
        cout << endl;
    }
    */

    int Q;
    cin >> Q;

    rep(i,0,Q) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        y1--;
        x2--;
        y2--;

        if (same(points, y1 * c + x1, y2 * c + x2)) {
            if (grid[y1 * c + x1] == 0) {
                prt("binary");
            } else {
                prt("decimal");
            }
        } else {
            prt("neither");
        }
    }

    return 0;
}
