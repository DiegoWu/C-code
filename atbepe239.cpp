#include<bits/stdc++.h> 
#define ll long long 
#define maxn 100005
#define mp make_pair 
using namespace std; 
vector<vector<int> > g(maxn); 
vector<vector<int> > val(maxn); 
vector<int> rec(maxn);

void dfs(int node, int pp){
	
	for(auto x: g[node]){
		if(x== pp) continue; 
		dfs(x, node); 
		sort(val[node].begin(), val[node].end());
		if(val[x].size()==1){
			if(val[node].size()>=20){
				if(rec[x]<= val[node][0]) continue; 
				val[node][0]= rec[x]; 
			}
			else val[node].push_back(rec[x]); 
		}
		else{
			int cnt= 0, p= val[x].size()-1, p1= val[node].size()-1;  
			vector<int> temp; 

			sort(val[x].begin(), val[x].end()); 
			
			while(cnt<=20){
				if(p==-1&&p1==-1) break; 

				if(p==-1|| val[x][p]< val[node][p1]){
					temp.push_back(val[node][p1]); 
					p1--; 
				}
				else if(p1== -1|| val[x][p]>= val[node][p1]){
					temp.push_back(val[x][p]); 
					p--; 
				}
				cnt++; 
				p= max(-1, p), p1= max(-1, p1);
				
			}
			val[node]= temp; 
        }
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int n, q, a, b; 
	cin>>n>>q; 

	for(int i=1; i<n+1; i++) {
		cin>>rec[i]; 
		val[i].push_back(rec[i]); 
	}

	for(int i=0; i<n-1; i++){
		cin>>a>>b; 
		g[b].push_back(a); 
		g[a].push_back(b);
	}
    
	dfs(1, 1); 
	
	for(int i=0; i<q; i++){
		int m, k;
		cin>>m>>k;
		sort(val[m].rbegin(), val[m].rend());
		cout<<val[m][k-1]<<endl;
	}
	return 0;
}
