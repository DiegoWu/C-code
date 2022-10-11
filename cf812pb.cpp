#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 9223372036854775807
#define mod 998244353
#define mp make_pair

using namespace std;
using P= pair<ll, int>; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t;
	cin>>t; 
	while(t--){
		int n;
		cin>>n; 
		vector<int> v(n);
		for(int i=0; i<n; i++) cin>>v[i]; 
		string ans= "Yes";
		int pvt= -1, pp= -1; 
		for(int i=1; i<n-1; i++){
			if(v[i]< v[i-1]) pp= v[i]; 
			if(v[i]== v[i+1]&& pp!= -1) pvt= v[i]; 
			else if(pp&&pvt!= -1&& v[i+1]> pvt) ans= "No"; 
			if(v[i]< v[i-1]&& v[i]< v[i+1]) ans= "No"; 
		}
		cout<<ans<<endl;
	}

 }
