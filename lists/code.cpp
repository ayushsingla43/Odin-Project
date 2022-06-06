/*
    Name: Divyansh Rai
    Codeforces Handle: thunderclap615

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// class segment_tree{
// private:
 
//   vector<int> tree;
//   int size;
//   int n;
// public:
//   void build( vector<int> v)
// {   
//     this->n = v.size();
//     this->size = 2*n;
//     tree.assign(size,0);
 
//     for (int i=0; i<n; i++)   
//         tree[n+i] = v[i];
     
//     // merge option
//     for (int i = n - 1; i > 0; --i)    
//         tree[i] = min(tree[i<<1] ,tree[i<<1 | 1]);   
// }
 
// void update(int p, int value)
// {
//     // set value at position p
//     tree[p+n] = value;
//     p = p+n;
     
//     // move upward and update parents
//     for (int i=p; i > 1; i >>= 1)
//         tree[i>>1] = min(tree[i] , tree[i^1]);
// }
 
// int query(int l, int r)
// {   
//     r++;
//     // [l,r] l is in 0 index
//     int res = INT_MAX;
//     // if(r==l)
//       // return tree[n+l];
     
//     // loop to find the sum in the range
//     for (l += n, r += n; l < r; l >>= 1, r >>= 1)
//     {
//         if (l&1)
//             res = min(tree[l++],res);
     
//         if (r&1)
//             res = min(tree[--r],res);
//     }
     
//     return res;
// }
 
 
//};
// pii dfs(vec<veci> &a,string &s,int node){
//     pii p={1,0};
//     // cout<<p.ff<<p.ss<<endl;
//     if(s[node]=='W') p={0,1};
//     for(auto x:a[node]) {
//         pii q=dfs(a,s,x);
//         p.ff+=q.ff;p.ss+=q.ss;
//     }
//     if(p.ff==p.ss) ans++;
//     return p;
// }
////////////////////////////////////////////////////////////////////////////////
using namespace __gnu_pbds;
const int N=2e6 +1;

  
#define ll          long long int
#define vi          vector<ll>
#define pii         pair<ll,ll>
#define vpii        vector<pii>
#define fo(i,n)     for(ll i=0;i<n;i++)
#define foin        fo(i,n)
#define take(n)     ll n; cin>>n;
#define el          "\n"
#define elif        else if
#define takevect(a,n) vector<ll> a(n);fo(zen,n) cin>>a[zen];
#define print(x)       cout << x <<el;
#define debug       cout<<"hello"<<el;
#define tree_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ll a[N];
bool f[N];
const ll INF = (ll)(1e9);
ll ans =INT_FAST64_MAX;
#define mod 1000000007

using namespace std;
bool is_prime(ll n)
{
	if(n<=3) return true;
	if(n%2==0 || n%3==0) return true;
	ll i{5};
	while(i*i <= n)
	{
		if(n%i==0 || n%(i+2)==0) return false;
		i += 6;
	}
	return true;
}




void solve(){
    
	take(n);
	vpii v;
	fo(i,n){
		take(a);take(b);
		v.push_back(make_pair(a,b));

	}

	
	vector<vector<ll>> dp(n+1,vector<ll>(3,0));
	dp[0][0]=0;dp[0][1]=1;dp[0][2]=0;
	if( (n>1 && (v[0].first+v[0].second)<v[1].first) or n==1 ){
		dp[1][2]=1;
	}
	for(ll i=1;i<n;i++){
		if((v[i].first-v[i].second)>v[i-1].first){
			if((v[i-1].first+v[i-1].second)<(v[i].first-v[i].second)){
				dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+1;
			}
			else{
				dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
			}
		}
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		if(i==n or (v[i].first+v[i].second)<v[i+1].first){
			dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+1;
		}
	}
	print(max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));

} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ll t{1};
    //cin >> t;
    while (t--)
 
        solve();

    return 0;
}