#include<bits/stdc++.h> 
#define ll long long 
#define maxn 92233720368
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int t; 
	cin>>t; 
	while(t--){
		ll n, y, x; 
		cin>>n>>x>>y; 
		string s, s1; 
		cin>>s>>s1;
		vector<int> rec; 

		for(int i=0; i<n; i++) {if(s[i]^s1[i]) rec.push_back(i); }  

		if(rec.size()%2) cout<<-1<<endl;
		else if(rec.size()==0) cout<<0<<endl;
		else{
			ll dp[n+2]; 
			memset(dp, maxn, sizeof(dp)); 
		
			ll ans= 0; 
			
			if(x> y){
				if(rec.size()==2&& rec[0]== rec[1]-1) ans= min(x, y*2); 
				else ans= y*rec.size()/2; 
			}
			else{
				dp[0]= 0, dp[1]= 0; 
				//cout<<rec.size()<<endl;
				for(int i=2; i<rec.size()+2; i++){
					if(i&1) dp[i]= min(dp[i-2]+(rec[i-1]-rec[i-2])*x, dp[i-1]); 
					else dp[i]= min(dp[i-2]+(rec[i-1]-rec[i-2])*x, dp[i-1]+y);
					//cout<<dp[i]<<endl; 
				}
				ans= dp[rec.size()]; 
			}
			cout<<ans<<endl;
		}
	}
}
