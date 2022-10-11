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
		int n, q, pos; 
		cin>>n>>q; 
		vector<int> v(n+1);
		map<int, vector<int> > m; 
		for(int i=1; i<=n; i++) cin>>v[i]; 
		int mx= v[1], mpos= 1; 
	
		for(int i=1; i<=n; i++){
			if(v[i]== n){
				pos= i; 
				break; 
			}
			if(v[i]> mx){
				m[i].push_back(i-1), mx= v[i], mpos= i; 
			}
			else if(v[i]< mx){
				m[mpos].push_back(i-1); 
			}
		}
		while(q--){
			int a, b; 
			cin>>a>>b; 
			if(b< a-1) cout<<0<<endl;

			else if(a== pos){
				if(pos==1|| pos==2) cout<<b<<endl;
				else cout<<b-(pos-2)<<endl;
			}
			else if(a> pos) cout<<0<<endl;
			else{
				//for(int i=0; i<m[a].size(); i++) cout<<m[a][i]<<endl;
				int x=  upper_bound(m[a].begin(), m[a].end(), b)-m[a].begin(); 
				cout<<x<<endl;
			}
		}
	}
}
