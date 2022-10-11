#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<bitset> 
#define ll long long 
#define INF 100000000000
#define mod 998244353
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, ans= (1<<30)-1, a; 
		cin>>n; 
		 
		for(int i=0; i<n; i++){
			cin>>a; 
			if(a!= i) ans&=  a; 
		}
		
		cout<<ans<<endl; 
	}
	return 0; 
}
