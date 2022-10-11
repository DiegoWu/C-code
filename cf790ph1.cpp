#include<iostream>
#include<vector>
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
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(v[j]<= v[i]) ans++; 
			}
		}
		cout<<ans<<endl;
	}
}
