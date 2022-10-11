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
		int n; 
		cin>>n; 
		vector<double> v(n); 
		string ans= "NO"; 
 
		for(int i=0; i<n; i++) cin>>v[i];
		for(int i=0; i<n; i++){
			double pin= v[i], cnt= 0; 
			for(int j=0; j<n; j++){
				if(j==i) continue; 
				cnt+= v[j]; 

			}
			if(cnt/(n-1)== pin){
				ans= "YES"; 
				break; 
			}
		}
		cout<<ans<<endl;
	}
}
