#include<bits/stdc++.h>

#define ll long long 
#define maxn 100005
#define mod 1000000007
#define mp make_pair


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; 
	cin>>n>>m; 
	vector<vector<int> > v(maxn);
	for(int i=0; i<m; i++){
		int a, b; 
		cin>>a>>b;
		v[a].push_back(b), v[b].push_back(a); 
	}
	ll ans= 0; 
	for(int i=1; i<=n; i++){
		for(auto j: v[i]){
			if(j> i){
				for(auto x: v[j]){
					if(x> j) {
						for(auto z: v[x]){
							if(z== i) ans++; 
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
