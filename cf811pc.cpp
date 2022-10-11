#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 10004
#define mod 998244353
#define mp make_pair

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int s; 
		cin>>s; 
		vector<int> prx(10); 
		int j= 1; 
		prx[0]= 0; 
		for(int i=9; i>=1; i--){
			prx[j]+= prx[j-1]+i; 
			j++; 
		}
		int x, rec; 
		for(int i=1; i<10; i++){
			if(prx[i]>= s){
				x= s-prx[i-1]; 
				rec= i; 
				break; 
			}
		}
		string ss= ""; 
        
		int z= 9; 
		for(int i=0; i<rec-1; i++){
			ss+= to_string(z); 
			z--; 
			//cout<<z<<endl;
		}
		ss+= to_string(x);
		reverse(ss.begin(), ss.end()); 
		cout<<ss<<endl;
	}
}
