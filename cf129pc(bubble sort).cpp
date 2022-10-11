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
		int n, ans= 0; 
		cin>>n; 
		vector<int> v(n), vv(n), rec[n+1]; 
		for(int i=0; i<n; i++){
			cin>>v[i];
			rec[v[i]].push_back(i); 
		}
		
		for(int i=0; i<n; i++)
			cin>>vv[i];
		for(int i=1; i<n; i++){
			if(vv[i]>=vv[i-1]&&v[i]>= v[i-1]) continue; 
			else if(vv[i]<=vv[i-1]&&v[i]<= v[i-1]) continue; 
			else{
				ans= -1; 
				break; 
			}
		}
		sort(v.begin(), v.end()); 
		vector<pair<int, int> > ann; 
		if(ans==-1) cout<<ans<<endl;
		else{
			int temp; 
			for(int i=1; i<n; i++){
				temp= rec[v[i-1]].size(); 
			 
				if(rec[v[i]][0]!= temp){
					ans++; 
					swap(rec[v[i-1]][temp-1], rec[v[i]][0]); 
					ann.push_back(make_pair(rec[v[i-1]][temp-1]+1, rec[v[i]][0]+1)); 
				}
			}
			cout<<ans<<endl;
			for(int i=0; i<ann.size(); i++){
				cout<<ann[i].first<<" "<<ann[i].second<<endl;
			}
		}
	}
}
