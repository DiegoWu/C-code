#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 5000000
using namespace std;
vector<int> arr(maxn);
vector<pair<int, int> > segtree(maxn); 
void build(int node, int start, int end){

	if(start== end){
		segtree[node].first= arr[start];
		segtree[node].second= start; 
	}
	else{
 
		int leftnode= node*2+1, rightnode= node*2+2, mid= (start+end)/2; 
		build(leftnode, start, mid); 
		build(rightnode, mid+1, end); 
		segtree[node].first= min(segtree[leftnode].first, segtree[rightnode].first);
	}
}

void modify(int node, int start, int end, int pos, int val){
	//cout<<v<<": "<<start<<" "<<end<<" "<<segtree[node].first<<endl; 
	if(start== end&& segtree[node].second== pos) {
		segtree[node].first= val;
		return;  //cout<<pos<<" "<<segtree[pos].first<<endl;
	} 
	else if(start== end) return; 
	else {
		int leftnode= node*2+1; 
		int rightnode= node*2+2; 
		int mid= (start+end)/2; 
		if(pos<= mid) modify(leftnode, start, mid, pos, val); 
		else modify(rightnode, mid+1, end, pos, val); 
		//cout<<"m: "<<node<<" "<<segtree[node].first<<endl;
		segtree[node].first= min(segtree[leftnode].first, segtree[rightnode].first);  
	}
}

int query(int node, int start, int end, int l, int r){

	//cout<<z<<": "<<start<<" "<<end<<" "<<segtree[node]<<endl; 
	if(start> r|| end< l) return maxn; 
	else if(start>= l&& end<= r){
		return segtree[node].first; 
	}
	else {
		int leftnode= node*2+1; 
		int rightnode= node*2+2; 
		int mid= (start+end)/2; 
		int leftv= query(leftnode, start, mid, l, r); 
		int rightv= query(rightnode, mid+1, end, l, r); 
		return min(leftv, rightv); 
	}
}
void solve(){
	int t, n; 
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	cin>>t>>n; 
	for(int i=0; i<n; i++)
		cin>>arr[i];
	build(0, 0, n-1);
	//for(int i=0; i<(n-1)*(n-1); i++) cout<<i<<" "<<segtree[i]<<endl;
	for(int i=0; i<t; i++){
		int x, y, z; 
		cin>>x>>y>>z;
		if (x==1)
			cout<<query(0, 0, n-1, y, z)<<endl;  
		else 
			modify(0, 0, n-1, y, z);
	}
}
int main(){

	solve();
	 return 0;
}
