#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 100005
#define mod 998244353
#define mp make_pair

using namespace std;
struct p{
	int st, end, idx; 
}; 
bool cmp(p a, p b){
	if(a.st== b.st) return a.end< b.end; 
	return a.st< b.st; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		string txt; 
		int n; 
		cin>>txt>>n; 
		vector<string> v(n);
		bool f= 0; 
		for(int i=0; i<n; i++) {
			cin>>v[i];
			if(v[i].size()<= txt.size()) f= 1;  
		}
		vector<p> rec; 
		if(f==0) cout<<-1<<endl;
		else{
			int ccc= 0; 
			for(int i=0; i<n; i++){
				for(int j=0; j<txt.size(); j++){
					bool ck= 0; 
					if(txt[j]== v[i][0]){
						for(int z= 0; z<v[i].size(); z++){
							if(txt[j+z]!= v[i][z]) {
								ck= 1; 
								break; 
							}
						}
						if(ck) continue; 
						rec.push_back((p){j, j+v[i].size()-1, i}); 
						
						ck= 0; 
					}
				}
			}
			vector<vector<int> > g(maxn);  
			if(rec.size()==0){
				cout<<-1<<endl;
			}
			else{
				bool fff= 0; 
				sort(rec.begin(), rec.end(), cmp);
				for(auto [a, b, c]: rec){
					if(a== 0&& b== txt.size()-1) {
						fff= 1; 
						cout<<1<<endl;
						cout<<c+1<<" "<<a+1<<endl;
						break; 
					}
				}
				if(!fff){
					int ini= -1;  
					for(int i=0; i<rec.size()-1; i++){

						for(int j=i+1; j<rec.size(); j++){
							if(rec[i+1].st== 0) continue; 
	 
							if(rec[i].end+1>= rec[j].st&& rec[j].end> rec[i].end) {
								if(rec[i].st==0&& ini==-1) ini= i;
								g[i].push_back(j); 
							}
						}
					}
					
					vector<int> vis(maxn); 
					for(int i=0; i<maxn; i++) vis[i]= -1; 
					queue<pair<int, int> > q;
					map<int, int> ans; 
					if(ini==-1) cout<<-1<<endl;
					else{
						q.push(mp(ini, 1)); 
						
						vis[ini]= 0; 
						ans[rec[ini].end]= 1; 
						int need=-1, use; 
						while(!q.empty()){
							if(g.size()==0) break; 
							int node= q.front().first, cnt= q.front().second;  
							q.pop(); 
							for(const auto x: g[node]){
								if(vis[x]!= -1) continue; 
								vis[x]= node; 
								ans[rec[x].end]= 1; 
								if(rec[x].end== txt.size()-1) use = x; 
								q.push(mp(x, cnt+1)); 
							}
							if(ans[txt.size()-1]==1){
								need= q.front().second; 
								break; 
							}
						}
						if(need!= -1){
							int gg= 1; 
							vector<pair<int, int> > final; 
							final.push_back(mp(rec[use].idx+1,rec[use].st+1 )); 
							
							while(true){
								if(use==ini) break; 
								gg++; 
								final.push_back(mp(rec[vis[use]].idx+1, rec[vis[use]].st+1));
								use= vis[use];
							}
							cout<<gg<<endl;
							for(int i=0; i<final.size(); i++) cout<<final[i].first<<" "<<final[i].second<<endl;
						}
						else cout<<-1<<endl;
					}
				}	
			}
		}
	}
}
