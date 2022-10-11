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
		ll n, k, temp= 2; 
		ll ans= 0; 
		cin>>n>>k; 
		vector<ll> arr(n), prx(n); 
		for(int i=0; i<n; i++) cin>>arr[i];
		prx[0]= arr[0]; 
		for(int i=1; i<n; i++) prx[i]= prx[i-1]+ arr[i];
		for(int i=0; i<n; i++){
			ll temp= prx[i]-k*(i)-arr[i]; 
			ll z= 2; 
			for(int j=i; j<min(30ll+i+1, n); j++){
				temp+= arr[j]/z, z*= 2; 
			}
			
			ans= max(ans, temp); 
		}		
		cout<<max(ans, prx[n-1]-k*(n))<<endl;
	}
}
