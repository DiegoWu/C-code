#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std;
int sz, md= 0, ch= 0, ex= 0; 
vector<vector<int> > g(maxn); 
vector<int> vis(maxn); 
int p[maxn]; 
map<int, int> m; 
string ans= "YES";
vector<string> res; 
void dfs(int node){
	
	if(m[node]){
		sz--; 
	
		if(g[node].size()>=3) ex= 1; 
		else md= 1; 
		m[node]= 0; 
	}
	
	for(int i=0; i<g[node].size(); i++){
		if(vis[g[node][i]]) continue; 
		vis[g[node][i]]= 1; 
		dfs(g[node][i]); 
		cout<<node<<endl;
		cout<<"md: "<<md<<endl;
		if(md&& sz>0){
			if(ch) ans= "NO"; 
			ch= 1; 
		}
		if(ex){
			md= 1, ex= 0; 
		}
	}


}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q; 
	cin>>n; 
	//p[1]= 1; 
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
	//	p[b]= a; 
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	cin>>q; 
	for(int i=0; i<q; i++){
		int k, c, the= -1;
		cin>>k; 
		sz= k; 
		for(int j=0; j<k; j++){
			cin>>c; 
			m[c]= 1; 
			if(g[c].size()==1) the= c; 
			//cout<<g[c].size()<<endl;
		}
		if(the!= -1) dfs(the); 
		else dfs(c); 
		m.clear(); 
		res.push_back(ans); 
		//cout<<the<<endl;
		cout<<ans<<endl;
		ans= "YES"; 
		vis.clear(); 
	}
	for(int i=0; i<q; i++) cout<<res[i]<<endl;
	
}
