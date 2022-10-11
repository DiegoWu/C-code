#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, l, r; 
		cin>>n; 
		vector<int> v(n);
		vector<int> pos(n); 
		for(int i=0; i<n; i++){
			cin>>v[i]; 
			pos[v[i]]= i; 
		}
		l= min(pos[0], pos[1]), r= max(pos[1], pos[0]); 
		ll ans= 1; 
		for(int i=2; i<n; i++){
			if(l< pos[i]&& pos[i]< r){
				ans*= (r-l+1)-i; 
				ans%= mod; 
			}
			else{
				l= min(pos[i], l); 
				r= max(pos[i], r); 
			}
		}
		cout<<ans<<endl;

		
	}
}
