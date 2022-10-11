#include<bits/stdc++.h>

#define ll long long 
#define maxn  100000000
#define mn 2005
#define mp make_pair
 
using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y; 
	cin>>n>>x>>y;
	vector<int> dis(n); 
	vector<int> ans(n); 
	vector<vector<pair<int, int> > > adj(mn);  

	for(int i=0; i<n-1; i++){
		adj[i].push_back(mp(i+1, 1)), adj[i+1].push_back(mp(i, 1)); 
	}
	adj[x-1].push_back(mp(y-1, 1)), adj[y-1].push_back(mp(x-1, 1)); 

	using P= pair<int, int>; 
	priority_queue<P, vector<P>, greater<P> > pq; 

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) dis[j]= maxn; 
		dis[i]= 0; 
		pq.push(mp(i, 0));  

		while(!pq.empty()){

			const auto [v, d]= pq.top(); 
			pq.pop(); 
			if(dis[v]!= d) continue; 

			for(const auto[vt, c]: adj[v]){

				if(dis[vt]> dis[v]+ c){
					dis[vt]= dis[v]+c; 
					pq.push(mp(vt, dis[vt])); 
				}
			}
		}
		for(int j=1; j<n; j++){
			if(j<=i) continue; 
			ans[dis[j]]++; 
		}
	}

	for(int i=1; i<n; i++)cout<<ans[i]<<endl;
}

