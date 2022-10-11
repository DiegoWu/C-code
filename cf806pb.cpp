#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		ll sum= 0; 
		cin>>n; 
		string s; 
		cin>>s; 
		map<char, int> m; 
		for(int i=0; i<n; i++){
			if(m[s[i]]==0){
				sum+=2, m[s[i]]= 1; 
			}
			else sum++; 
		}
		cout<<sum<<endl;
		
	}
}
