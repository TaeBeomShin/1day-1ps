#include<bits/stdc++.h>
using namespace std;
/*
	���� ����Ʈ�� ���࿡�� �湮�� �� �ִ� ĭ�� �ִ밳��.
	1. 2ĭ���� 1ĭ ������
	2. 1ĭ���� 2ĭ ������
	3. 1ĭ �Ʒ��� 2ĭ ������
	4. 2ĭ �Ʒ��� 2ĭ ���� ��
	
	n�� m�� 20�� ���� �۰ų� ���� �ڿ���. O(1)���� ã�ƾ���. 
*/
int main(){
	int n,m;cin>>n>>m;
	//�� 4���� case; 
	if(n==1) cout<<1;
	else if(n==2) cout<<min(4,(m+1)/2);
	else if(n>=3){
		if(m<=6) cout<<min(4,m);
		else cout<<m-2;
	}
}
