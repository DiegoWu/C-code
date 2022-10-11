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
		
		string s; 
		cin>>s; 
		if((s[0]== 'y'|| s[0]== 'Y')&& (s[1]== 'E'|| s[1]== 'e')&& (s[2]== 'S'|| s[2]== 's')) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
