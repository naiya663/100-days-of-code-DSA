#include <stdio.h>

int main() {
    int n,x;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&x);

    int l=0,r=n-1,lb=n,ub=n;

    while(l<=r) {
        int mid=(l+r)/2;
        if(arr[mid]>=x) lb=mid, r=mid-1;
        else l=mid+1;
    }

    l=0,r=n-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(arr[mid]>x) ub=mid, r=mid-1;
        else l=mid+1;
    }

    printf("%d %d",lb,ub);
    return 0;
}