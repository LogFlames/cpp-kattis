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
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

void fast() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

void solve() {

}

int main() {
    fast();

    int board[16], m;
    rep(i,0,16) cin >> board[i];
    cin >> m;

    if (m == 0) {
        rep(i,0,4) {
            rep(x,2,5) per(j,x,1) {
                if (board[i * 4 + j] > 0) {
                    if (board[i * 4 + j - 1] == 0) {
                        board[i * 4 + j - 1] = board[i * 4 + j];
                        board[i * 4 + j] = 0;
                    } else if (board[i * 4 + j - 1] == board[i * 4 + j]) {
                        board[i * 4 + j - 1] *= -2;
                        board[i * 4 + j] = 0;
                    }
                }
            }
        }
    } else if (m == 2) {
        rep(i,0,4) {
            per(x,3,0) rep(j,x,3) {
                if (board[i * 4 + j] > 0) {
                    if (board[i * 4 + j + 1] == 0) {
                        board[i * 4 + j + 1] = board[i * 4 + j];
                        board[i * 4 + j] = 0;
                    } else if (board[i * 4 + j + 1] == board[i * 4 + j]) {
                        board[i * 4 + j + 1] *= -2;
                        board[i * 4 + j] = 0;
                    }
                }
            }
        }
    } else if (m == 1) {
        rep(j,0,4) {
            rep(x,2,5) per(i,x,1) {
                if (board[i * 4 + j] > 0) {
                    if (board[(i - 1) * 4 + j] == 0) {
                        board[(i - 1) * 4 + j] = board[i * 4 + j];
                        board[i * 4 + j] = 0;
                    } else if (board[(i - 1) * 4 + j] == board[i * 4 + j]) {
                        board[(i - 1) * 4 + j] *= -2;
                        board[i * 4 + j] = 0;
                    }
                }
            }
        }
    } else if (m == 3) {
        rep(j,0,4) {
            per(x,3,0) rep(i,x,3) {
                if (board[i * 4 + j] > 0) {
                    if (board[(i + 1) * 4 + j] == 0) {
                        board[(i + 1) * 4 + j] = board[i * 4 + j];
                        board[i * 4 + j] = 0;
                    } else if (board[(i + 1) * 4 + j] == board[i * 4 + j]) {
                        board[(i + 1) * 4 + j] *= -2;
                        board[i * 4 + j] = 0;
                    }
                }
            }
        }
    }

    rep(i,0,4) {
        rep(j,0,4) {
            cout << abs(board[i * 4 + j]) << " ";
        }
        cout << endl;
    }

    return 0;
}
