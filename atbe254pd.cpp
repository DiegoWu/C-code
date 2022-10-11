#include<bits/stdc++.h>

#define ll long long 
#define maxn 10004
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> rec; 
	cin>>n; 
	ll cnt= n; 
	for(int i=1; i*i<=n; i++){
		rec.push_back(i); 
	}
	for(int i=1; i<=n; i++){
		for(auto x: rec){
			if(x==i) continue; 
			if(sqrt(i*x)== int(sqrt(i*x))) cnt+=2; 
		}
	}
	cout<<cnt<<endl;
}
