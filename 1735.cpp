#include<iostream> 

using namespace std;

int gcd(int a,int b)
{
	int c;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
//���м��� ��Ÿ���¹�. �и��� �ִ������� ����� �̸����� ����ǽ�
//���� ���� �ִ������� ���ؼ� �������ش�.
	int bunja,bunmo;
	bunmo=y1*y2;
	bunja=x1*y2+x2*y1;
//�ִ������� ���ؼ� ������ �������ش�.(�ִ����� ���Ϸ���?

	int g = gcd(bunmo,bunja);
//��Ŭ���� ȣ�������� �ִ������� ���ؾ��Ѵ�. �ƴϸ� �ð��ʰ�����. 
	bunmo=bunmo/g;bunja=bunja/g;
	cout<<bunja<<" "<<bunmo;

}
