#include<iostream>
#include<vector> 
#include<algorithm>
#define maxn 100000
using namespace std; 
vector<pair<int, int > >g[maxn+1]; 
vector<int> vis(maxn+1); 
int ans= 0, v= 0;
void dfs(int node, int w){
	if(vis[node]) 
		return; 
	vis[node]= 1; 
	if(w> ans) {
		ans= w; 
		v= node; 
	}
	for(int i=0; i<g[node].size(); i++){
		w+= g[node][i].second; 
		dfs(g[node][i].first, w);
		w-= g[node][i].second; 
	}
}
int main(){
	int n; 
	while(cin>>n&&n){ 
		int a, b, c, nn, z=0;  
		cin>>a>>b>>c; 
		nn= a; 
		g[a].push_back(make_pair(b, c)); 
		g[b].push_back(make_pair(a, c));  
		for(int i=1; i<n-1; i++){
			cin>>a>>b>>c; 
			g[a].push_back(make_pair(b, c)); 
			g[b].push_back(make_pair(a, c)); 
		}
		dfs(nn, 0); 
		for(int i=0; i<maxn+1; i++)
			vis[i]= 0; 
		ans= 0; 
		dfs(v, 0); 
		for(int i=0; i<maxn+1; i++) {
			g[i].clear(); 
			vis[i]= 0; 
		}
		cout<<ans<<endl;
	  	v= 0, ans= 0; 
	}
}