
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mod 1000000007
#define int long long
#define REP(i, m, n) for (int i = m; i < n; i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int, int>
#define mp make_pair
#define vii vector<ii>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
// const int n=2e5+5;
// int power(int a,int b){
//     if(b==0)return 1;
//     if(a==0)return 0;
//     if(a==1)return 1;
//     int ans=1;
//     a=a%mod;
//     while(b>0){
//         if(b&1){
//             ans=ans*a%mod;
//         }
//         b>>=1;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
// int fact[n]; int inv[n];
// void once(){
//     fact[0]=1;
//     REP(i,1,n){
//         fact[i]=fact[i-1]*i%mod;
//     }
//     inv[0]=1;
//     REP(i,1,n){
//         inv[i]=power(fact[i],mod-2)%mod;
//     }
// }
// int ncr(int n,int r){
//     int ans=fact[n]%mod;
//     ans*=inv[r]%mod;
//     ans%=mod;
//     ans*=inv[n-r]%mod;
//     ans%=mod;
//     return ans;
// }
// int addmod(int x,int y){
//     return (x+y)%mod;
// }
 
// int multmod(int x,int y){
//     return (x*y)%mod;
// }
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄
*/
void bfs(int start,vector<vector<int>>&graph,int n,vector<int>&visited){
    queue<int>q;
    set<ii>check;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int curr=q.front();q.pop();
        for(auto i:graph[curr]){
            if(check.find({curr,i})==check.end())
            {cout<<i<<" "<<curr<<endl;check.insert({i,curr});}
            if(!visited[i]){q.push(i);visited[i]=1;}
        }
    }
}
void solve(int xyz)
{
   int n,m;cin>>n>>m;vector<vector<int>>graph(n+1);
   REP(i,0,m){int x,y;cin>>x>>y;graph[x].pb(y);graph[y].pb(x);}
    vector<int>visited(n+1,0);
    REP(i,1,n+1)if(!visited[i])
    bfs(i,graph,n,visited);
}
 
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //   int t;cin>>t;
    REP(xyz, 0, 1)
    {
        solve(xyz);
    }
}
