#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

int main(){
	int E,S,M;
	cin>>E>>S>>M;//����,�¾�,��. �� ���� �����Ѿ� �������� 1�� ������. 
	
	int a=1,b=1,c=1;
	int count =1;
	//�ݺ����� �̿��� Ǯ��. 
	while(a!=E||b!=S||c!=M){
		a++;b++;c++;
		if(a>15) a=1;
		if(b>28) b=1;
		if(c>19) c=1;
		count++;
	}
	cout<<count;

	return 0;
}
