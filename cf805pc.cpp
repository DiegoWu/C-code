#include<bits/stdc++.h>

#define ll long long 
#define maxn 1000000001
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		
		int n, k; 
		cin>>n>>k; 
	
		map<int, int> vis; 
	
		map<int, pair<int, int> > rec, x; 
		for(int i=0; i<n; i++){
			int a; 
			cin>>a; 
 
			if(x[a].first==0&& vis[a]!= 1) x[a].first= i; 
			x[a].second= max(x[a].second, i); 
			vis[a] =1;
		}
		//sort(vv.begin(), vv.end());
		
		for(int i=0; i<k; i++){
			int s, t; 
			cin>>s>>t; 
			if(vis[s]==0|| vis[t]== 0) cout<<"No"<<endl;
			else{
				if(x[s].first< x[t].second) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}
	}
}
