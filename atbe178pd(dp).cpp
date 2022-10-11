#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mp make_pair
#define mod 1000000007
using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	ll s;
	cin>>s; 
	vector<ll>dp(s+1); 
	dp[0]= 1; 
	for(int i=3; i<=s; i++){
		for(int coin= 3; coin<=i; coin++){
			dp[i]+= dp[i-coin]; 
			dp[i]%= mod; 
		}
	}
	cout<<dp[s]<<endl;
}
