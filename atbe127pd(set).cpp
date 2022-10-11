#include<bits/stdc++.h>

#define ll long long 
#define maxn  100000000
#define mn 2005
#define mp make_pair
 
using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; 
	cin>>n>>m; 
	vector<ll> v(n);
	map<ll, ll> mm; 
	set<ll> st; 
	for(int i=0; i<n; i++) {
		cin>>v[i];
		mm[v[i]]++; 
		st.insert(v[i]); 
	}

	while(m--){
		int a, b; 
		cin>>a>>b; 
		st.insert(b); 
		mm[b]+= a; 
	}
	ll ans= 0; 
	for(auto i=st.rbegin(); i!= st.rend(); i++){
		if(mm[*i]>= n){
			ans+= n*(*i);
			break; 
		}
		else{
			ans+= mm[*i]*(*i); 
			n-= mm[*i]; 
		}
	}
	cout<<ans<<endl;
}
