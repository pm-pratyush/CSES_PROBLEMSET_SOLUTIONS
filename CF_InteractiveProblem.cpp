/* Pratyush Mohanty */
// C. Guess The Tree
// https://codeforces.com/contest/2001/problem/C

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*---------------------------------------------------------------------------------------------------------------------------*/

#define INF 1e18
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

#define ll long long
#define ull unsigned long long

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll

/*---------------------------------------------------------------------------------------------------------------------------*/


ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
 
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} 
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} 

/*---------------------------------------------------------------------------------------------------------------------------*/

#define print_pair(p) cout << p.ff << " " << p.ss << endl;
#define print_set(s) for (auto x : s) cout << x << " "; cout << endl;
#define print_map(m) for (auto x : m) cout << x.ff << " " << x.ss << endl;

#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;
#define print_arr(a, n) for (int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;

#define print_mat(mat, m, n) for (int i = 0; i < m; ++i) { for (int j = 0; j < n; ++j) cout << mat[i][j] << " "; cout << endl; }
#define print_graph(g, n) for (int i = 0; i < n; ++i) { cout << i << " : "; for (auto x : g[i]) cout << x << " "; cout << endl; }

/*---------------------------------------------------------------------------------------------------------------------------*/

bool isaParentOfb(int a, int b, int n, int parent[])
{
    if (a == b)
        return true;
    if (parent[b] == -1)
        return false;
    return isaParentOfb(a, parent[b], n, parent);
}
void find(int a, int b, int n, int parent[])
{
    cout << "? " << a << " " << b << endl;
    cout << flush;

    int m;
    cin >> m;

    if (a == m)
        parent[b] = a;
    
    if (!isaParentOfb(a, m, n, parent))
        find(a, m, n, parent);
    if (!isaParentOfb(m, b, n, parent))
        find(m, b, n, parent);
}
void solveTC()
{
    int n;
    cin >> n;

    int parent[n + 1];
    for(int i = 0; i < n + 1; i++)
        parent[i] = -1;
    
    // Finding the edges from 1... and from here recursively
    for (int i = 2; i < n + 1; i++)
    {
        if (!isaParentOfb(1, i, n, parent))
            find(1, i, n, parent);
    }

    // Printing the n - 1 edges
    cout << "! ";
    for (int i = 2; i < n + 1; i++)
        cout << i << " " << parent[i] << " ";
    cout << endl;
}

/*---------------------------------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        #ifdef DEBUG
            cout << "Case #" << i + 1 << ": " << endl;
        #endif

        solveTC();
    }
    return 0;
}
