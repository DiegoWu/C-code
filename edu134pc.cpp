#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n;  
		cin>>n; 
		vector<int> v(n), v1(n), ans(n), ans1(n); 
		for(int i=0; i<n; i++) cin>>v[i]; 
		for(int i=0; i<n; i++) cin>>v1[i]; 

		for(int i=0; i<n; i++){
			int pos= lower_bound(v1.begin(), v1.end(), v[i])-v1.begin(); 
			ans[i]= v1[pos]- v[i];  
			
		}

		int  last= n-1, per= v1[n-1]; 
		for(int i=n-1; i>=0; i--){
			
			int pos= lower_bound(v1.begin(), v1.end(), v[i])-v1.begin(); 
			if(pos== i) {
				ans1[i]= per- v[i], last= i-1;  
				per= v1[last]; 
			}
			else
				ans1[i]= per-v[i]; 
			
		}
		for(int i=0; i<n; i++) cout<<ans[i]<<" ";
		cout<<endl;
		for(int i=0; i<n; i++) cout<<ans1[i]<<" ";
		cout<<endl;

	}
}
