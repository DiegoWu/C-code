#include<bits/stdc++.h>

#define ll long long 
#define maxn 9223372036854775807
#define mod 1000000007
#define mp make_pair
const float P = 0.5;
using namespace std; 

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		vector<ll> v(n), dp(n), rec; 
		for(int i=0; i<n; i++) cin>>v[i]; 

		ll ans= 0; 
		for(int i=1; i<n-1; i++){
			if(v[i]> v[i-1]&&v[i]> v[i+1]) rec.push_back(0); 
			else rec.push_back(max(v[i-1], v[i+1])- v[i]+1); 
	
		}

		if(n%2==1){
			for(int i=1; i<n-1; i+=2){
				if(v[i]> v[i-1]&&v[i]> v[i+1]) continue; 
				else ans+= (max(v[i-1], v[i+1])- v[i]+1); 
		
			}
		}
		else{

			dp[0]= rec[0], dp[1]= rec[1]; 
			for(int i=2; i<rec.size(); i++){
				if(i%2==0) dp[i]= rec[i]+dp[i-2]; 
				else dp[i]= min(dp[i-2], dp[i-3])+ rec[i]; 
			}
			ans= min(dp[rec.size()-1], dp[rec.size()-2]); 
		}
		cout<<ans<<endl;
	}
}
