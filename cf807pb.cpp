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
		cin>>n; 
		ll ans= 0; 
		vector<int> v(n);
		for(int i=0; i<n; i++) cin>>v[i]; 
		int rec= n-1; 
		for(int i=0; i<n; i++){
			if(v[i]!= 0){
				rec= i; 
				break; 
			}
		}
		if(rec==n-1) cout<<0<<endl;
		else{
			for(int i=rec; i<n-1; i++){
				if(v[i]==0) ans++; 
				else ans+= v[i]; 
			}
			cout<<ans<<endl;
		}
	}
}
