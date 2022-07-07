#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

vector<int> v;

int arr[MAX];

int main(){
    for(int i=2; i<MAX; i++)
        arr[i]=1;

    for(int i=2; i<MAX; i++)
        for(int j=2; i*j<MAX; j++)
            if(arr[i*j]==1)
                arr[i*j]=0;

    for(int i=3; i<MAX; i++)
        if(arr[i]==1)
            v.push_back(i);

    while(1){
        int n=1;
        scanf("%d", &n);

        if(n==0) break;

        for(int i=0; v[i]<n; i++){
            int a=n-v[i];
            if(arr[a]==1){
                printf("%d = %d + %d\n", n, v[i], a);
                break;
            }
        }
    }

    return 0;
}