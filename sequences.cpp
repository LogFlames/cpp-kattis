#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

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
#define MOD 1000000007

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

ll mod_power(ll a, ll b, ll m) {
    ll res = 1ll;

    a %= m;

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b = b >> 1;
    }

    return res;
}

/*
2^(antal ? till vänster om) * ((antal hopp till höger - antal fasta ettor) * 2^(antal ? till höger) - antal ettor i alla binära tall med längd av antal ? till höger) - summera för varje 1 och ?

l = 1
n | a
1   1  | 2^0 * 1
2   4  | 2^1 * 2
3   12 | 2^2 * 3
4   32 | 2^3 * 4
n      | 2^(n - 1) * n


??10?

00100 | 2
00101 | 1
01100 | 4
01101 | 2
10100 | 5
10101 | 3
11100 | 6
11101 | 3
26

2^0 * ((4 - 1) * 2^(2) - 4) | 8
2^1 * ((3 - 1) * 2^(1) - 1) | 6
2^2 * ((2)     * 2^(1) - 1) | 12


 */

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

int main() {
    fast();

    string s;
    getline(cin, s);

    vi ones_acc(sz(s), 0), ques_acc(sz(s), 0);
    rep(i,0,sz(s)) {
        ones_acc[i] = gtz(i, ones_acc[i - 1]) + (s[i] == '1' ? 1 : 0);
        ques_acc[i] = gtz(i, ques_acc[i - 1]) + (s[i] == '?' ? 1 : 0);
    }

    ll sum = 0ll;

    rep(i,0,sz(s)) {
        if (s[i] == '0') {
            continue;
        }
        ll left = mod_power(2, gtz(i, ques_acc[i - 1]), MOD);
        ll jump = (sz(s) - i - 1);
        ll on = (ones_acc[sz(s) - 1] - ones_acc[i]);
        ll right = (ques_acc[sz(s) - 1] - ques_acc[i]);
        ll oiq = (mod_power(2, right - 1, MOD) * right) % MOD;

        deb2(left, jump);
        deb2(on, right);
        deb(oiq);

        deb(mod_power(2, right, MOD));

        ll to_add = left * (((jump - on) * mod_power(2, right, MOD) - oiq) % MOD) % MOD;
        sum = (sum + to_add) % MOD;
    }

    prt(sum);

    return 0;
}
