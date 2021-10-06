#include<bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define input(a) int a; cin>>a
#define vi vector<int>
#define pb push_back
#define pf push_front
#define emp emplace
#define mp make_pair
#define map map<int,int>
#define deq deque<int>
#define tests int t; cin >> t; while(t--)
#define FOR(a,b) for(int i = a;i<b;i++)
using namespace std;

int dp[2000][2000];

int solve(int egg, int floor){
  
    // Base Condition
    if(egg == 1 || floor == 0 || floor == 1) {
        return floor;    
    }
    
    int ans = INT_MAX;
    if(dp[egg][floor] != -1) {
        return dp[egg][floor];
    }
    for(int k=1; k<=floor; k++) {
        int temp = 1 + max(solve(egg-1, k-1), solve(egg, floor - k));
        ans = min(ans, temp);
    }
    return dp[egg][floor] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int egg, floor;
    cin >> egg >> floor;
    cout<<solve(egg, floor);
    return 0;
}
