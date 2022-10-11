#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
#define maxn 100000
#define ll long long 
using namespace std;
int n; 
ll tempp= 0; 
vector<ll> bit(maxn+1);
vector<ll> segtree(maxn*4);  
vector<ll> arr(maxn+1); 
vector<ll> rl(maxn+1); 

ll gcd(ll a, ll b){
	ll temp= max(a, b); 
	a= min(a, b); 
	b= temp; 
	if(a==0) return b; 
	return gcd(b%a, a);  
}

void bitmodify(int l, int r, ll val){
	while(l<= n){
		bit[l]+= val; 
		l+= l&-l;  
	}
	while(r<= n){
		bit[r]-= val; 
		r+= r&-r; 
	}	
}
ll bitquery(int pos){
	while(pos>= 1){
		tempp+= bit[pos]; 
		pos-= pos&-pos; 
	}
	return tempp; 
}
void modify(int node, int l, int r, int qr, ll val){
	if(l>r|| r< qr|| l> qr) return; 
	if(l==r&& r==qr){
		segtree[node]-= val;
		return; 
	}

	int leftnode= node*2+1; 
	int rightnode= node*2+2; 
	int mid= (l+r)/2; 
	modify(leftnode, l, mid, qr, val); 
	modify(rightnode, mid+1, r, qr, val); 
	segtree[node]= gcd(abs(segtree[leftnode]), abs(segtree[rightnode])); 
}
void modifyleft(int node, int l, int r, int ql, ll val){
	if(l>r|| l>ql|| r< ql) return; 
	if(l==r&& l==ql){
		segtree[node]+= val;
		return; 
	}
	int leftnode= node*2+1; 
	int rightnode= node*2+2; 
	int mid= (l+r)/2; 
	modifyleft(leftnode, l, mid, ql, val); 
	modifyleft(rightnode, mid+1, r, ql, val); 
	segtree[node]= gcd(abs(segtree[leftnode]), abs(segtree[rightnode])); 
}
void build(int node, int l, int r){
	if(l== r) {
		segtree[node]= rl[l+1]; 
		return; 
	}
	int mid= (l+r)/2; 
	int leftnode= node*2+1; 
	int rightnode= node*2+2; 
	build(leftnode, l, mid); 
	build(rightnode, mid+1, r); 
	segtree[node]= gcd(abs(segtree[leftnode]), abs(segtree[rightnode])); 
}
ll query(int node, int l, int r, int ql, int qr){

	if(l>r|| l>qr|| r<ql) return 0; 
	if(l>=ql&& r<=qr) return segtree[node]; 

	int leftnode= node*2+1; 
	int rightnode= node*2+2; 
	int mid= (l+r)/2; 
	return gcd(abs(query(leftnode, l, mid, ql, qr)), abs(query(rightnode, mid+1, r, ql ,qr))); 
}
void solve(){
	int q;  
	cin>>n>>q; 
	for(int i=1; i<n+1; i++) cin>>arr[i]; 
	arr[0]= 0; 
	rl[1]= arr[1]; 
	for(int i=2; i<n+1; i++) rl[i]= arr[i]- arr[i-1]; 
	bit[1]= rl[1]; 
	for(int i=2; i<n+1; i++){
		int ttemp= i-(i&-i);
		bit[i]= arr[i]- bit[ttemp]; 
		while(ttemp> 0){
			ttemp= ttemp-(ttemp&-ttemp); 
			bit[i]= bit[i]- bit[ttemp]; 
		}
	}
	build(0, 0, n-1); 
	for(int i=0; i<q; i++){
		int t, a, b, c; 
		cin>>t; 
		if(t== 1){
			cin>>a>>b>>c; 
			bitmodify(a, b+1, c); 
			if(b< n) {
				modify(0, 0, n-1, b, c);
			}
			modifyleft(0, 0, n-1, a-1, c);  

		}
		else{
			cin>>a>>b;    
			ll w= query(0,  0, n-1, a, b-1); 
			ll wx= bitquery(b); 
			tempp= 0;
			cout<<gcd(abs(w), abs(wx))<<endl;
		}
	}
}

int main(){

	solve(); 
	return 0; 
}