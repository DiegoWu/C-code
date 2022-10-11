#include<iostream>
#include<vector> 
#include<cstring> 
#include<cmath> 

using namespace std; 

int main(){
	string l, l1; 
	cin>>l>>l1;
	vector<vector<int> > v(2, vector<int>(l1.size()+1)); 
	int ans= 0; 
	for(int i=1; i<l.size()+1; i++){
		for(int j=i; j<l1.size()+1; j++){
			if(l[i-1]== l1[j-1]) v[i%2][j]=v[(i-1)%2][j-1]+1;  
			else v[i%2][j]= v[(i-1)%2][j-1]; 
			ans = max(ans, v[i%2][j]); 
		}
	}
	cout<<ans<<endl;
}