#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int arr[100001];

int main()
{
    ll N,M; cin>>N>>M;
    for (int i = 0; i < N; i++) cin>>arr[i];
    ll l = 0,r = M * arr[N-1] ;
    ll mn=1e19;
    while (l <= r){
        ll mid = (l + r) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++)sum += (mid / arr[i]);
        if (sum >= M){
            mn = min(mn,mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout<<mn;
}

