#include<bits/stdc++.h>

#define ll long long 
#define maxn 10004
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; 
	cin>>n>>k; 
	vector<int> v(n), rec; 
	map<int, int> m;
	for(int i=0; i<n; i++) {
		cin>>v[i]; 
		if(i< k) continue; 
		if(m[v[i]]) continue; 
		rec.push_back(v[i]); 
		m[v[i]]= i; 
	}
	int ans= -1; 

	sort(rec.begin(), rec.end()); 
	for(int i= rec.size()-2; i>= 0; i--){
		if(m[rec[i]]> m[rec[i+1]]) m[rec[i]]= m[rec[i+1]]; 
	}
	for(int i=0; i<k; i++){
		int x= upper_bound(rec.begin(), rec.end(), v[i])-rec.begin();  
		if(x==rec.size()) continue; 
		if(ans== -1) ans= m[rec[x]]-i; 
		else ans= min(ans,  m[rec[x]]-i); 
	}
	cout<<ans<<endl; 
}
