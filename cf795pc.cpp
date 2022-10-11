#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#include<cmath> 
#include<map>
#define ll long long 
#define maxn 4005
#define mp make_pair
#pragma GCC target("AVX")
#pragma GCC optimize("-O2")
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, k, pos= 0, x= 0, p= -1; 
		ll cnt= 0; 
		cin>>n>>k; 
		string s; 
		cin>>s; 
		map<char, int> m; 
		m[s[0]]++; 
		for(int i=1; i<n; i++) {
			m[s[i]]++; 
			if(!x&&s[i]== '1'){
				p= i; 
				x= 1; 
			}
			if(s[i]== '1') pos= i; 
			if(s[i]== '1'&& s[i-1]== '1') cnt+= 11; 
			else if(s[i]=='1'&&s[i-1]== '0') cnt+= 1; 
			else if(s[i]== '0'&& s[i-1]== '1') cnt+= 10; 
		}
		int pin= 0; 
		if(m['1']> 0){
			if(s[n-1]== '0'){
				if(k>= n-pos-1) {
					k-= n-pos-1; 
					cnt-= 10; 
					pin= 1;
					if(s[0]== '1'&&m['1']==1) cnt++; 
				}
			} 
			if(s[0]== '0'&& p!= -1&& p<= k){
				if(m['1']== 1&& pin) cnt+= 1;
				else if(m['1']== 1&& s[n-1]== '1') cnt++;
				cnt-= 1; 
			}
		}
		cout<<cnt<<endl;
	}

	
}
