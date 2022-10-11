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
		
		string w; 
		cin>>w; 
		vector<ll> v(w.size());
		map<int, ll> m; 
		ll sum= 0;
		for(int i=0; i<w.size(); i++){
			v[i]= w[i]-'a'+1; 
			m[v[i]]++; 
		}
		for(ll i=1; i<=26; i++){
			sum+= m[i]*i; 
		}
		ll p; 
		cin>>p; 
		if(sum<= p)cout<<w<<endl;
		else{ 
			ll ss= 0, rec, fin= 0; 
			for(ll i=26; i>=1; i--){
				ss+= m[i]*i; 
				if(sum-ss<= p){
					ss-= m[i]*i; 
					sum-= ss; 
					fin= (sum-p)/i; 
					//cout<<sum-p<<endl;
					if((sum-p)%i> 0) fin++; 
					rec= i; 
					break; 
				}
			}
			vector<int> rr; 
			int cnt= 0; 
			for(int i=26; i>=1; i--){
				for(int j=0; j<w.size();j++){
					if(i> rec){
						if(v[j]== i) rr.push_back(j); 
					}
					else if(i==rec){
						if(cnt>= fin) break; 
						if(v[j]== i){
							cnt++; 
							rr.push_back(j); 
						}
					}
				}
				if(cnt>= fin) break; 
			}
			sort(rr.begin(), rr.end()); 
			//cout<<fin<<endl;
			map<int, int> rrr; 
			string s= ""; 
			for(int i=0; i<rr.size(); i++) rrr[rr[i]]= 1; 
			for(int i=0; i<w.size(); i++){
				if(rrr[i]==1) continue; 
				s+= w[i]; 
			}
			cout<<s<<endl;
		}
		
	}
}
