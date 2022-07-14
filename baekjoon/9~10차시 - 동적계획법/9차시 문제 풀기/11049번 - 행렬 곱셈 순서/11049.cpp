// error
#include <iostream>
#define MAX 501

using namespace std;

int dp[MAX][2];
int row[MAX], col[MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d %d", &row[i], &col[i]);

    for(int i=1; i<n; i++){ // step
        for(int j=1; i+j<n; j++){
            dp[j][i+j]=987654321;
            for(int k=j; k<j+i; k++){ // mid
                dp[j][i+j]=min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]+row[j]*col[i+j]*col[k]);
            }
        }
    }

    printf("%d", dp[1][n]);

    return 0;
}