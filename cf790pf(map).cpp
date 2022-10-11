 #include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<map>
#include<set> 
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
		int n, k; 
		cin>>n>>k; 
		vector<int> v(n+1); 
		vector<pair<int ,int> > ans(n+1);
		vector<int> rec; 
		map<int, int> sum;
		map<int, int> vis; 

		for(int i=0; i<n; i++) {
			cin>>v[i];
			sum[v[i]]++;
			vis[v[i]]= 0; 
		}
		for(int i=0; i<n; i++) sum[v[i]]++; 
		
		for(int i=0; i<n; i++){
			if(vis[v[i]]) continue; 
			if(sum[v[i]]>=k) {
				rec.push_back(v[i]); 
				vis[v[i]]= 1; 
			}
			 
		}
		if(rec.size()==0) cout<<-1<<endl;
		else {
			sort(rec.begin(), rec.end()); 
			
			int cnt= 0, p=rec[0], z= 0, x= 0; 
			for(int i=0; i<rec.size(); i++){

				if(i<rec.size()-1&&rec[i]+1== rec[i+1]) cnt++;  
				else {
					if(cnt!= 0) {
						z= 1; 
						x= max(cnt, x); 
						ans[cnt]= make_pair(p, rec[i]); 
						cnt= 0; 
					}
					if(i==rec.size()-1) continue; 
					p= rec[i+1]; 

				}
			}
			if(!z) {
				int g= 0; 
				for(int i=0; i<n; i++) if(sum[v[i]]>= k) {cout<<v[i]<<" "<<v[i]<<endl; g= 1;  break;}
				if(!g)cout<<-1<<endl;
			}
			else cout<<ans[x].first<<" "<<ans[x].second<<endl;
		}
	}
}
