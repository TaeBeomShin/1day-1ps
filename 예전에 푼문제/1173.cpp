#include<iostream>

using namespace std;

int main(){
	int N,m,M,T,R;
//	1�и��� ��� �޽� �߿� ����.
//	�ƹ��� X������ 1�е��� ����ϰ� �ƹ��� X+T����, M�� ������ȵ�.
//	�޽����ϸ� �ƹ��� R��ŭ �����Ѵ�.
//	ó�� �ƹ��� m, ��� N���ϴµ� �ɸ��� �ð��� �ּڰ�.
	cin>>N>>m>>M>>T>>R; //N:��ð�, m:ó���ƹ�&�ּҸƹ�,M:�ִ�ƹ�,T:�ƹ����� ,R:�ƹڰ���. 
	
	int count=0;
	int exercise=0;
	int current=m;
//	��� ������ ���°��
//	1.��� �ϸ� �ٷ� M�� �Ѵ°��m+T>=M
//	2.��ϰ� �޽����ϸ� �ٷ� m���� �������� ���.
	if(m+T>M){
		cout<<-1;
	}
	else{
		while(exercise!=N){
			if(current+T<=M){
				current=current+T;
				exercise++;
			}
			else{//current+T>M;
				current=current-R;
				if(current<m) current=m;
			}
			count++;
//			cout<<current<<" "<<count<<" "<<exercise<<"\n";
		}
		cout<<count;
	}
}
