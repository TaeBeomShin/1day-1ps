#include <cstdio>
#include <cstring>

#define MOD 10301

inline void add( int &a, int b ) {
    a += b;
    if( a >= MOD ) a -= MOD;//%MOD 연산이 비효율적이여서 -를 통해 사용한 듯 함. 
}

int N, A, B;
int memoL[1024][1024][2];
int memoR[1024][1024][2];

int recR( int n, int rub, bool ok ) {//n: 전체길이, rub: 버릴부분?, ok 방문한 부분인지 체크. 
    int &ret = memoR[n][rub][ok];
    if( ret != -1 ) return ret;

    ret = ok;//방문 여부 체크. 
    if( rub <= n ) add( ret, recR(n-rub, rub, true) );
    if( n ) add( ret, recR(n-1, rub+1, false) );

    return ret;
}

int recL( int n, int rub, bool ok ) {//n: 전체길이, rub: 버릴부분?, ok 방문한 부분인지 체크. 
    int &ret = memoL[n][rub][ok];
    if( ret != -1 ) return ret;

    ret = 0;
    if( ok ) add( ret, recR(n, B, true) );
    if( rub <= n ) add( ret, recL(n-rub, rub, true) );
    if( n ) add( ret, recL(n-1, rub+1, false) );

    return ret;
}

int main( void ) {
    memset( memoL, -1, sizeof memoL );//왼쪽 배열을 -1로 초기화시킨다. 
    memset( memoR, -1, sizeof memoR );//오른쪽 배열을 -1로 초기화시킨다. 

    scanf( "%d%d%d", &N, &A, &B );//N,A,B값을 받는다. 

    printf( "%d\n", recL( N-A-B, A, true ) );

    return 0;
}
