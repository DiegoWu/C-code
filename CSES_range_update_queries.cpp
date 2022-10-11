#include<iostream>
#include<unordered_map>
#include<algorithm> 
#define ll long long 
using namespace std;
ll n; 
unordered_map<ll, ll> bit; 
unordered_map<ll, ll> temp; 
void modify(ll i, ll val){
	while(i<= n){
		bit[i]+= val; 
		i+= i&-i; 
	}

}
ll sum(ll i){
	ll ans= 0; 
	while(i>0){
		ans+= bit[i]; 
		i-= i&-i; 
	}
	return ans; 
}
void solve(){
	ll q;
	ll a; 
	cin>>n>>q>>bit[1]; 
	temp[1]= bit[1];
	for(ll i=2; i<n+1; i++){
		cin>>a;
		temp[i]= a; 
		ll x= i- (i&-i); 
		bit[i]= a-temp[x]; 
	}
	ll b, c, d; 
	for(int i=0; i<q; i++){
		cin>>a; 
		if(a== 1){
			cin>>b>>c>>d; 
			modify(b, d); 
			modify(c+1, -d); 
		}
		else {
			cin>>b; 
			cout<<sum(b)<<endl; 
		}
	}
}
int main(){
	solve(); 
	return 0; 
}