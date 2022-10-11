#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std; 

int main(){
	ll n, k, x; 
	ll ans=0; 
	cin>>n>>k>>x;
	vector<int>v(n);
	vector<int>r(n); 
	for(int i=0; i<n; i++){
		cin>>v[i]; 
		ans+= v[i];
	}
	
	sort(v.rbegin(), v.rend()); 
	for(int i=0; i<n; i++){
		if(k<= 0) break; 
 		if(v[i]/x>=k) {
			ans-= x*(min(k, v[i]/x)); 
			k= 0;
			break; 
		}
		ans-= x*(v[i]/x); 
		k-= v[i]/x;
		r[i]= v[i]%x;
	}
	if(k==0) cout<<ans<<endl;
	else{
		sort(r.rbegin(), r.rend()); 
		for(int i=0; i<n; i++){
			if(k== 0) break; 
			k--; 
			ans-= r[i]; 
		}
		cout<<ans<<endl; 
	}
}