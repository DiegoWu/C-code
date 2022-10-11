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
		int n, x; 
		cin>>n>>x;
		vector<int> v(2*n); 
		for(int i=0; i<2*n; i++){
			cin>>v[i];
		}
		string ans= "Yes";
		sort(v.begin(), v.end()); 
		for(int i=0; i<n; i++){
			if(v[i+n]< v[i]+x) ans= "No"; 
		}
		cout<<ans<<endl;
	}
}
