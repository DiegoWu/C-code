#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 10004
#define mod 998244353
#define mp make_pair

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, cnt5= 0, temp; 
		bool f= 0;  
		cin>>n; 
		vector<ll> v(n), v5; 
		for(int i=0; i<n; i++) {
			cin>>v[i]; 
			if(v[i]%10== 5) 
				v[i]+= 5,v5.push_back(v[i]); 
			else if(v[i]%10==0) v5.push_back(v[i]); 
			else{
				while(v[i]%10!=4){
					v[i]+= v[i]%10; 
				}
			}

		}
		if(v5.size()!= 0) {
			if(v5.size()!= n) f= 1; 
			sort(v5.begin(), v5.end()); 
		}
		
		for(int i=1; i<v5.size(); i++)
			if(v5[i-1]!= v5[i]) f= 1;  
		sort(v.begin(), v.end()); 

		for(int i=1; i<n; i++){
			if((v[i]-v[i-1])%20!= 0) f= 1; 
		}
		cout<<(!f? "Yes": "No")<<endl; 
	}
}
