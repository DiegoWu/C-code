 #include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
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
		int n, q; 
		cin>>n>>q; 
		vector<int> v(n);
		vector<int> suf(n); 
		for(int i=0; i<n; i++){
			cin>>v[i]; 
		}
		sort(v.rbegin(), v.rend()); 
		suf[0]= v[0]; 
		for(int i=1; i<n; i++){
			suf[i]= suf[i-1]+v[i]; 
		}
		while(q--){
			int x; 
			cin>>x; 
			int pos= lower_bound(suf.begin(), suf.end(), x)-suf.begin(); 
			if(pos==n) cout<<-1<<endl;
			else cout<<pos+1<<endl;
		}
	}
}
