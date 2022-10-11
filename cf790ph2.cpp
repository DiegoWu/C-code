#include<iostream>
#include<vector>
#include<map> 
#include<set> 
#define ll long long 
using namespace std; 
map<ll, ll> bit; 
 
int n; 
ll sum(int node){
	ll cnt= 0;   
	while(node> 0){
		cnt+= bit[node]; 
		node-= node&-node; 
	}
	return cnt; 
}
void modify(int node){
	
	while(node<= n){
		bit[node]++; 
		node+= node&-node; 
	}
	return; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		ll ans= 0; 
		cin>>n; 
		vector<int> v(n);
		set<int> st; 
		map<ll, ll> mp; 
		for(int i=0; i<n; i++) {
			cin>>v[i]; 
			st.insert(v[i]); 
			mp[v[i]]++; 
		}
		for(int i=0; i<n; i++){
			
			ans+= i-sum(v[i]); 
			modify(v[i]); 
			//cout<<ans<<endl;
		}
		for(auto i= st.begin(); i!= st.end(); i++){
			if(mp[*i]> 1) ans+= mp[*i]*(mp[*i]-1)/2; 
		}
		cout<<ans<<endl;
	
		bit.clear(); 
	}
}