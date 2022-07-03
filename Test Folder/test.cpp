#include <iostream>

using namespace std;

int main(){
    char line[30];
    string a;
    int t[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cin.getline(line, 30);
    getline(cin, a);

    cout << line << '\n';
    cout << a << '\n';
    
    int row = sizeof(t)/sizeof(t[0]);
    int col = sizeof(t[0])/sizeof(int);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cout << t[i][j] << endl;

    return 0;
}