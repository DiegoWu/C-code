#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 10004
#define mod 998244353
#define mp make_pair

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n;
		cin>>n; 
		vector<int> v(n);
		for(int i=0; i<n; i++) cin>>v[i]; 
		map<int, int> m; 
		int ans= 0; 
		for(int i=n-1; i>=0; i--){
			m[v[i]]++; 
			if(m[v[i]]> 1) break; 
			ans++; 
		}
		cout<<n-ans<<endl;
	}
}
