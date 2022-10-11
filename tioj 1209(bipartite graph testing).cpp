#include<iostream>
#include<vector>
#include<algorithm> 
#define maxn 40001
using namespace std; 
int n, m, cc= 0; 

vector<int > graph[maxn];
vector<int> Node(maxn); 
vector<int>vis(maxn);
void  dfs(int node, int val){
	
	if(Node[node]== val) cc= 1; 
	if(vis[node]) return; 
	vis[node]= 1;
	for(int i=0; i<graph[node].size(); i++){
 
		if(!vis[graph[node][i]]) Node[graph[node][i]]= (Node[node]+1)%2; 

		dfs(graph[node][i], Node[node]); 
	}
	
}
void solve(){
	while(cin>>n>>m&& n){
		for(int i=0; i<m; i++){
			int c, d; 
			cin>>c>>d; 
			Node[c]= -1;
			Node[d]= -1; 
			graph[c].push_back(d);
			graph[d].push_back(c); 
		}
		Node[1]= 1; 
		dfs(1, -1);
		if(cc)  cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		for(int i=0; i<maxn; i++) vis[i]= 0;
		for(int i=0; i<maxn; i++){
			Node[i]= 0;
			graph[i].clear();
		}
		cc= 0; 
	}
}

int main(){

	solve(); 
	return 0; 
}