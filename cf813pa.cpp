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
		int n, k; 
		cin>>n>>k; 
		vector<int> v(n), rec, z; 
		for(int i=0; i<n; i++) cin>>v[i]; 
		for(int i=0; i<k; i++) z.push_back(v[i]); 
		for(int i=k; i<n; i++) rec.push_back(v[i]); 
		if(rec.size()==0) cout<<0<<endl;
		else {
			sort(rec.begin(), rec.end()); 
			
			sort(z.rbegin(), z.rend()); 
			int cnt= 0, g= 0; 
			for(int i=0; i<z.size(); i++){
				if(rec[cnt]< z[i]) g++, cnt++; 
				if(cnt>= rec.size()) break; 
			}
			cout<<g<<endl;
		}

	}
}