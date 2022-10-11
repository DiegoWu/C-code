#include<bits/stdc++.h>

#define ll long long 
#define maxn 3003
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; 
	cin>>t; 
	while(t--){
		int n, k; 
		cin>>n>>k; 
		vector<int> v(n); 
		int ans, mx= 0, mn= maxn; 
		for(int i=0; i<n; i++){
			cin>>v[i]; 
			mx= max(v[i], mx); 
		}

		if(mx< k) cout<<0<<endl;
		else{
			int ans= maxn; 
			reverse(v.begin(), v.end()); 
			mx= 0, mn= maxn; 
			for(int i=k; i>=1; i--){
				//cout<<"i: "<<i<<endl;
				int ck= v[0]/i; 
				int rec= i; 
				mx= ck, mn= ck; 
				for(int j=1; j<n; j++){

					while(true){
						if(ck< v[j]/rec) break; 
						rec--; 
						if(!rec){ 
							break; 
						}
					} 
					rec++; 
					if(rec> 1) rec-= (abs(v[j]/(rec-1)-ck)< abs(v[j]/rec-ck)? 1: 0);  
					mx= max(mx, v[j]/rec), mn= min(mn, v[j]/rec); 
					ck= max(ck, v[j]/rec); 
				//	cout<<v[j]/rec<<endl;
				}
				ans= min(ans, mx-mn); 
			}
			cout<<ans<<endl;
		}
	}
	return 0; 
}
