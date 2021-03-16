#include<iostream>
#define ll long long
const int mod = 1000000007;
using namespace std;

long long k,p,n;
ll fastpow(ll x, ll y)
{
	ll ret = k;
	while (y > 0)
	{
		if (y & 1)
		{
			ret *= x;
			ret %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
    return ret;
}

int main(int argc, char** argv)
{
	cin>>k>>p>>n;
	
	long long ans=fastpow(p,n);
	
	cout<<ans;
	return 0;
}
