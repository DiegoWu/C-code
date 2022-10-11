#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<bitset> 
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
		int n, m; 
		cin>>n>>m; 
		vector<string> s(n);
		for(int i=0; i<n; i++){
			cin>>s[i]; 
		}
		int cnt= -1, a= -1; 
		string ans= "YES";
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(s[i][j]== 'R') {
					a= j; 
					 break;
				}
			}
			if(a!= -1) break; 
		}
		if(a==-1) cout<<"NO"<<endl;
		else {
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(s[i][j]== 'R') {
						if(j<a) ans= "NO"; 
						break;
					}
				}
				if(ans== "NO") break;
			}
			cout<<ans<<endl;
		}
	}
}
