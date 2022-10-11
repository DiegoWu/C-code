#include<bits/stdc++.h> 
#define ll long long 
#define maxn 10000
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	string s; 
	cin>>s; 
	ll ans= stoll(s); 
	for(int i=1; i<(1<<(s.size()-1)); i++){
		vector<ll> temp, rec; 
		int xx= i, pos= 0;   
		while(xx!= 0){
			if(xx%2) temp.push_back(pos); 
			pos++; 
			xx/= 2; 
		}

		//cout<<i<<endl;

		int t= 0; 
		temp.push_back(s.size()-1); 
		//cout<<temp.size()<<endl;
		if(temp.size()==1) continue; 
		for(int j=0; j<temp.size(); j++){
			string tt=""; 
			for(int z=t; z<=temp[j]; z++){
				tt+= s[z]; 
			}
			rec.push_back(stoll(tt));
			
			t= temp[j]+1; 
		}
		for(auto x: rec) ans+= x;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
