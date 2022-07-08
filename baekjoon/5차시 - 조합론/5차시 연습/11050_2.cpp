// ÆÄ½ºÄ® »ï°¢Çü
#include <iostream>

using namespace std;

int arr[11][66];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < 11; i++)
        arr[i][0] = arr[i][i] = 1;

    for(int i = 2; i < 11; i++)
        for(int j = 1; j < i; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

    printf("%d", arr[n][k]);

    return 0;
}