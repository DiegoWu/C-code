#include<bits/stdc++.h>

#define ll long long 
#define maxn 100005
#define mod 1000000007
#define llmax 92233720368547758
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; 
	cin>>t; 
	while(t--){
		int n, m; 
		cin>>n>>m; 
		vector<ll> v(n), z(n+1); 

		vector<pair<ll, ll> > rec(n);
		ll ans= llmax, anss= llmax;
		for(int i=0; i<n; i++){
			cin>>v[i]; 
			z[i]= llmax; 
			rec[i]= mp(v[i], i+1);
		}
		z[n]= llmax; 
		sort(rec.begin(), rec.end());
		map<ll, ll> mm;

		for(int i=0; i<m; i++){
			ll a, b;
			cin>>a>>b; 
			mm[a]++, mm[b]++; 
			z[a]= min(z[a], v[b-1]); 
			z[b]= min(z[b], v[a-1]);  
		}
		if(m%2!= 0){
			for(int j=0; j<n; j++){
				if(mm[rec[j].second]%2!= 0) anss= min(rec[j].first, anss);
				else {
					if(z[rec[j].second]== llmax) continue; 
					ans= min(ans, z[rec[j].second]+ rec[j].first); 
				}
			}
		}
		if(m%2==0) cout<<0<<endl;
		else cout<<min(ans, anss)<<endl;
	}
}
