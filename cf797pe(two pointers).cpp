#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#include<cmath> 
#include<map>
#include<bitset> 
#include<queue> 
#define ll long long 
#define maxn 4005
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
		ll sum= 0; 
		vector<int> v(n);
		vector<int> rmn(n); 
		 
		for(int i=0; i<n; i++) {
			cin>>v[i];
			sum+= v[i]/k; 
			rmn[i]= v[i]%k;  

		}
		sort(rmn.rbegin(), rmn.rend()); 
		for(int i=0, j= n-1; i<j; i++, j--){
			while(rmn[i]+rmn[j]< k&& i< j) j--; 
			if(i==j) break; 
			sum++; 
		}
		cout<<sum<<endl;
	}
}

