#include<iostream>
#include<cmath> 
#include<vector>
#include<algorithm> 
#include<cstring> 
#define N 100001
#define R 1000001
#define ll long long 
using namespace std; 
int n, z; 
struct anode{
	int x1, x2, y, c; 
}arr[N*2]; 
struct node{
	int val, tag; 
}seg[R*4]; 
bool cmp(anode a, anode b){return a.y< b.y;} 

void modify(int node, int l, int r, int ql, int qr, int val){

	if(l>r||ql>=r||qr<=l) return; 

	if(ql<=l&&qr>=r){
		seg[node].tag+= val; 
		return; 
	}

	int leftnode= node*2+1, rightnode= node*2+2, mid= (l+r)/2; 

	modify(leftnode, l, mid, ql, qr, val);
	modify(rightnode, mid, r, ql, qr, val); 
	
	seg[node].val= (seg[leftnode].tag?mid-l:seg[leftnode].val)+(seg[rightnode].tag?r-mid: seg[rightnode].val); 
	//cout<<l<<" "<<mid<<" "<<mid-l<<" "<<seg[leftnode].tag<<endl;
	//cout<<mid+1<<" "<<r<<" "<<seg[rightnode].tag<<endl;
}

void solve(){

	memset(arr, 0, sizeof(arr)); 
	memset(seg, 0, sizeof(seg)); 
	cin>>n; 
	for(int i=0; i<n*2; i+=2){
		int l, r, d, u; 
		cin>>l>>r>>d>>u; 
		arr[i]= (anode){l, r, d, 1}; 
		arr[i+1]= (anode){l, r, u, -1}; 
	}
	stable_sort(arr, arr+n*2, cmp); 
	ll ans= 0, y0= 0, val= 0; 
	for(int i=0; i<n*2; i++){
		ans+= (ll)(arr[i].y- y0)*val; 
		z= 0; 
		modify(0, 0, R, arr[i].x1, arr[i].x2, arr[i].c); 
		y0= arr[i].y; 
		val= seg[0].val; 
	}

	cout<<ans<<endl;

}

int main(){

	solve(); 
	return 0; 
}