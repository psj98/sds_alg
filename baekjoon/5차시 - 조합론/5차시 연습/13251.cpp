#include <iostream>

using namespace std;

int arr[50];

int main(){
    int m, k;
    double b = 0, sum1 = 0, sum2 = 1.0;
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d", &arr[i]);
        b += arr[i];
    }

    scanf("%d", &k);

    if(m == 1 || k == 1){
        printf("1.0");
        return 0;
    }

    for(int i = 0; i < m; i++){
        double a = 1.0;
        for(int j = 0; j < k; j++)
            if(arr[i] >= k)
                a *= (arr[i] - j);
                
        if(arr[i] >= k)
            sum1 += a;
    }

    for(int i = 0; i < k; i++)
        sum2 *= (b - i);

    double ans = sum1 / sum2;

    printf("%.16f", ans);

    return 0;
}