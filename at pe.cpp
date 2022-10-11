#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 10000
using namespace std; 
vector<int> parent(maxn+1); 
vector<pair<int, int> >rec; 
int find(int f){
	//cout<<f<<" "<<parent[f]<<endl;
	if(parent[f]== f) return f;
	return parent[f]= find(parent[f]); 
}
void Union(int fi, int se){
	int z= find(fi), x= find(se);
	parent[max(fi, se)]= min(z, x); 
	//cout<<"hi"<<parent[max(fi, se)]<<endl;
}
vector<int> vis(maxn+1); 
void solve(){
	int n, m;
	while(cin>>n>>m){ 
		for(int i=0; i<m; i++){
			int a, b; 
			cin>>a>>b; 
			if(vis[a]&& vis[b]){
				parent[a]= min(parent[a], min(a, b));
				parent[b]= min(parent[b], min(a, b)); 
			}
			else if(vis[a]&& !vis[b]){
				parent[a]= min(parent[a], min(a, b));
				parent[b]= min(a, b);
				vis[b]= 1; 
			}
			else if(vis[b]&& !vis[a]) {
				parent[b]= min(parent[b], min(a, b));  
				parent[a]= min(a, b);
				vis[a]= 1; 
			}
			else{
				vis[a]= 1; 
				vis[b]= 1; 
				parent[min(a, b)]= min(a, b); 
				parent[max(a, b)]= min(a, b); 
			}	
			rec.push_back(make_pair(a, b));
		}
		int k; 
		cin>>k; 
		for(int i=0; i<rec.size()-1; i++){
			for(int j=i+1; j<rec.size(); j++){
				if(rec[i].first== rec[j].first|| rec[i].second== rec[j].first||  rec[i].first== rec[j].second||rec[i].second== rec[j].second){
						
					Union(parent[rec[i].first], parent[rec[j].first]); 
				}
			}
		}
		cout<<find(parent[k])<<endl;
		parent.clear(); 
		rec.clear();
		vis.clear();
	}
}

int main(){

	solve(); 
	return 0; 
}