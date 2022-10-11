#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i< t ; i++){
        int n, cnt= 0, c= 0; 
        string s;
        cin>>n>>s;
       	for(int j=1; j<s.size(); j++) if(s[j]!= s[j-1])c= 1; 
       	if(!c) cnt= n; 
       	else{ 
       	
	        for(int j=n/2; j>= 1; j--){
	        	
	        	if(s[j]== s[j-1]) cnt++; 
	        	else break; 
	        	
	        }  
	        if(!cnt) cnt++; 
	        else if(n%2==1) cnt= cnt*2+1; 
	        else cnt*= 2; 
    	}
    	cout<<cnt<<endl; 
    }


    return 0;
}