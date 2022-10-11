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
		int n; 
		cin>>n; 
		vector<int> v(101); 
		for(int i=0; i<n; i++) {
			int a; 
			cin>>a; 
			v[a]++; 
		}
		int temp= v[0]; 
		sort(v.rbegin(), v.rend()); 
		if(temp>=1) cout<<n-temp<<endl;
		else if(v[0]>=2) cout<<n<<endl;
		else cout<<n+1<<endl;
	}
	
}
