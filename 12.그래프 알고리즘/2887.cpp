#include<bits/stdc++.h>
using namespace std;

int root[100001];
void merge(int a,int b){
	x=find(x);
	y=find(y);
	//�� ���� ���� ��Ʈ�� �ǰ�. 
	if(x>y) swap(x,y);
	root[y]=x;
}

void find(int a){
	if(a==root[a]) return a;
	else return find(root[a]);
}
int main(){
	int n;cin>>n;
	/*
		��� �༺�� �ͳη� �����ϴ� �ּҺ��.
		�� �༺ ������ min( abs(xa-xb),abs(ya-yb),abs(za-zb))
		
		�ּ� ����� ������ �ϳ��� ����, ����Ŭ�� �Ǹ� ����
		-> ����Ŭ���� ��� �Ǻ�? �θ� �޶����. 
		
		1. ���� �� �ִ� ������ �� n^2 -> time out. 
		2. x��ǥ, y��ǥ, z��ǥ ����(�༺ ��ȣ�� ������ ����, �̿��� ���� ������ ���� ���� )
			(greedy ����) 
	*/
	 
}
