#include<bits/stdc++.h>
#define ll long long 
#define maxn 505
#define maxx 1e18
using namespace std;
int n, m; 

ll adj[maxn][maxn]= {0, 0}, pa[maxn]= {-1};
vector<bool> vis(maxn); 

bool reachable(){
	for(int i=0; i<maxn; i++) vis[i]= 0; 
	queue<ll> q; 
	q.push(1); 
	vis[1]= 1; 
	while(!q.empty()){
		int node= q.front(); 

		for(int i=1; i<=n; i++){
			if(!adj[node][i]|| vis[i]) continue; 
			vis[i]= 1; 
			q.push(i); 
			pa[i]= node; 
		}
		q.pop(); 
	}
	return vis[n]; 
}
int main(){

	cin>>n>>m; 

	for(int i=0; i<m; i++){
		ll a, b, c; 
		cin>>a>>b>>c; 
		adj[a][b]+= c; 
	}
	ll maxflow= 0; 
	while(reachable()){
		ll flow= maxx; 

		for(int i=n; i!= 1; i= pa[i]){
			flow= min(flow, adj[pa[i]][i]); 
			//cout<<i<<endl;
		}
		maxflow+= flow; 
		for(int i=n; i!= 1; i= pa[i]){
			adj[pa[i]][i]-= flow; 
			adj[i][pa[i]]+= flow;
			cout<<i<<endl; 
		}
		cout<<"asfd"<<endl;
	}
	cout<<maxflow<<endl;

}