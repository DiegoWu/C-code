#include<bits/stdc++.h> 
#define maxn 505 
using namespace std; 

int n, m; 

int adj[maxn][maxn], pa[maxn], oadj[maxn][maxn];
bool vis[maxn]; 
vector<vector<int> > rec(maxn); 
bool reachable(){

	memset(vis, 0, sizeof(vis)); 
	
	

	queue<int> q; 
	q.push(1), vis[1]= 1;   

	while(!q.empty()){

		int node= q.front();

		for(int i=1; i<=n; i++){
			if(vis[i]|| !adj[node][i]) continue; 
		
			q.push(i), vis[i]= 1, pa[i]= node; 
		}
		q.pop(); 
	}
	return vis[n]; 
}
int main(){
	cin>>n>>m; 

	for(int i=0; i<m; i++){
		int a, b; 
		cin>>a>>b; 
		adj[a][b]= 1;
		adj[b][a]= 1; 
		oadj[a][b]= 1, oadj[b][a]= 1; 
	}
	int cnt= 0;
	
	
	vector<int> ans; 
	while(reachable()){
		cnt++; 
		//cout<<"start: "<<endl;
		for(int i=n; i!= 1; i= pa[i]) {
			//cout<<pa[i]<<" "<<i<<endl;
			adj[pa[i]][i]= 0, adj[i][pa[i]]= 1; 
		}

	}

	cout<<cnt<<endl;
	reachable(); 

	for(int i=1; i<=n-1; i++){
		for(int j=1; j<=n; j++){
			if(vis[i]&& !vis[j]&& oadj[i][j]) ans.push_back(i), ans.push_back(j); 
		}
	}
	int i= 0; 
	while(i< cnt*2) {
		
		cout<<ans[i]<<" "<<ans[i+1]; 
		cout<<endl;
		i+= 2; 
	}
	
}