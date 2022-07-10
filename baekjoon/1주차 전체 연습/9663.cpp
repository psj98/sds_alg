#include <iostream>

using namespace std;

int arr[15]={0};
int n, ans=0;

int check(int a){
    for(int i=0; i<a; i++){
        if(arr[a]==arr[i] || a-i==abs(arr[a]-arr[i]))
            return 0;
    }

    return 1;
}

void nqueen(int a){
    if(a==n) ans++;
    else{
        for(int i=0; i<n; i++){
            arr[a]=i;
            if(check(a))
                nqueen(a+1);
        }
    }
}

int main(){
    scanf("%d", &n);

    if(n==1){
        printf("1");
        return 0;
    }

    if(n==2 || n==3){
        printf("0");
        return 0;
    }

    nqueen(0);
    printf("%d", ans);

    return 0;
}