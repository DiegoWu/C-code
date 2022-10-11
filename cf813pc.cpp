#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		vector<int> v(n), rec; 
		map<int, int> m; 
		vector<vector<int> > pos(n+1);  
		for(int i=0; i<n; i++) {
			cin>>v[i]; 
			m[v[i]]= v[i]; 
			pos[v[i]].push_back(i); 
		}
		int ini= 0; 
		set<int> st; 
		for(int i=1; i<n; i++){
			st.insert(v[i-1]);
			if(pos[v[i]][0]< ini) m[v[i]]= 0; 
			if(m[v[i]]< m[v[i-1]]){
				ini= i; 
				rec.push_back(st.size()); 
			}
		}
		if(rec.size()==0) cout<<0<<endl;
		else cout<<rec[rec.size()-1]<<endl;
	}
}