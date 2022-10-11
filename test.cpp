#include<iostream>
#include<vector> 
#include<algorithm> 
#define ll long long 
#define mod 1000000009
#define maxn 10000000000
using namespace std ;
bool cmp(pair<ll, ll> f, pair<ll, ll> s){
	if(f.first== s.first) return f.second< s.second; 
	return f.first< s.first; 
}
//bool L(pair<ll, ll> f, pair<ll, ll> s){return f.second< s.second;} 

int main(){

	int n; 
	ll w, h; 
	cin>>n; 
	vector<pair<ll, ll> > v; 
	vector<pair<ll, ll> > temp(n); 
	for(int i=0; i<n; i++){
		cin>>w>>h; 
		v.push_back(make_pair(w, h)); 
	}
	sort(v.begin(), v.end(), cmp); 
	ll ans= 0; 
	for(int i=0; i<n-1; i++){
		for(int j=i+1;j<n; j++){
			if(v[i].second> v[j].second) continue; 
			ans+= v[j].second*v[j].first-v[i].second*v[i].first; 
		}

	}
	cout<<"*****************************test********************"<<endl;
	cout<<ans%mod<<endl;
}