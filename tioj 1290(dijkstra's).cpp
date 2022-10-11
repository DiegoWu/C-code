#include<iostream>
#include<vector>
#include<cmath> 
#include<cstring> 
#include<set> 
#define maxn 1001
#define INF 1000000000
#define ll long long 
using namespace std;
int n, m; 
int main(){
	while(cin>>n>>m){
		ll ans= INF; 
		int st, ed, a, b, c, node, cnt= 0; 
		cin>>st>>ed; 
		int g[maxn][maxn]; 
		vector<int> vis(maxn); 
		set<int>s; 
		vector<ll> dis(maxn); 
		for(int i=0; i<n+1; i++){
			dis[i]= INF; 
			for(int j=0; j<n+1; j++) g[i][j]= -1; 
		}
		for(int i=0; i<m; i++){
			cin>>a>>b>>c; 
			if(g[a][b]!= -1) {
				g[b][a]= min(c, g[b][a]); 
				g[a][b]= g[b][a];  
			}
			else{
			 	g[a][b]= c; 
			 	g[b][a]= c; 
		 	}
		 	s.insert(a); 
		 	s.insert(b); 
		}
		dis[st]= 0;
	 	if(st==ed) cout<<0<<endl;
	 	else{
	 		node= st;
	 		while(cnt<s.size()){
	 			ans= INF; 
	 			for(int i=1; i<n+1; i++){
	 				if(vis[i]) continue; 
	 				if(dis[i]< ans){
	 					node= i; 
	 					ans= dis[i]; 
	 				}
	 			} 
	 			vis[node]= 1; 
	 			for(int i=1; i<n+1; i++){
	 				if(g[node][i]== -1||vis[i]) continue; 
	 				if(dis[i]> g[node][i]+dis[node]) dis[i]= g[node][i]+dis[node]; 	
	 			}
	 			cnt++; 
	 		}
	 		if(dis[ed]== INF) cout<<"He is very hot"<<endl;
	 		else cout<<dis[ed]<<endl;
		}
	}
	return 0; 
}