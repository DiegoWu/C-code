#include<iostream>
#include<vector>
#include<algorithm> 
#define maxn 200005
using namespace std; 

int main(){
	
	int n, q, l, r, x; 
	cin>>n; 
	vector<int> v[maxn]; 
	for(int i=1; i<n+1; i++){
		int a; 
		cin>>a; 
		v[a].push_back(i); 
	}
	cin>>q; 
	for(int i=0; i<q; i++){
		int ans= 0;  
		cin>>l>>r>>x; 
		int rr= lower_bound(v[x].begin(), v[x].end(), r+1)-v[x].begin(), ll= lower_bound(v[x].begin(), v[x].end(), l)-v[x].begin(); 
		ans= rr- ll; 
		cout<<rr<<" "<<ll<<endl;
		cout<<ans<<endl;
	}
	
}