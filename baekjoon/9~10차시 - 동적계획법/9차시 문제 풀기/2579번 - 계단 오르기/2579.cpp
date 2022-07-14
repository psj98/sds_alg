#include <iostream>
#define MAX 301

using namespace std;

int arr[MAX];
int val[MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    val[1]=arr[1];
    val[2]=arr[1]+arr[2];
    val[3]=max(arr[1]+arr[3], arr[2]+arr[3]);

    for(int i=4; i<=n; i++)
        val[i]=max(val[i-2]+arr[i], val[i-3]+arr[i-1]+arr[i]);

    printf("%d", val[n]);

    return 0;
}