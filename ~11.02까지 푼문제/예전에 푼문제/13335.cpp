#include<bits/stdc++.h>
using namespace std;

int t[11]={0,};
bool check[11];
int main(){
	int n,w,l;//n:�ٸ��� �ǳʴ� Ʈ���� ��,w:�ٸ� ����,l:�ٸ��� �ִ�����.
	cin>>n>>w>>l;
	int max=n;
	queue <int> trucks;
	queue <int> current;
	while(n--){
		int truck;
		cin>>truck;
		trucks.push(truck);
	}

	
	int count=0;
	int currentsum=0;
	int number=1;//�ٸ��� �ö� Ʈ���� ����. 
	int pass=0;

	while(true){//��� Ʈ���� ������ ������.
		//���� �ٸ��� �ִ� ������ ���� ������������ ī��Ʈ�ؾ���.
		//������������ ���� ��ٸ� ó���������. 
		count++;
		for(int i=1;i<=10;i++){
			if(check[i]==true) t[i]++;
		}
		 
		if(currentsum+trucks.front()<=l&&!trucks.empty()){//�� �����ص� �Ǵ� ���. 
		 	current.push(trucks.front());
		 	currentsum+=trucks.front();
		 	check[number]=true;//���° Ʈ������ üũ�Ѵ�. 
		 	t[number]=1;//���� �� Ʈ���� �ð��� ���.
		 	number++;
		 	trucks.pop();
		}
		for(int i=1;i<=number;i++){
		 	if(t[i]==w){
			 //�ٸ��� �������� ���� �Ǿ��ٸ�. current���� ����, �ð��� 0����. 
		 		currentsum-=current.front();
				current.pop();
				check[i]=false;
		 		t[i]=0;
		 		pass++;
			 }
		 }
		 if(pass==max){
		 	break;
		 }
	}
	cout<<count+1;
	
	return 0;
}
