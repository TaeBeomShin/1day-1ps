#include<bits/stdc++.h>
using namespace std;
typedef struct C {
    int n, g, s, b,r;
} C;
int compare(C c1, C c2)
{
    if (c1.g != c2.g)
        return c1.g > c2.g;
    if (c1.s != c2.s)
        return c1.s > c2.s;
    if (c1.b != c2.b)
        return c1.b > c2.b;
}
int main()
{
    C arr[1000];
    int N, K;cin>>N>>K;
    for (int i = 0; i < N; ++i) cin>>arr[i].n>>arr[i].g>>arr[i].s>>arr[i].b;
        
    sort(arr, arr + N, compare);
    int i = 0;
    while (i < N)
    {
        int j = i;
        while (j < N && arr[j].g == arr[i].g && arr[j].s == arr[i].s && arr[j].b == arr[i].b)
        {
            arr[j].r = i;
            ++j;
        }
        i = j;
    }
    for(int i=0;i<N;++i)
    {
        if (arr[i].n == K)
            cout<<arr[i].r+1;
    }
}

