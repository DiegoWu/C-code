#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<sstream>
#define ll long long 
#define INF 100000000000
#define mod 998244353
using namespace std; 

int main(){
	
	int n;
	ll ans= 0;  
	cin>>n; 
	ll dp[2][11]; 
	 
	dp[1][10]= 0; 
	for(int i=0; i<10; i++) dp[1][i]= 1; 
	
	for(int i=1; i<n; i++){
		dp[i%2][0]= 0, dp[i%2][10]= 0; 
		for(int j=1; j<10; j++){
			dp[(i+1)%2][j]= dp[i%2][j-1]+dp[i%2][j]+dp[i%2][j+1]; 
			dp[(i+1)%2][j]%= mod; 
		}
	}
	for(int i=1; i<10; i++) {ans+= dp[n%2][i], ans%= mod;}
	cout<<ans<<endl; 
}