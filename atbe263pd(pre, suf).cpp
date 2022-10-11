#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 9223372036854775807
#define mod 998244353
#define mp make_pair

using namespace std;
using P= pair<ll, int>; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	ll n, l, r, ans= 0; 
	cin>>n>>l>>r;  
	vector<ll> v(n+1), suf(n+2), prx(n+2); 
	for(int i=1; i<n+1; i++) cin>>v[i], ans+= v[i]; 

	for(int i=1; i<n+1; i++)
		prx[i]= min(prx[i-1]+ v[i], l*i); 
	
	for(int i=n; i>0; i--)
		suf[i]= min(suf[i+1]+ v[i], (n-i+1)*r); 
	
	for(int i=0; i<=n; i++)
		ans= min(suf[i+1]+prx[i], ans); 
	
	cout<<ans<<endl;

 }
