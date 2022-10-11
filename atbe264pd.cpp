#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 9223372036854775807
#define mod 998244353
#define mp make_pair

using namespace std;
using P= pair<ll, int>; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	string s, z= "atcoder"; 
	cin>>s; 
	map<char, int> m; 
	for(int i=0; i<7; i++) m[z[i]]= i; 
	int cnt= 0; 
	for(int i=0; i<6; i++){
		for(int j=i+1; j<7; j++){
			if(m[s[j]]< m[s[i]]) swap(s[j], s[i]), cnt++; 
		}
	}
	cout<<cnt<<endl;
	
 }
