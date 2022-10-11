#include<bits/stdc++.h>

#define ll long long 
#define maxn 9223372036854775807
#define mp make_pair
 
using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, x;
	cin>>n>>x; 
	vector<pair<ll, ll> > v(n);
	for(int i=0; i<n; i++) {
		cin>>v[i].first>>v[i].second;
		if(i!= 0){
			if(x< i) continue; 
			v[i].first+= v[i-1].first+v[i-1].second; 
			v[i-1].second= (x-i+1)*v[i-1].second; 
		}
	}
	//v[0].second= v[0].second*(x); 
	ll com= maxn; 
	if(x>= n) v[n-1].second= v[n-1].second*(x-n+1); 
	for(int i=0; i<n; i++){
		//cout<<v[i].first<<endl;
		if(x< i) continue; 
		//cout<<v[i].first+v[i].second<<endl;
		com= min(com, v[i].first+v[i].second); 
	}
	cout<<com<<endl;
}

