#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#define maxn 501
using namespace std; 

multiset<int> g[maxn]; 
vector<int> ans; 
void dfs(int node){
	while(g[node].size()){
		int x= *g[node].begin(); 
		g[node].erase(g[node].find(x)); 
		g[x].erase(g[x].find(node)); 
		dfs(x); 
	}
	ans.push_back(node); 
}
int main(){
	int m, a, b, s;
	while(cin>>m&&m){
		cin>>a>>b; 
		g[a].insert(b);
		g[b].insert(a); 
		s= a; 
		for(int i= 1; i<m; i++){
			cin>>a>>b;
			g[a].insert(b); 
			g[b].insert(a); 
		}
		for(int i=1; i<maxn; i++){
			if(g[i].size()%2){
				s= i; 
				break;
			}
		}
		dfs(s); 
		reverse(ans.begin(), ans.end()); 
		for(int i=0; i<ans.size(); i++) cout<<ans[i]<<endl; 
		cout<<endl;
		ans.clear(); 
		for(int i=0; i<maxn; i++) g[i].clear(); 
	}
}