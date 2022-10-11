#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		vector<int> v(n), v1(n); 
		bool ck= 0; 
		for(int i=0; i<n; i++) cin>>v[i]; 
		for(int i=0; i<n; i++) cin>>v1[i]; 

		for(int i=0; i<n; i++) if(v[i]> v1[i]) ck= 1; 
		//cout<<ck<<endl;
		for(int i=0; i<n-1; i++){
			if(v1[i]> v1[i+1]+1) {if(v[i]!= v1[i]) ck= 1;} 
			else v[i]= v1[i]; 
		}

		if(v1[n-1]+1< v1[0]&& v[0]!= v1[0]) ck= 1; 
		cout<<(!ck? "YES": "NO")<<endl; 
	}
}
