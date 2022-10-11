#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
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
		vector<ll> v(n); 
		for(int i=0; i<n; i++){
			cin>>v[i]; 
		}
		string ans= "YES"; 
		int ck= 0, temp= v[0]; 
		for(int i=1; i<n; i++){
			if(v[i]%temp==0) continue; 
			else{
				ans= "NO"; 
				break; 
			}
		}
		cout<<ans<<endl;
	
	}
}
