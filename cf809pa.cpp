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
		int n, m; 
		cin>>n>>m; 
		vector<int> v(n);
		for(int i=0; i<n; i++) cin>>v[i];
		sort(v.begin(), v.end());
		map<int, int> vis; 
		for(int i=0; i<n; i++){
			int x= v[i]-1, b= m-v[i]; 
			if(vis[min(x, b)]==1&& vis[max(x, b)]==1) continue; 
			if(vis[min(x, b)]==1) vis[max(x, b)]= 1; 
			else vis[min(x, b)]= 1;  
		}
		for(int i=0; i<m; i++){
			if(vis[i]==1) cout<<'A'; 
			else cout<<'B'; 
		}
		cout<<endl;
	}
}


