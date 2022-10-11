#include<bits/stdc++.h>

#define ll long long 
#define maxn 3003
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin>>n; 
	string ans= "correct"; 
	vector<string> v(n); 
	for(int i=0; i<n; i++) cin>>v[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j) continue; 
			if(v[i][j]=='W'){
				if(v[j][i]!= 'L') ans= "incorrect"; 
			}
			else if(v[i][j]=='D'){
				if(v[j][i]!= 'D') ans= "incorrect"; 
			}
			else{
				if(v[j][i]!= 'W') ans= "incorrect"; 
			}
		}
	}
	cout<<ans<<endl;
	
}
