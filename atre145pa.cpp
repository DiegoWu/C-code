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
	cin>>n;
	string s, ans= "Yes"; 
	cin>>s; 

	if(s[0]== 'A'&& s[n-1]=='B') ans= "No"; 
	if(n==2&& s[0]=='B'&& s[1]=='A') ans= "No";  
	cout<<ans<<endl;
}
