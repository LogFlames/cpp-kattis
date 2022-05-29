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

vi dp(100001, -1);

int solve(int n) {
    if (dp[n] != -1) {
        return dp[n];
    }

    int mo = 100001;

    string s = to_string(n);

    int in = sz(s);
    for (int i = 10; i <= n; i *= 10)
    {
        in--;
        if (s[in] == '0') {
            continue;
        }
        
        int a = solve(n % i);
        int b = solve(n / i);

        amin(mo, a + b);
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int f1 = solve(i);
            int f2 = solve(n / i);

            amin(mo, f1 + f2);
        }
    }

    rep(i,1,n / 2 + 1) {
        int a = solve(i);
        int b = solve(n - i);

        amin(mo, a + b);
    }

    dp[n] = mo;
    return mo;
}

int main() {
    fast();

    dp[0] = 100001;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 5;
    dp[7] = 7;
    dp[8] = 6;
    dp[9] = 6;
    dp[10] = 7;

    /*
    int n;
    cin >> n;
    prt(solve(n));
    */

    cout << "Solving..." << endl;
    solve(100000);

    cout << "Writing python file..." << endl;
    ofstream py_file("1sforall.py");

    py_file << "a = '";
    rep(i,1,100001) {
        py_file << (char)(dp[i] + 65);
    }

    py_file << "'" << endl;
    py_file << "print(ord(a[int(input()) - 1]) - 65)" << endl;
    py_file.close();
    cout << "Python file written" << endl;


    return 0;
}
