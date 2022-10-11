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
	cout.tie(NULL); 
	int t;
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		map<int, int> m, vis; 
		vector<int> dp(n); 
		for(int i=0; i<n; i++) dp[i]= -1; 
		int x= sqrt(2*n-2); 
	
		for(int i= x; i>=0; i--){
			for(int j=n-1; j>=0; j--){
				if(i*i< j|| i*i-j> n-1) continue; 
				if(vis[i*i-j]) continue; 
				if(dp[j]== -1) dp[j]= i*i-j, vis[i*i-j]= 1;  
			}
		}
		int f= 0; 
		for(int i=0; i<n; i++) {
			if(m[dp[i]]>1|| dp[i]==-1) f= -1;
			m[dp[i]]++;  
		}
		if(f==-1) cout<<f<<endl;
		else{
			for(int i=0; i<n; i++) cout<<dp[i]<<" "; 
			cout<<endl;
		}
	}

 }
