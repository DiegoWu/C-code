#include<bits/stdc++.h> 
#define ll long long 
#define maxn 51
#define mp make_pair 
using namespace std; 
vector<string>g(maxn); 
int n, m; 
int dirx[4]= {1, -1, 0, 0}, diry[4]= {0, 0, 1, -1}, diax[4]= {1, 1, -1, -1}, diay[4]= {-1, 1, -1, 1}; 
int vis[51][51]; 
int cnt= 1; 
vector<pair<int, int> > temp; 
vector<vector<pair<int, int> > > rec(2500); 
void dfs(int x, int y){
    
	if(cnt>= 4) return; 
	
	for(int i=0; i<4; i++){
		 
		if(x+dirx[i]<0|| y+diry[i]<0|| x+dirx[i]>=n|| y+diry[i]>= m) continue; 
		if(vis[x+dirx[i]][y+diry[i]]) continue; 
		 
		if(g[x+dirx[i]][y+diry[i]]=='*') {
			cnt++; 
			vis[x+dirx[i]][y+diry[i]]= 1; 
			temp.push_back(mp(x+dirx[i], y+diry[i])); 
			dfs(x+dirx[i], y+diry[i]); 
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	//cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		bool f= 0; 
		cin>>n>>m; 
		for(int i=0; i<maxn; i++) for(int j=0; j<maxn; j++) vis[i][j]= 0; 
		for(int i=0; i<2500; i++) rec[i].clear(); 
		temp.clear(); 
		for(int i=0; i<n; i++) cin>>g[i]; 
		int cc= 0; 

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cnt= 1; 

				if(g[i][j]=='*'){
					if(vis[i][j] ) continue; 
					
					vis[i][j]= 1; 
					dfs(i, j); 
					if(cnt== 3){
						int gg=0, gg1= 0; 
						for(const auto [a, b]: temp){
							if(a== i) gg++; 
							if(b== j) gg1++; 
						}
						if(gg==2|| gg1== 2) {
							f= 1;
							break; 
						}
						else{
							rec[cc]= temp;
							rec[cc].push_back(mp(i, j)); 
							cc++; 
						}
					
					}
					else{
						f= 1; 
						break; 
					}
				}
				
				temp.clear(); 
			}
		}
		if(f) cout<<"NO"<<endl;

		else{
			
			bool flag= 0;
			for(int i=0; i<cc; i++){
				for(int j=0; j<4; j++){
					for(const auto [a, b]: rec[i]){
						if(a+diax[j]< 0|| b+ diay[j]< 0|| a+ diax[j]>=n|| b+diay[j]>=m) continue; 
						
						if(g[a+diax[j]][b+ diay[j]]== '*'){
							int flg=0; 
							for(const auto[c, d]: rec[i]){
								if(a+diax[j]== c&& b+diay[j]== d){
									continue; 
								}
								flg++; 
							}
							if(flg==3) flag= 1; 
						}
					}
				}
			}

			if(flag== 1) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
}
