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
		int n, c, q; 
	 
		cin>>n>>c>>q;
		string s; 
		cin>>s; 
		ll x= 1+s.size(); 
		
		map<ll, ll> rec; 
		vector<ll> v; 
		//m[1]= mp(1, s.size()); 
		rec[0]= 1; 
		ll gg; 
		v.push_back(1); 
		v.push_back(1+s.size()); 
		ll a, b; 
		for(int i=1; i<c+1; i++){
		
			gg= b-a+1; 
			if(i>=2)x+= gg; 
			cin>>a>>b; 
			rec[i]= a; 
			if(i==1) continue; 
			v.push_back(x); 
		
		}
	//	for(int i=0; i<c+1; i++) cout<<v[i]<<" "; 
		for(int i=0; i<q; i++){
			ll d; 
			cin>>d; 
			ll z= d; 
			while(true){
				if(z<= s.size()) break; 
				//cout<<z<<endl;
				int cur= upper_bound(v.begin(), v.end(), z)- v.begin(); 
				cur--;
			//	cout<<v[cur]<<endl;
				
 				z= rec[cur]+z-v[cur]; 
 			//	cout<<z<<endl;
			} 
			cout<<s[z-1]<<endl;
		}
	}
}
