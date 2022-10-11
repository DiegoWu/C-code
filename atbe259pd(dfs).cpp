#include<bits/stdc++.h>

#define ld long double
#define maxn 3005
#define mod 1000000007
#define mp make_pair

using namespace std; 
ld x, y, xx1, yy1; 
int start, eend; 
vector<vector<int> > g(maxn);
bool xx(ld x1,ld y1,ld r1, ld x2,ld y2,ld r2) { 
	ld s; 
	s = sqrt(((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1))); 
	if(s<=r2+r1&&s>=abs(r2-r1)) return true; 
	else return false; 
}
struct p{
	ld x, y, c; 
}; 
string ans= "No"; 
vector<int> vis(maxn); 
void dfs(int node){
	if(node== start){
		ans= "Yes"; 
		return; 
	}
	if(vis[node]==1) return; 
	vis[node]= 1; 
	for(int i=0; i<g[node].size(); i++){
		if(!vis[g[node][i]]) dfs(g[node][i]); 
	}
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin>>n; 
	
	cin>>x>>y>>xx1>>yy1; 
	vector<p> v(maxn);
    
	for(int i=0; i<n; i++){
		ld a, b, c; 
		cin>>a>>b>>c; 
		if(sqrt((x-a)*(x-a)+(y-b)*(y-b))== c) start= i; 
		if(sqrt((xx1-a)*(xx1-a)+(yy1-b)*(yy1-b))== c) eend= i;
		v[i].x= a, v[i].y= b, v[i].c= c; 
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(xx(v[i].x, v[i].y, v[i].c, v[j].x, v[j].y, v[j].c)== true){
				//cout<<i<<" "<<j<<endl;
				g[i].push_back(j), g[j].push_back(i); 
			}
		}
	}
    
	dfs(eend); 
	if(start==eend) ans= "Yes"; 
	cout<<ans<<endl;
}

