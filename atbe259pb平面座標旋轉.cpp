#include<bits/stdc++.h>

#define ll long long 
#define maxn 92233720368547
#define mod 1000000007
#define mp make_pair

using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	double a, b, d; 
	double pi1 = M_PI;
	cin>>a>>b>>d;
	d= d*pi1/180.0; 

	double s = sin(d); // angle is in radians
	double c = cos(d);
	//cout<<s<<endl;
	double xnew = a * c - b * s;
	double ynew = a * s + b * c;
	cout<<fixed<<setprecision(15)<<xnew<<" "<<ynew<<endl;
}

