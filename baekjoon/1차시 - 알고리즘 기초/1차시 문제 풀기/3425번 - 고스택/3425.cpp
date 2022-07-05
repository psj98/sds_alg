#include <iostream>
#include <stack>
#include <vector>
#define MAX 1000000000

using namespace std;

stack<long long> s; // 스택
vector<string> v; // 문자열 저장 벡터
vector<long long> n; // NUM일 때, 숫자 저장 벡터

int NUM(long long num){
    s.push(num);

    return 0;
}

int POP(){
    if(s.empty())
        return 1;

    s.pop();

    return 0;
}

int INV(){
    if(s.empty())
        return 1;

    long long num = -s.top();

    s.pop();
    s.push(num);

    return 0;
}

int DUP(){
    if(s.empty())
        return 1;

    s.push(s.top());

    return 0;
}

int SWP(){
    if(s.empty())
        return 1;

    long long num1 = s.top();
    s.pop();

    if(s.empty())
        return 1;

    long long num2 = s.top();
    s.pop();
    s.push(num1);
    s.push(num2);

    return 0;
}

int ADD(){
    if(s.empty())
        return 1;

    long long num = s.top();
    s.pop();

    if(s.empty())
        return 1;

    num += s.top();
    s.pop();
    s.push(num);

    return 0;
}

int SUB(){
    if(s.empty())
        return 1;

    long long num = s.top();
    s.pop();

    if(s.empty())
        return 1;

    num = s.top() - num;
    s.pop();
    s.push(num);

    return 0;
}

int MUL(){
    if(s.empty())
        return 1;

    long long num = s.top();
    s.pop();

    if(s.empty())
        return 1;

    num *= s.top();
    s.pop();
    s.push(num);

    return 0;
}

int DIV(){
    int check = 0;

    if(s.empty())
        return 1;

    long long num1 = s.top();
    s.pop();

    if(num1 < 0)
        check++;

    if(num1 == 0)
        return 1;

    if(s.empty())
        return 1;

    long long num2 = s.top();
    s.pop();

    if(num2 < 0)
        check++;

    num1 = num2 / num1;

    if(check == 1) num1 = -(abs(num1));
    else num1 = abs(num1);

    s.push(num1);

    return 0;
}

int MOD(){
    int check = 0;

    if(s.empty())
        return 1;

    long long num1 = s.top();
    s.pop();

    if (num1 == 0)
        return 1;

    if(s.empty())
        return 1;

    long long num2 = s.top();
    s.pop();

    if (num2 < 0)
        check++;

    num1 = num2 % num1;

    if(check == 1)  num1 = -(abs(num1));
    else num1 = abs(num1);
    
    s.push(num1);

    return 0;
}

int main(){
    string str;
    long long num;
    int x;
    int a;
    int returnNum;
    int numVec;

    while(1){
        // 문자열 입력
        returnNum = 0;
        while (1){
            cin >> str;

            if(str == "NUM"){
                cin >> num;
                n.push_back(num);
            }
            if(str == "QUIT") return 0;
            if(str == "END") break;

            v.push_back(str);
        }

        cin >> x; // 숫자 전체 개수

        // 숫자 입력
        while (x > 0){
            numVec = 0;

            cin >> a;

            s.push(a);

            for(int i = 0; i < v.size(); i++){
                if (v[i] == "NUM") {
                    returnNum = NUM(n[numVec]);
                    numVec++;
                }
                else if (v[i] == "POP") returnNum = POP();
                else if (v[i] == "INV") returnNum = INV();
                else if (v[i] == "DUP") returnNum = DUP();
                else if (v[i] == "SWP") returnNum = SWP();
                else if (v[i] == "ADD") returnNum = ADD();
                else if (v[i] == "SUB") returnNum = SUB();
                else if (v[i] == "MUL") returnNum = MUL();
                else if (v[i] == "DIV") returnNum = DIV();
                else if (v[i] == "MOD") returnNum = MOD();
                
                if(!s.empty() && (s.top() > MAX || s.top() < -MAX))
                    returnNum = 1;
                if(returnNum == 1) break;
            }

            if(returnNum == 1 || s.size() != 1)
                cout << "ERROR\n";
            else
                cout << s.top() << "\n";

            while(!s.empty())
                s.pop();

            x--;
        }

        n.clear();
        v.clear();
        cout << "\n";
    }

    return 0;
}