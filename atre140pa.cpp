#include<iostream>
#include<vector>
#include<cmath> 
#define INF 10000000
using namespace std;

int main(){

	int n, k, ans= INF; 
	string s; 
	cin>>n>>k>>s; 
	ans= n; 
	vector<char> t(n+1); 
	for(float i=1; i<ceil(sqrt(n+1)); i++) 
		t[i]= s[i-1]; 
	for(int i=1; i<=n; i++){
		int cnt= k; 
		if(n%i== 0){
			float kk= n/i, z= i; 
			while(z){
				int tans= 0; 
				vector<int>vis(n*2); 
				for(int j=z; j<n+1; j+=i) {

					vis[t[j]-97]++; 
					tans= max(tans, vis[t[j]-97]); 
				}
				cnt-= kk-tans; 
				z--; 
			}
			if(cnt>= 0) ans= min(ans, i);  
			
		}
	}
	cout<<ans<<endl;
}