#include "vectorfunctions.h"

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
typedef vector<vector<int>> vvi;
typedef vector<long> vl;
typedef vector<vector<long>> vvl;
typedef vector<pair<int, int>> vpii;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

void backwards(vector<int>& vec) {
    rep(i,0,sz(vec) / 2) {
        int temp = vec[i];
        vec[i] = vec[sz(vec) - i - 1];
        vec[sz(vec) - i - 1] = temp;
    }
}

vector<int> everyOther(const vector<int>& vec) {
    vi nv;
    rep(i,0,sz(vec)) {
        if (i % 2 == 0) {
            nv.pb(vec[i]);
        }
    }
    return nv;
}

int smallest(const vector<int>& vec) {
    int sma = -1;
    trav(i,vec) {
        if (i < sma || sma == -1) sma = i;
    }

    return sma;
}

int sum(const vector<int>& vec) {
    int su = 0;
    trav(i,vec) su += i;
    return su;
}

int veryOdd(const vector<int>& vec) {
    int su = 0;
    rep(i,0,sz(vec)) {
        if (i % 2 == 1 && vec[i] % 2 == 1) {
            su++;
        }
    }
    return su;
}

// int main() {
//     fast();

//     return 0;
// }
