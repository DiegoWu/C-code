#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 
vector<int> viss(maxn); 
vector<int> g[maxn];
map<int, int> m, vis; 
int trv= 0, ck= 0; 
string ans= "Yes"; 
void dfs(int node, int p, int pp){
	if(ck==1) return;
	viss[node] =1;
	for(int i=0; i<g[node].size(); i++){

		if(g[node][i]== pp) continue; 
		else if(g[node][i]==p){
			trv++;
			if(trv%2==1) ans= "No";
			ck= 1; 
			break;
		}
		else {
			trv++; 
			dfs(g[node][i], p, node); 
		}
	}

}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		
		int n;
		cin>>n; 
		for(int i=0; i<n+1; i++){ 
			viss[i]= 0; 
			g[i].clear();  
		}
		m.clear(), vis.clear(); 
	
		for(int i=0; i<n; i++){
			int a, b; 
			cin>>a>>b;
			if(ans=="No") continue; 
			if(m[a]){
				g[vis[a]].push_back(i+1); 
				g[i+1].push_back(vis[a]); 
			}
			if(m[b]){
				g[vis[b]].push_back(i+1); 
				g[i+1].push_back(vis[b]); 
			}
			m[a]++, m[b]++, vis[a]= i+1, vis[b]= i+1; 
			if(m[a]> 2|| m[b]> 2|| a==b) ans= "No"; 

        }
		if(ans!= "No"){
			for(int i=0; i<n; i++){
				trv= 0; 
				if(viss[i+1]) continue; 
				ck= 0;
				dfs(i+1, i+1, i+1); 
			}
		}
		cout<<ans<<endl;
		ans= "Yes"; 
	}
	return 0; 
}
