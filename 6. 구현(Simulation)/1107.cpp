#include<bits/stdc++.h>
using namespace std;

/*
	��� ����� �� Ž���ϱ�. 
	ä�� N���� �̵��ϱ� ���� ��ư�� �ּ� �� �� ������ �ϴ°�?
	
	0~9, +�� -
	
	0���� -�� ������ ä�� �Ⱥ���
	ä���� ���Ѵ� ��ŭ.
	
	N���� �̵��ϱ����� ��� �������ϴ°�?
	
	��� ����� �� Ž���ϱ�. 
*/
int n,m,ans=500001;
bool impossible[10];
int main(){
	cin>>n;cin>>m;
	
	for(int i=0;i<m;i++){
		int num;cin>>num;
		impossible[num]=true;
	}
	//1.���� ����(100)���� ++,--�̵�
	ans=min(ans,abs(n-100)); 
	
	//2.���� ���� ��ư�� ������, ++ -- �̿�. 
	for(int i=0;i<=999999;i++){
		bool possible=true;
		string num=to_string(i);
		for(int i=0;i<num.length();i++){
			if(impossible[num[i]-'0']){
				possible=false;
				break;
			}
		}
		if(!possible) continue;
		ans=min(ans,abs(i-n)+int(num.length()));
	}
	
	cout<<ans;
}
