#include<iostream>
#include<cmath>

using namespace std;
//1.n���� ������ �Ҽ��� root(N)�� �����ʴ´�. 
//2.boolean ���·� �ش� ���ڰ� �Ҽ����� �����Ѵ�. 

int main(){
	int begin,end;
	
	cin>>begin>>end;
	
	bool c[end+1]={true,true};//1�� �Ҽ� �ƴ� 
	
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
