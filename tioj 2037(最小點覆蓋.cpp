#include<bits/stdc++.h> 
#define ll long long 
#define maxn 100005
using namespace std; 
vector<vector<int> > g(maxn); 
vector<int> rec; 
int pa[maxn], vis[maxn]; 
bool dfs(int node){
  rec.push_back(node); 
  
  for(auto x: g[node]){
    if(!pa[x]) {
      pa[x]= node; 
      return 1; 

    }
    else if(vis[x]) continue; 
    else{
       vis[x]= 1;
       rec.push_back(x); 
      if(dfs(pa[x])) {
        pa[x]= node; 
        return 1; 
      }
    }
  }
  return 0; 
}
void solve(){
  int p, q, k, ans= 0; 
  cin>>p>>q>>k; 
  for(int i=0; i<maxn; i++) g[i].clear(); 
  memset(pa, 0, sizeof(pa)); 
  memset(vis, 0, sizeof(vis)); 
  rec.clear(); 
  for(int i=0; i<k; i++){
    int a, b;  
    cin>>a>>b; 
    g[a].push_back(b); 
  }

  for(int i=1; i<maxn; i++){

    if(dfs(i)) ans++;  
    for(int i=0; i<rec.size(); i++) vis[rec[i]]= 0; 
    rec.clear(); 
  }
  cout<<ans<<endl;
}


int main(){
    int t; 
    cin>>t; 
    while(t--){
      solve(); 
    }
}