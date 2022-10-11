#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair
const float P = 0.5;
using namespace std; 

int main() 
{	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t; 
	while(t--){
		int n, q;
		cin>>n>>q; 
		vector<int> v(n);
		//vector<multiset<ll> > mul(n);
		for(int i=0; i<n; i++) cin>>v[i];
		string ans=""; 
		int iq= 0; 
		for(int i=n-1; i>=0; i--){
			if(iq>= v[i]) ans+= '1'; 
			else if(iq< v[i]&& iq< q) iq++, ans+='1';  
			else ans+= '0'; 
			
		}
		reverse(ans.begin(), ans.end()); 
		cout<<ans<<endl;
		
	}
    
}


