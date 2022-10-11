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
bool L(pair<ll, ll> f, pair<ll, ll> s){return f.second< s.second;} 

int main(){

	int n; 
	ll w, h; 
	cin>>n; 
	vector<pair<ll, ll> > v; 
	vector<pair<ll, ll> > temp(n); 
	vector<int> vis(n); 
	vector<int> tag(n); 
	for(int i=0; i<n; i++) temp[i]= make_pair(maxn, maxn); 
	vector<pair<ll, ll> > x(n); 
	for(int i=0; i<n; i++){
		cin>>w>>h; 
		v.push_back(make_pair(w, h)); 
	}
	sort(v.begin(), v.end(), cmp); 
	x[0]= make_pair((v[0].first*v[0].second)%mod, 1); 
	temp[0]= v[0]; 
	int g, ww= 0; 
	ll ans= 0; 
	for(int i=1; i<n; i++){
		g= 0; 
		cout<<"****************times: "<<i<<endl;
		int z= lower_bound(temp.begin(), temp.begin()+i, v[i], L)-temp.begin();
		if(temp[z].second== v[i].second|| !z) g= 1;
		temp[z]= v[i];
		if(!z) {
			x[z].second++; 
			x[z].first+= (v[i].first*v[i].second)%mod; 
			continue;
		}
		//else if(g) x[z].second= x[z].second+z-1+g; 
		else 
			x[z].second=x[z-1].second+z-1+g;
		
		if(vis[z]){
			x[z].second+= vis[z]; 
			vis[z]= 0; 
			
			//else x[z].first+= (v[i].first*v[i].second)%mod; 
			
			//x[z].first+=  (v[i].first*v[i].second)%mod; 
		}
		if(tag[z-1]){
				x[z].first+= tag[z-1];
				tag[z-1]= 0; 
		}
		ans+= (((v[i].first*v[i].second)%mod)*x[z].second)%mod-x[z-1+g].first%mod; 
		if(g) {
			vis[z]++; 
			tag[z]+= (v[i].first*v[i].second)%mod; 
			//x[z].second++; 
			x[z].first+= (v[i].first*v[i].second)%mod; 
		}
		else x[z].first+= (v[i].first*v[i].second)%mod+x[z-1].first%mod; 
		cout<<"ans: "<<ans<<endl;
		cout<<"now: "<<v[i].first*v[i].second*x[z].second<<endl;
		cout<<"z: "<<z<<endl;
		cout<<"x.second: "<<x[z].second<<endl; 
		cout<<"x.first: "<<x[z].first<<endl;
		cout<<"tag: "<<tag[z]<<endl;
		ans%= mod; 
	}

	//for(int i=1; i<n; i++) ans+= x[i]%mod; 
	cout<<ans%mod<<endl;
}