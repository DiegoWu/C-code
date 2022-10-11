#include<bits/stdc++.h> 
#define ll long long 
#define maxn 10000
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

		for(int i=0; i<n; i++) if(s[i]!= s1[i]) {rec.push_back(i); };  

		if(rec.size()%2) cout<<-1<<endl;
		else if(rec.size()== 2&& rec[0]== rec[1]-1) cout<<min(y*2, x)<<endl;
		else{
			ll ans= 0; 
			ans+= y*(rec.size()/2); 
			cout<<ans<<endl;
		}
	}
}
