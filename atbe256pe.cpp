#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mxx 10000000000
#define mp make_pair

using namespace std;
vector<vector<pair<int, ll> > > g(maxn);
vector<int> vis(maxn); 
vector<int> rec; 
ll temp= mxx; 
bool ck= 0, ck1= 0; 
map<int, int> bck, r; 
void dfs(int node){
	if(ck) return; 
	if(vis[node]) {
		ck1= 1; 
		return; 
	}
	//cout<<"node: "<<node<<endl; 
	if(!r[node]) rec.push_back(node);
	r[node]= 1; 
	bck[node]++; 
	for(const auto [i, c]: g[node]){
		 //if(ck) break; 
		if(bck[i]==2){
			ck= 1; 
			continue;  
		}
		bck[i]++;
		dfs(i); 
		if(ck){ 
			//cout<<i<<endl;
			if(bck[node]>=1) {
				temp= min(temp, c); 
				//cout<<c<<endl;
			}
		}
	}
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	cin>>n; 
	vector<ll> x(n), c(n); 
	for(int i=0; i<n; i++) cin>>x[i];
	for(int i=0; i<n; i++) cin>>c[i]; 
	for(int i=0; i<n; i++){
		g[i+1].push_back(mp(x[i], c[i])); 
	}
	
	ll ans= 0; 
	for(int i=0; i<n; i++){
		if(vis[i+1]) continue; 
		dfs(i+1); 
		vis[i+1]= 1; 
		for(auto j: rec) vis[j]= 1; 
		if(ck1) continue; 
		ans+= temp; 
		temp= mxx; 
		ck= 0; 
		bck.clear(); 
		r.clear(); 
		rec.clear(); 
		//cout<<"i: "<<i<<endl;
	}

	cout<<ans<<endl;
	return 0; 
	
}
