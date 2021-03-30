#include<bits/stdc++.h>
using namespace std;

long long X;
int ansA,ansB;
int main(){
	string a,b;cin>>a>>b;
	int cnt=0;
	for(int i=2;i<=36;i++){//A의 진법 
		//A진법으로 구한 수 
		long long A=0;
		bool possibleA=true;
		for(int j=0;j<a.length();j++){
			if(a[j]-'0'<=9&&a[j]-'0'>=0){
				A+=(a[j]-'0')*pow(i,j);
			}else{
				if(a[j]-'a'+10>=i) possibleA=false;
				A+=(a[j]-'a'+10)*pow(i,a.length()-j-1);
			}
		}
		if(possibleA==false) continue;
		for(int j=2;j<=36;j++){//B의 진법 
			//a 10 b11 c12 d13 e14 f15 g16 hijklmnop25 qrstuvwxyz35
			long long B=0;
			bool possibleB=true;
			if(i==j) continue;
			for(int k=0;k<b.length();k++){
				if(b[k]-'0'<=9&&b[k]-'0'>=0){
					B+=(b[k]-'0')*pow(j,k);
				}else{
					if(b[k]-'a'+10>=j) possibleB=false;
					B+=(b[k]-'a'+10)*pow(j,b.length()-k-1);
				}	
			}
			if(possibleB==false) continue;
			if(A==B&&A>=0){
				X=A;
				ansA=i;
				ansB=j;
				cnt++; 
			}
		}
		
		if(cnt>=2) break;
	}
	if(cnt==0){
		cout<<"Impossible";
	}else if(cnt==1){
		cout<<X<<" "<<ansA<<" "<<ansB;
	}else{
		cout<<"Multiple";
	}
}
