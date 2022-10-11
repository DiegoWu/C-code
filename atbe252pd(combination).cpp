#include<iostream>
#include<vector>
#include<string> 
#include<algorithm> 
#include<cmath> 
#define ll long long 
#define INF 200006
using namespace std; 

int main(){
	ll n; 
	cin>>n; 
	vector<int> v(n); 
	int x= INF, y= -1;  
	for(int i=0; i<n; i++) {
		cin>>v[i]; 
		x= min(v[i], x); 
		y= max(y, v[i]); 
	}
	//sort(v.begin(), v.end()); 
	vector<ll> vp(INF); 
	 
	for(int i=0; i<n; i++)
		vp[v[i]]++; 

	ll ans= n*(n-1)*(n-2)/6; 
	for(int i=x; i<=y; i++){

		if(vp[i]== 2) ans-= n-2; 
		else if(vp[i]>= 3){
			ans-= vp[i]*(vp[i]-1)*(vp[i]-2)/6; 
			ans-= (vp[i]*(vp[i]-1)/2)*(n-vp[i]); 
		}
	}
	cout<<ans<<endl;
}