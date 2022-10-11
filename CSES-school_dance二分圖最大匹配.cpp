#include<bits/stdc++.h> 
#define ll long long 
#define maxn 505
using namespace std; 
vector<vector<int> > arr(maxn); 
vector<int> pa(maxn); 
int vis[maxn]; 

bool dfs(int node){
  for(auto ele: arr[node]){
    if(!pa[ele]) {
      pa[ele]= node; 
      return 1; 
    }

    else if(vis[ele]) continue; 

    else{
      vis[ele]= 1; 
      if(dfs(pa[ele])){
        pa[ele]= node; 
        return 1; 
      }
    }
  }
  return 0; 
}

int main(){
  int n, m, k; 
  cin>>n>>m>>k; 
  for(int i=0; i<k; i++){
    int a, b; 
    cin>>a>>b; 
    arr[a].push_back(b); 

  }
  int cnt= 0; 

  for(int i=1; i<=n; i++){
    memset(vis, 0, sizeof(vis)); 
    if(dfs(i)) cnt++; 
  }
  cout<<cnt<<endl;
  for(int i=1; i<=m; i++){
    if(pa[i]) cout<<pa[i]<<" "<<i<<endl;
  }
  
  return 0; 
}