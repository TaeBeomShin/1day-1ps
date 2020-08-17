#include<iostream>
#include<cmath>

using namespace std;
//1.n까지 범위의 소수는 root(N)을 넘지않는다. 
//2.boolean 형태로 해당 숫자가 소수인지 저장한다. 

int main(){
	int begin,end;
	
	cin>>begin>>end;
	
	bool c[end+1]={true,true};//1은 소숙 아니 
	
	for(int i=2;i<=sqrt(end);i++){
		if(c[i]==false){
			for(int j=i*2;j<=end;j+=i){
				c[j]=true;
			}
		}
	}
	for(long long i=begin;i<=end;i++)
		if(c[i]==false) cout<<i<<"\n"; 
	return 0;
} 
