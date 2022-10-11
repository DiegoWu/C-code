#include <iostream>
#include<algorithm> 
#include<vector> 
#include <cmath>
#define ll long long
#define ld long double
#define int long long
#define N 300005
#define INT_MAX 1e7
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define INF 2e18
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int n,arr[N],pref[N];
pii seg[4*N];

//建立線段樹[l,r)
void build(int cur,int l,int r){
    if(r-l == 1) { 
    	seg[cur]= make_pair(arr[l], l);
    	return ; 
    } 
    int mid= (l+r)/2; 
    build(cur*2, l, mid); 
    build(cur*2+1, mid, r); 
    if(seg[cur*2].x> seg[cur*2+1].x) seg[cur]= seg[cur*2+1]; 
    else seg[cur]= seg[cur*2]; 
}

//詢問區間最小值，回傳pair
pii query(int cur,int l,int r,int ql,int qr){
	if(r <= l || ql >= r || qr <= l) return make_pair(INT_MAX, INT_MAX);
    if(ql<= l&& qr>= r) {
    	//cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<cur<<" "<<seg[cur].x<<endl;
    	return seg[cur];
    } 
    int mid= (l+r)/2; 
    pii lft= query(cur*2, l, mid, ql, qr); 
    pii rgt= query(cur*2+1, mid, r, ql, qr); 
    if(lft.x> rgt.x) return rgt;
    else return lft;   

}

signed main(){
   Orz; 
   int n; 
   cin>>n; 
   for(int i=1; i<n+1; i++){
		cin>>arr[i];
	   	pref[i]= pref[i-1]+ arr[i]; 
   }
   build(1, 1, n+1); 
   int l= 1, r= n+1; 
   while(r-l> 1){
   		int idx= query(1, 1, n+1, l, r).y; 
   		int lft= pref[idx-1]- pref[l-1]; 
   		int rgt= pref[r-1]- pref[idx]; 
   		if(rgt>= lft) l= idx+1; 
   		else r= idx; 
   	}
   	cout<<arr[l]<<endl; 
}