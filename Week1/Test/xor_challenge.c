// QUES: https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/

#include <stdio.h>
long long max(long long a, long long b){ 
    return a > b ? a : b;
}
int main(){
    long long n;
    scanf("%lli", &n);
    long long cnt = 0;
    long long g = n;
    while(g!=0){
        cnt++;
        g/=2;
    }

    long long ans = 0;
    for(int i=0; i<pow(2, cnt); i++){
        long long x = i ^ n;
        if(x ^ i == n){
            ans = max(ans, x*i);
        }
    }

    printf("%lli", ans);
}

