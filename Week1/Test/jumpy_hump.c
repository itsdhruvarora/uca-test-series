// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/jumpy-humpy-5e0231d6/discussion/jumpy-humpy-linear-s-399bbf25/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int st[100000];
    st[n-1] = arr[n-1];
    int x = arr[n-1];
    for(int i=n-2;i>=0;i--) {
        for(int j=i+1;j<n;j++)
        if(arr[i] < arr[j]) {
             st[i]= arr[i]^ st[j];
             break;
        }
    if(st[i] == 0) st[i] = arr[i];
    if(st[i] > x) x = st[i];
    }

  
    printf("%d",x);
    return 0;
}
