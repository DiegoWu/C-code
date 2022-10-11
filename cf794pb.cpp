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
		int n, cnt= 0; 
		cin>>n; 
		vector<int> v(n); 
		for(int i=0; i<n; i++) cin>>v[i]; 
		int pin= v[0], use= -1; 
		for(int i=0; i<n-1; i++){
			if(i== use) continue; 
			if(v[i+1]< v[i]) {
				use= i+1; 
				cnt++; 
			}
		}
		cout<<cnt<<endl;
	}
}
