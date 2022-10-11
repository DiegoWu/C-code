#include<iostream>
#include<algorithm> 
#include<vector> 
#define maxn 10001
#define M 1000001
// Kruskal algorithm
using namespace std; 
vector<int> p(maxn); 
struct E{int u, v, w; }edge[M]; 
bool cmp(E a, E b){return a.w< b.w;}
int find(int x){
	if(p[x]== x) return x; 
	return p[x]= find(p[x]); 
}
void solve(){
	int n, m;
	while(cin>>n>>m&&n&&m){ 
		for(int i=1; i<n+1; i++) p[i]= i; 
		for(int i=0; i<m ;i++){
			int a, b, c; 
			cin>>a>>b>>c; 
			edge[i]= (E){a, b, c};  
		}
		int ans= 0; 
		sort(edge, edge+m, cmp);
		for(int i=0; i<m; i++){
			if(find(edge[i].u)== find(edge[i].v)) continue; 
			ans+= edge[i].w; 
			p[find(edge[i].u)]= find(edge[i].v); 
			n--; 
		}
		if(n> 1) cout<<-1<<endl;
		else cout<<ans<<endl;
		//for(int i=0; i<M; i++) edge[i]= (E){0, 0, 0}; 
	}
}
int main(){
	solve();
	return 0;
}
