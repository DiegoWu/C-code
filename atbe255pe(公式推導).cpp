#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#include<cmath> 
#include<map>
#include<bitset> 
#include<queue> 
#define ll long long 
#define maxn 300005
#define mp make_pair

using namespace std; 
int main(){

	ll n, m, ans= 0; 
	cin>>n>>m; 
	vector<ll> s(n), arr(m), b(n);
	map<ll, ll> cnt; 
	for(int i=1; i<n; i++) cin>>s[i];
	for(int i=0; i<m; i++) cin>>arr[i];

	for(int i=1; i<n; i++) b[i]= s[i]-b[i-1];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ll c= arr[j]- b[i];
			
			if(i%2) c*= -1; 
			cnt[c]++; 
		}
	}
	for(auto ele: cnt) ans= max(ans, ele.second); 
	cout<<ans<<endl;
}


