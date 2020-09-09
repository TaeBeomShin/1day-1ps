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
//기약분수로 나타내는법. 분모의 최대공배수를 만들고 이를통해 연산실시
//나온 값의 최대공약수를 구해서 나누어준다.
	int bunja,bunmo;
	bunmo=y1*y2;
	bunja=x1*y2+x2*y1;
//최대공약수를 구해서 각각에 나누어준다.(최대공약수 구하려면?

	int g = gcd(bunmo,bunja);
//유클리드 호제법으로 최대공약수를 구해야한다. 아니면 시간초과나왐. 
	bunmo=bunmo/g;bunja=bunja/g;
	cout<<bunja<<" "<<bunmo;

}
