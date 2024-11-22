#include "arithmeticfunctions.h"

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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long> vl;
typedef vector<vector<long> > vvl;
typedef vector<pair<int, int> > vpii;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

int cube(int x) {
    return x * x * x;
}

int max(int x, int y) {
    return (x > y ? x : y);
}

int difference(int x, int y) {
    return x - y;
}


// int main() {
//     fast();

//     return 0;
// }
