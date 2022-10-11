#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mp make_pair
 
using namespace std; 

ll ans[maxn]; 
vector<vector<int> > g(maxn); 
map<int, ll> m; 
ll c= 0; 
void dfs(int node, int p){

	for(auto i: g[node]){
		if(i== p) continue; 
		c+= m[i]; 
		dfs(i, node); 
		ans[i]= c; 
		c-= m[i]; 
	}
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, a, b; 
	cin>>n>>q; 

	for(int i=0; i<n-1; i++){

		cin>>a>>b; 
		g[a].push_back(b);
		g[b].push_back(a);  
	}
	while(q--){
		cin>>a>>b; 
		m[a]+= b; 
	}
	c+= m[1]; 
	dfs(1, 1);
	ans[1]= m[1]; 
	for(int i=1; i<n+1; i++) cout<<ans[i]<<" ";  
}
