#include<iostream>
#include<vector> 
#include<cstring> 
#include<cmath> 

using namespace std; 

int main(){
	string l, l1; 
	cin>>l>>l1;
	vector<vector<int> > v(l.size()+1, vector<int>(l1.size()+1)); 
	for(int i=1; i<l.size()+1; i++){
		for(int j=1; j<l1.size()+1; j++){
			if(l[i-1]== l1[j-1]) v[i][j]= max(v[i-1][j-1]+1, max(v[i-1][j], v[i][j-1])); 
			else v[i][j]= max(v[i-1][j], v[i][j-1]); 
		}
	}
	cout<<v[l.size()][l1.size()]<<endl;
}