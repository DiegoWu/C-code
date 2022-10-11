#include<sstream>
#include<iostream>
#include<vector> 
#include<cmath>
using namespace std; 

int main(){

	int x= 14, z= 0;
	while(x!= 1){
		z++;
		x>>= 1; 
	}
	cout<<z<<endl;
	cout<<(3<<1); 
	
}