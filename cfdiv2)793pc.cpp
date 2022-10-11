#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<bitset> 
#include<map>
#define ll long long 
#define INF 1000000001
#define mod 998244353
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		ll n, ans= 0, ans1= 0; 
		cin>>n; 
		vector<int> v(n); 
		map<int, int> mp; 
		for(int i=0; i<n; i++){
			cin>>v[i]; 
			mp[v[i]]++; 
		}
		sort(v.begin(), v.end()); 

		int flip= 0, z= 0; 
		for(int i=1; i<n+1; i++){
			if(i!=n) {if(v[i]==v[i-1]) continue;} 
			if(mp[v[i-1]]>= 2) {
				if(flip==1) {
					z= 1; 
					flip++; 
				}
				else ans++;
			}
			else{ 
				flip++; 
			}
			if(flip==2){ 
				if(z) flip= 1;  
				else flip= 0; 
				ans++, z= 0;
			}
			if(flip==1&&v[i-1]==v[n-1]&&mp[v[i-1]]== 1) ans++;  
			
		}
		sort(v.rbegin(), v.rend()); 
		for(int i=1; i<n+1; i++){
			if(i!=n) {if(v[i]==v[i-1]) continue;} 
			if(mp[v[i-1]]>= 2) {
				if(flip==1) {
					z= 1; 
					flip++; 
				}
				else ans1++;
			}
			else{ 
				flip++; 
			}
			if(flip==2){ 
				if(z) flip= 1;  
				else flip= 0; 
				ans1++, z= 0;
			}
			if(flip==1&&v[i-1]==v[n-1]&&mp[v[i-1]]== 1) ans1++;  
			
		}
		if(n==1) cout<<1<<endl; 
		else{
			cout<<max(ans, ans1)<<endl;
		}
	
	}
	return 0; 
}
