#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 9223372036854775807
#define mod 998244353
#define mp make_pair

using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int r, c; 
	cin>>r>>c;
	if(r==1|| c==1|| r==15|| c==15) cout<<"black"<<endl;
	else if(r==2|| c==2|| r==14|| c==14)cout<<"white"<<endl;
	else if(r==3|| c==3|| r==13|| c==13)cout<<"black"<<endl;
	else if(r==4|| c==4|| r==12|| c==12)cout<<"white"<<endl;
	else if(r==5|| c==5|| r==11|| c==11)cout<<"black"<<endl;
	else if(r==6|| c==6|| r==10|| c==10)cout<<"white"<<endl;
	else if(r==7|| c==7|| r==9|| c==9)cout<<"black"<<endl;
	else cout<<"white"<<endl;
 }
