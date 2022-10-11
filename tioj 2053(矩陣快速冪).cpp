#include<iostream> 
#include<vector>
#include<algorithm> 
#include<string> 
#include<cmath> 
#include<cstring> 
#define ll long long 
#define prime 1000000007
using namespace std; 

struct matrix{
	ll m[2][2]; 
	int r, c;
}; 
matrix ori, res;
void init(){
	memset(res.m, 0, sizeof(res.m)); 
	res.r= 2; res.c= 2; 
	for(int i=0; i<res.r; i++) 
		res.m[i][i]= 1; 
	ori.r=2; ori.c= 2; 

}

matrix multi(matrix x, matrix y){
	matrix mix; 
	memset(mix.m, 0, sizeof(mix.m)); 
	mix.r= x.r, mix.c= y.c; 
	for(int i=0; i<mix.r; i++){
		for(int j=0; j<mix.c; j++){
			for(int k=0; k<mix.c; k++){
				mix.m[i][j]+= (x.m[i][k]*y.m[k][j])%prime; 
				mix.m[i][j]%= prime; 
			}
		}
	}  
	return mix; 
}
int main(){
    
	ll x, x1, a, b, n; 
	cin>>x>>x1>>a>>b>>n; 
	x%= prime, x1%= prime, a%= prime, b%= prime; 
	n-= 2; 
	init(); 

	ori.m[0][0]= b, ori.m[1][0]= a, ori.m[0][1]= 1, ori.m[1][1]= 0; 
	while(n){
		if(n&1) res= multi(res, ori); 
		ori= multi(ori, ori); 
		
		n>>= 1; 
	}
	
	cout<<((res.m[0][0]*x1)%prime+ (res.m[1][0]*x)%prime)%prime<<endl;
}
