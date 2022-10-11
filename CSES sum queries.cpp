#include<iostream>
#include<vector>
#include<algorithm> 
#include<unordered_map>
#define ll long long 
#define maxn 200000
using namespace std; 
unordered_map<ll, ll> bit; 
unordered_map<ll, ll> ori;
unordered_map<ll, ll> nt;
ll n; 
ll sum(ll index){
	ll summ= 0;
	while(index> 0){
		summ+= bit[index]; 
		index-= index&-index; 
	}
	return summ; 
}
void modify(ll index, ll val, ll o){
	while(index<= n){
		bit[index]+= val-ori[o]; 
		index+= index&-index; 
	}
}
void solve(){
	ll q, a, b, c;
	cin>>n>>q>>bit[1];
	ori[1] =bit[1];
	nt[1]= ori[1];
	for(ll i=2; i<n+1; i++) {
		cin>>ori[i]; 
		nt[i]= nt[i-1]+ori[i];
		bit[i]= nt[i]; 
		ll z= i-(i&-i);
		bit[i]-= nt[z];
	}
	for(int i=0; i<q; i++){
		cin>>a>>b>>c; 
		if(a== 1)
			modify(b, c, b);
		else 
			cout<<sum(c)-sum(b-1)<<endl;
	}
	bit.clear(); 
	ori.clear(); 
	nt.clear(); 
}

int main(){
	solve();
	return 0; 
}