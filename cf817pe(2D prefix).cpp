#include<bits/stdc++.h> 
#define ll long long 
#define maxn 1003
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int t; 
	cin>>t;
	while(t--){
		int n, q, a, b; 
		cin>>n>>q; 

		ll prx[maxn][maxn]; 
		vector<vector<ll> > mp1(maxn, vector<ll>(maxn)); 
	
		memset(prx, sizeof(prx), 0ll); 
		
		for(int i=0; i<n; i++){
			cin>>a>>b;
			mp1[a][b]+= a*b;
		}

		for(int i=1; i<maxn; i++){
			for(int j=1; j<maxn; j++){

				prx[i][j]= prx[i-1][j]+prx[i][j-1]- prx[i-1][j-1]+mp1[i][j]; 
			}
			
		}
		
		while(q--){
			int h, w, h1, w1; 
			cin>>h>>w>>h1>>w1; 
			cout<<prx[h1-1][w1-1]+prx[h][w]-prx[h1-1][w]-prx[h][w1-1]<<endl; 

		}
	}
}
