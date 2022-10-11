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
		int n, ee= 0, ee1= 0; 
		cin>>n; 
		vector<int> v(n), v1(n), cnt(10), cnt1(10), g(10), g1(10);  
		map<int, int> m, org; 
		for(int i=0; i<n; i++){
			cin>>v[i]; 
			m[v[i]]++;  
			org[v[i]]++; 
			if(v[i]==1) g[1]++; 
			if(v[i]< 10) cnt[v[i]]++; 
		}
		for(int i=0; i<n; i++) {
			cin>>v1[i];
			if(v1[i]==1) g1[1]++; 
			if(v1[i]< 10) cnt1[v1[i]]++; 
		}
		sort(v.begin(), v.end()); 
		sort(v1.begin(), v1.end()); 
	
		for(int i=0; i<n; i++){
			if(v1[i]< 10) continue; 
			if(m[v1[i]]> 0) { m[v1[i]]--; v1[i]= -1; } 
		}

		int ans= 0; 

		for(int i=0; i<n; i++){
	
			string temp= to_string(v[i]); 
			string temp1=  to_string(v1[i]); 
			if(m[v[i]]== org[v[i]]) g[temp.size()]++;
			else m[v[i]]++;  
			if(v1[i]>= 10)  g1[temp1.size()]++; 
		}

		for(int i=2; i<10; i++){

			ans+= g[i]+g1[i]; 
	
			ans+= abs(g[i]-g1[i]+cnt[i]-cnt1[i]); 
			
			if(cnt[i]+g[i]> cnt1[i]+g1[i]) ee+= abs(g[i]-g1[i]+cnt[i]-cnt1[i]); 
			else ee1+= abs(g[i]-g1[i]+cnt[i]-cnt1[i]); 
		}
		
		cout<<ans<<endl;

	}
}
