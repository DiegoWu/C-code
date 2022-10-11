#include<iostream>
using namespace std;
long long mypow(long long A,long long B,long long M){ //calculate A^B % M
    A%=M;
    if(M==1) return 0;
    if(B==0) return 1; 
    if(A==0) return 0;
    long long mid=mypow(A,B/2,M);
    if(B%2) return mid*mid%M*A%M;
    else return mid*mid%M;
    
}
int main(){
    long long a,b,c,p=880301;
    cin>>a>>b>>c;
    cout<<mypow(a,mypow(b,c,p-1),p)<<'\n';
}