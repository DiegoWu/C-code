#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		ll ans= 0; 
		cin>>n; 
		vector<int> v(n);
		for(int i=0; i<n; i++) cin>>v[i]; 
		sort(v.begin(), v.end()); 
		for(int i=1; i<n; i++) ans+= v[i]-v[0]; 
		cout<<ans<<endl;
	}
}
