#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#include<cmath> 
#include<map>
#include<bitset> 
#include<queue> 
#define ll long long 
#define maxn 300005
#define mp make_pair

using namespace std; 
vector<int> g[maxn]; 

int ch[maxn], dp[maxn]; 
void dfs(int node, int p){
	int s= 0;
	
	ch[node]= 1, dp[node]= 0; 	
	for(auto i: g[node]){
		
		if(i== p) continue; 
		dfs(i, node);
		s+= dp[i], ch[node]+= ch[i]; 

	}
	for(auto i: g[node]){
		if(i== p) continue; 
		dp[node]= max(dp[node], s-dp[i]+ch[i]-1); 
	}

}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<maxn; i++) g[i].clear(); 
		int n; 
		cin>>n;
		n--; 
		while(n--){
			int a, b;
			cin>>a>>b;
			g[a].push_back(b); 
			g[b].push_back(a); 

		}

		dfs(1, 0); 
		cout<<dp[1]<<endl;
	}
}

