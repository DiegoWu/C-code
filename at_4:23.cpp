#include<bits/stdc++.h>

using namespace std; 

void solve(){
	int n, k; 
	cin>>n>>k; 

	vector<string>s(n); 
	
	for(int i=0; i<n; i++){
		string a; 
		cin>>a; 
		s[i]= a;
	}
	int ans= 26; 
	vector<vector<int> > v(26, vector<int>(n)); 
	vector<int> count(26); 
	for(int i=97; i<= 122; i++){
		int c= 0; 
		vector<int> temp(n); 
		for(int j=0; j<n; j++){
			for(int z=0; z<s[j].size(); z++){
				if(s[j][z]== i){ 
					c++;
					temp[j]= 1; 
				}
			}
		}
		if(c< k) ans--;
		else{
			for(int h=0; h<n; h++){
			
				count[i-97]+= temp[h]; 
			}
			for(int h=0; h<n; h++) v[i-97][h]= count[i-97];
		}
	}

	//for(int j=0; j<26; j++) cout<<count[j]<<endl;
	int gg= 0; 
	for(int j=0; j<26; j++){
		if(count[j]> k){
			int ccc= 0; 
		for(int kk= gg+1; kk<n; kk++){
			for(int z= j+1; z<26; z++){
				if(v[z][kk]>= k) ccc++; 
			}
		}
		gg++; 
		if(ccc> k) ans--; 
		}
	}
    
    
	cout<<ans<<endl; 

}

int main(){

	solve(); 
	return 0; 
}
