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
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

int pow2roundup(int x) {
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

int query(vi& a, int trees, int l, int r) {
    int sl = 0, sr = 0;
    for(l += trees, r += trees; l < r; l >>= 1, r >>= 1) {
        if (l % 2) sl = (sl + a[l++]);
        if (r % 2) sr = (sr + a[--r]);
    }
    return (sl + sr);
}

void update(vi& a, int trees, int i, int v) {
    int ind = i + trees;
    a[ind] = v;
    while (ind > 1) {
        ind /= 2;
        a[ind] = a[ind * 2] + a[ind * 2 + 1];
    }
}


int find_i(vi& a, int trees, int am) {
    am++;
    int i = 1;

    while (i < trees) {
        if (a[2 * i] == 0) {
            i = i * 2 + 1;
        } else if (a[i * 2 + 1] == 0) {
            i = i * 2;
        } else {
            if (a[i * 2] >= am) {
                i = i * 2;
            } else {
                am -= a[i * 2];
                i = i * 2 + 1;
            }
        }
    }

    return i - trees;
}

int lower_bound(vi& a, int trees, int d, map<int,int> uncompress, int al, int ar) {
    while (al < ar) {
        int am = (al + ar) / 2;
        int i = find_i(a, trees, am);

        if (uncompress[i] < d) al = am + 1;
        else ar = am;
    }

    return al;
}

int upper_bound(vi& a, int trees, int d, map<int,int> uncompress, int al, int ar) {
    while (al < ar) {
        int am = (al + ar) / 2;
        int i = find_i(a, trees, am);

        if (uncompress[i] <= d) al = am + 1;
        else ar = am;
    }

    return al;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi N(n);
    rep(i, 0, n) cin >> N[i];

    sort(all(N));

    map<int, int> compress;
    map<int, int> uncompress;
    int a = 0;
    compress[N[0]] = 0;
    rep(i, 1, n) {
        if (compress[N[i]]) continue;
        compress[N[i]] = a;
        uncompress[a] = N[i];
        a++;
    }

    int trees = pow2roundup(a);
    vi tree(2 * trees, 0);

    rep(i, 0, n) {
        tree[trees + compress[N[i]]]++;
    }
    for (int i = trees - 1; i > 0; i--) {
        tree[i] = (tree[i * 2] + tree[i * 2 + 1]);
    }

    rep(i, 0, q) {
        int T, D;
        cin >> T >> D;
        if (T == 1) { // discard problems strictly harder than
            int i = upper_bound(tree, trees, D, uncompress, 0, tree[1]);
            if (i == tree[1]) {
                cout << -1 << endl;
            } else {
                int ii = find_i(tree, trees, i);
                cout << uncompress[ii] << endl;
                update(tree, trees, ii, tree[ii + trees] - 1);
                // remove
            }
        } else if (T == 2) { // discard problems not harder than
            int i = lower_bound(tree, trees, D, uncompress, 0, tree[1]);
            int ii = find_i(tree, trees, i);

            if (i < tree[1] && uncompress[ii] == D) {
                cout << uncompress[ii] << endl;
                update(tree, trees, ii, tree[ii + trees] - 1);
                // remove
            } else {
                if (i == 0) {
                    cout << -1 << endl;
                } else {
                    int ii = find_i(tree, trees, i - 1);
                    cout << uncompress[ii] << endl;
                    update(tree, trees, ii, tree[ii + trees] - 1);
                    // remove
                }
            }
        }
    }
}

int main() {
    fast();

    solve();

    return 0;
}
