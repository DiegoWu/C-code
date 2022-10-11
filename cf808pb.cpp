#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t; 
	while(t--){
		
		int n;
		ll l, r; 
		cin>>n>>l>>r; 
		
		vector<ll> v; 
		
		v.push_back(l); 
		ll z; 
		string ans= "YES"; 
		for(ll i=2; i<=n; i++){
			z= l/i; 
			ll x; 
			if(l%i== 0) x= i*z; 
			else x= i*z+i; 
			if(x> r){
				ans= "NO"; 
				break; 
			}
			v.push_back(x); 
		}
		if(ans=="NO") cout<<ans<<endl;
		else{
			cout<<ans<<endl;
			for(int i=0; i<n; i++) cout<<v[i]<<" "; 
			cout<<endl;
		}
	}

}
