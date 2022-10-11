#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair
const float P = 0.5;
using namespace std; 

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		vector<int> v(n); 
		map<int, int> vis; 
		map<int, int> ans; 
		for(int i=0; i<n; i++) cin>>v[i]; 
		for(int i=0; i<n; i++){
			if(vis[v[i]]==0) {
				vis[v[i]]= i+1; 
				ans[v[i]]= 1; 
			}
			else{

				if((i+1- vis[v[i]])%2== 1){

					//cout<<v[i]<<endl;
				 	ans[v[i]]++; 
				}
				vis[v[i]]= i+1; 
			}
		}
		for(int i=1; i<n+1; i++){
			
			cout<<ans[i]<<" "; 
		}
		cout<<endl;
	}
}


