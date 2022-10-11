#include<bits/stdc++.h>

#define ll long long 
#define maxn 1000000005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b; 
	cin>>n>>a>>b;
	vector<int> v(n);
	int mn= maxn, mx= 0; 
	for(int i=0; i<n; i++){
		cin>>v[i]; 
		mn= min(v[i], mn), mx= max(mx, v[i]); 
	}
	int mid, c= 0; 
	int ans= mn; 

	while(mn<=mx){
		c++; 
		mid= (mn+mx)/2; 
	
		prv= mid; 
		ll cnt= 0, cnt1= 0; 
		for(int i=0; i<n; i++){
			if(v[i]< mid) cnt+= (mid-v[i])/a+((mid-v[i])%a? 1: 0);
			else cnt1+= (v[i]-mid)/b;
		}
		if(cnt<= cnt1){
			ans= mid; 
			mn= mid+1; 
		}
		else{
			mx= mid-1; 
		}
	}
	cout<<ans<<endl;
}
