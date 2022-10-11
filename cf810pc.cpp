#include<bits/stdc++.h>

#define ll long long 
#define maxn 10004
#define mod 1000000007
#define mp make_pair

using namespace std;
void solve(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, k, fin= 0; 
	cin>>n>>m>>k; 
	bool ck= 0; 
	vector<ll> v(k);
	for(int i=0; i<k; i++) cin>>v[i]; 

	for(int i=0; i<k; i++){
		if(v[i]/n< 2) continue; 
		else{
			fin+= v[i]/n;  
		}
		if(v[i]/n>=3) ck= 1; 
	}
	if(fin>=m&&(ck|| m%2==0) ) {
		cout<<"Yes"<<endl;
		return; 
	}
	ck= 0, fin= 0; 
	for(int i=0; i<k; i++){
		if(v[i]/m< 2) continue; 
		else{
			fin+= v[i]/m; 
		}
		if(v[i]/m>= 3) ck= 1; 
	}
	if(fin>=n&&(ck|| n%2==0)){
	 cout<<"Yes"<<endl;
	 return; 
	}
	cout<<"No"<<endl;
	return; 
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; 
	cin>>t; 
	while(t--){
		solve(); 
	}
}
