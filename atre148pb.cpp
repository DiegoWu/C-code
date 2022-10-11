#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int n; 
	cin>>n; 
	string s; 
	cin>> s; 
	string temp, ans= s, tt="", back= "";  
	for(int i=0; i<n; i++){
		temp= ""; 
		if(s[i]== 'p'){
			tt= s.substr(0, i); 
			while(n>=i){
				for(int j=n-1; j>=i; j--){
					if(s[j]=='p') temp+= 'd'; 
					else temp+= 'p'; 
				}
				temp= tt+temp+back; 
				if(temp< ans) ans= temp; 
				//cout<<temp<<" "<<ans<<" "<<back<<endl;
				temp= ""; 

				back= s[n-1]+back; 
				n--; 
			}
 			break; 
		}
		
	}
	cout<<ans<<endl;
}
