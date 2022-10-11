#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#define ll long long 
#define maxn 4005
#define mp make_pair
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		string s; 
		ll ans= 0; 
		cin>>n; 
		vector<int> g[maxn];
		vector<int> v(n-1), bl(n+1);
		set<int> st; 
		for(int i=0; i<n-1; i++) cin>>v[i]; 
		cin>>s; 
		for(int i=0; i<n-1; i++) g[v[i]].push_back(i+2); 
		reverse(v.begin(), v.end()); 
		
		for(int i=1; i<n+1; i++) {
			if(s[i-1]== 'W') bl[i]=1; 
			else bl[i]= -1; 
		}

		for(int i=0; i<n-1; i++) st.insert(v[i]); 
		
		for(auto i= st.rbegin(); i!=st.rend(); i++){
			
			for(int j=0; j<g[*i].size(); j++){
				bl[*i]+= bl[g[*i][j]]; 

			}
			if(bl[*i]==0) ans++; 
		}
		cout<<ans<<endl;
	}
}