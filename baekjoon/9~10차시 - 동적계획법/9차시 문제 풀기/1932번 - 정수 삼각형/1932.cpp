#include <iostream>

using namespace std;

int square[501][501];

int main(){
    int n, ans=0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            scanf("%d", &square[i][j]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1)
                square[i][j]+=square[i-1][1];

            else if(i==j)
                square[i][j]+=square[i-1][j-1];

            else
                square[i][j]=max(square[i-1][j], square[i-1][j-1])+square[i][j];
            
            ans=max(ans, square[i][j]);
        }
    }

    printf("%d", ans);

    return 0;
}