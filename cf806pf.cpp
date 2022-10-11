#include<bits/stdc++.h>

#define ll long long 
#define maxn 105
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n;
		cin>>n; 
		vector<int > v;
		vector<int> v1; 
 
		ll ans= 0; 
		for(int i=1; i<n+1; i++){
			int a;
			cin>>a; 
			if(i> a) {
				
				v.push_back(a);
				v1.push_back(i);  
			}
		}
		
		for(int i=1; i<v.size(); i++){
			int cur= lower_bound(v1.begin(), v1.begin()+i, v[i])-v1.begin(); 
			ans+= cur; 
		}
		cout<<ans<<endl;

	}
}
