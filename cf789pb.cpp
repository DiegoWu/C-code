#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<bitset> 
#include<map>
#define ll long long 
#define INF 1000000001
#define mod 998244353
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, ans= 0, cnt= 1; string s;
		cin>>n>>s; 
		
		for(int i=0; i<n; i+=2){
			if(s[i]!= s[i+1]) ans++; 
		}
		cout<<ans<<endl;
	}
	
}
