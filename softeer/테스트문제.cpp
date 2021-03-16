#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    string n;cin>>n;
    int num=stoi(n);

    int ans=0;
    for(int i=1;i<=num;i++){
    	int temp=i;
        while(temp>0){
            if(temp%10==3||temp%10==6||temp%10==9) ans++;
            temp/=10;
        }
    }
    cout<<ans;
    return 0;
}
