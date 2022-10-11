#include<iostream>
#include<vector>
#include<cmath> 
using namespace std; 

int main(){
	int arr[3][1003]; 
	int n, a, s= 0; 
	cin>>n; 
	for(int i=2; i<n+2; i++){
		cin>>arr[i%3][i]; 
		s+= arr[i%3][i]; 
		for(int j=i-1; j>=2; j--){
			arr[j%3][i]= max(arr[j%3][j]+min(arr[(j+1)%3][i-1], arr[(j+2)%3][i]), arr[i%3][i]+min(arr[(j+1)%3][i-1], arr[j%3][i-2])); 
		}
	}
	cout<<arr[2][n+1]<<" "<<s-arr[2][n+1]<<endl;
	
}