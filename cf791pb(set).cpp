#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#define ll long long 
using namespace std;
 

int main(){
	ll n, q , res= 0; 
	ll ans= 0; 
	cin>>n>>q; 
	vector<ll> v(n+1);
	set<ll> st; 
	for(int i=1; i<n+1; i++) {
		cin>>v[i];
		ans+= v[i]; 
	}

	for(int i=0; i<q; i++){
		ll t, a, b; 
		cin>>t;
		if(t== 1){
			cin>>a>>b; 
			ll temp= v[a];
			
			if(res!= 0&& st.find(a)== st.end()) {
				st.insert(a); 
				temp= res; 
			}
			v[a]= b;  
			ans= ans-temp+b; 
		}
		else{   
			st.clear(); 

			cin>>b; 
			res= b; 
			ans= b*n; 
		}
		cout<<ans<<endl;
	}

}