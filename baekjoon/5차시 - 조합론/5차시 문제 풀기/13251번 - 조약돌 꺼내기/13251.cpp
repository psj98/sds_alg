#include <iostream>

using namespace std;

int arr[51];

int main(){
    int n=0, m, k;
    double ans;
    scanf("%d", &m);

    for(int i=1; i<=m; i++){
        scanf("%d", &arr[i]);
        n+=arr[i];
    }

    scanf("%d", &k);

    if(m==1 || k==1){
        printf("1.0");
        return 0;
    }
    
    for(int i=1; i<=m; i++){
        double t=1.0;
        if(arr[i]>=k){
            for(int j=0; j<k; j++)
                t*=double(arr[i]-j)/double(n-j);
            ans+=t;
        }
    }

    printf("%.16f", ans);

    return 0;
}