#include<bits/stdc++.h>

#define ll long long 
#define maxn 1000006
#define mod 1000000007
#define llmax 92233720368547758
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll dp[maxn]; 
	dp[1]= 1, dp[2]= 2, dp[3]= 4, dp[4]= 8, dp[5]= 16, dp[6]= 32; 
	int n; 
	cin>>n; 
	for(int i=7; i<=n; i++){
		dp[i]= dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6]; 
		dp[i]%= mod;  
	}
	cout<<dp[n]<<endl;
	
}
