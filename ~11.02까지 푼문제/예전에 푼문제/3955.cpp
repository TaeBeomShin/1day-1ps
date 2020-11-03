#include<iostream>

using namespace std;

typedef long long ll;

typedef struct candy{
	ll s,t,r;
}candy;

ll gcd(ll a,ll b){
	while(b!=0){
		ll r=a%b;
		a=b;
		b=r;
	}
	return a;
}
candy uclid(ll K,ll C){
	ll s0=1,t0=0,r0=K;
	ll s1=0,t1=1,r1=C;
	
	ll temp;
	
	while(r1!=0){
		ll q=r0/r1;
		
		temp=r0-r1*q;
		r0=r1;
		r1=temp;
		
		temp=s0-s1*q;
		s0=s1;
		s1=temp;
		
		temp=t0-t1*q;
		t0=t1;
		t1=temp;
	}
	struct candy result ={s0,t0,r0};
	return result;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	ll K,C;
//X,Y는 1에서 10^9 이하. 
	cin>>t;
//KX+1=CY, -KX+CY=1;
//1. gcd(A,B)=1이여야 하고, 아니면 불가능.(s,t)를 이용해서 x0,y0를 구해야함.
 
	for(int i=0; i<t;i++){
		cin>>K>>C;
		candy temp=uclid(-K,C);
		
		if(abs(gcd(K,C))!=1){
			cout<<"IMPOSSIBLE"<<"\n";
		}
		else{
			long x=temp.s*1/temp.r;
			long y=temp.t*1/temp.r;
			
			while(y<=0||x<=0){
				x+=C;
				y-=K;
				if(y>1e9) break;
			}
			
			if(y>1e9){
				cout<<"IMPOSSIBLE"<<"\n";
			}
			else{
				cout<<y<<"\n";
			}
		}
}
	
	return 0;
}
