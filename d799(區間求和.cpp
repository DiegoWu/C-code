#include<iostream>
#include<cmath>
#include<vector> 
#define ll long long 
#define maxn 500000
using namespace std;
vector<ll> segtree(4*maxn); 
vector<ll> ltag(4*maxn); 
vector<ll> arr(maxn); 
void build(int node, int l, int r){
	if(l== r) segtree[node]= arr[l]; 
	else{
		int mid= (l+r)/2; 
		int leftnode= node*2+1;
		int rightnode= node*2+2; 
		build(leftnode, l, mid); 
		build(rightnode, mid+1, r); 
		segtree[node]= segtree[leftnode]+ segtree[rightnode]; 
	}
}

void modify(int node, int l, int r, int ql, int qr, int val){ 

	if(l>r|| l>qr|| r<ql) return; 
	if(l>=ql&& r<= qr){
		ltag[node]+= val; 
		//cout<<"modify"<<endl;
		//cout<<"node: "<<node<<" "<<"ltag: "<<ltag[node]<<endl;
		return; 
	}
	int leftnode= node*2+1; 
	int rightnode= node*2+2;                                    
	int mid= (l+r)/2; 
	modify(leftnode, l, mid, ql, qr, val); 
	modify(rightnode, mid+1, r, ql, qr, val); 
	segtree[node]= segtree[leftnode]+ (r-mid)*ltag[rightnode]+ segtree[rightnode]+ (mid-l+1)*ltag[leftnode]; 
	//cout<<"left: "<<leftnode<<" "<<"right: "<<rightnode<<" R: "<<r<<" mid: "<<mid<<" L: "<<l<<endl;
	//cout<<"node modified: "<<node<<" val: "<<segtree[node]<<endl;
}

ll query(int node, int l, int r, int ql, int qr){
	
	if(l>r|| r<ql|| l> qr) return 0; 
	if (l>=ql&& r<= qr) {
		//cout<<"query"<<endl;
		//cout<<"nodeori: "<< segtree[node]<<endl;
		//cout<<"added node: "<<node<<" val: "<<segtree[node]+ (r-l+1)*ltag[node]<<endl;
		//cout<<"ltag: "<<ltag[node]<<endl; 
		return segtree[node]+ (r-l+1)*ltag[node];  
	}
	//else cout<<"regular: node: "<<node<<" val: "<<segtree[node]<<" lazy: "<<ltag[node]<<" l: "<<l<< " r: "<<r<<endl;
	int leftnode= node*2+1; 
	int rightnode= node*2+2; 
	int mid= (l+r)/2; 
	ll lf= query(leftnode, l, mid, ql, qr); 
	ll rt= query(rightnode, mid+1, r, ql, qr);  

	return lf+ rt +(min(r, qr)-max(l, ql)+1)*(ltag[node]); 
} 
void solve(){

	int n, q; 
	cin>>n; 
	for(int i=0; i<n; i++) cin>>arr[i]; 
	cin>>q; 
	 
	build(0, 0, n-1); 
	//for(int i=0; i<n*4; i++) cout<<segtree[i]<<endl;
	for(int i=0; i<q; i++){
		int a, b, c, k; 
		cin>>a; 

		if(a==1){

			cin>>b>>c>>k; 
			modify(0, 0, n-1, b-1, c-1, k); 

		}

		else{ 
			cin>>b>>c; 
			ll ans= query(0, 0, n-1, b-1, c-1); 
			cout<<ans<<endl;
			//cout<<"ans: "<< ans<<endl; 
		}
	}
}
int main(){
	solve(); 
	return 0; 
}