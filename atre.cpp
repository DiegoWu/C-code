#include<iostream>
#include<vector> 
#include<cmath>
#include<algorithm>
#define ll long long 
#define INF 10000000000
using namespace std;  

int main(){
	int n, k; 
	cin>>n>>k; 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> v(n); 
	//vector<int> use; 
	ll temp= 0; 
	ll tt= INF;
	for(int i=0; i<n; i++)
		cin>>v[i];
	for(int i=k; i<n; i++) if(v[i]>temp) temp= v[i]; 
	for(int i=0; i<k; i++) if(v[i]< tt) tt= v[i];
	ll ttt= INF; 
	if(temp<tt) cout<<-1<<endl;
	else{
		for(int i=k-1; i>= 0; i--){
			if(v[i]> temp) continue;
			if((i-k)>ttt) break;
			for(int j=k; j<n; j++){
				if(v[j]< tt) continue; 
				if(v[j]>v[i]){

					if(j-i< ttt) ttt= j-i; 
					//use.push_back(j-i); 
					break; 
				}
			}
		}
		if(ttt==INF)  cout<<-1<<endl;
		else cout<<ttt<<endl;
	}
	return 0; 
}