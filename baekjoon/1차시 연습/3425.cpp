#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000000000 // MAX ����(10^9)

typedef long long ll;

using namespace std;

stack<ll> s; // ����
vector<string> vec; // ��ɾ� ����
vector<ll> num; // NUM�� �� ���� ���� ����

int NUM(ll a){
    s.push(a);

    return 0;
}

int POP(){
    if(s.empty()) return 1;

    s.pop();
    return 0;
}

int INV(){
    if(s.empty()) return 1;

    ll a = -s.top();
    s.pop();
    s.push(a);
    return 0;
}

int DUP(){
    if(s.empty()) return 1;
    s.push(s.top());
    return 0;
}

int SWP(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    ll b = s.top();
    s.pop();

    s.push(a);
    s.push(b);
    return 0;
}

int ADD(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    a += s.top();

    s.pop();
    s.push(a);
    return 0;
}

int SUB(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    a = s.top() - a;
    
    s.pop();
    s.push(a);
    return 0;
}

int MUL(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    a *= s.top();

    s.pop();
    s.push(a);
    return 0;
}

int DIV(){
    int ch=0;

    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(a==0) return 1;
    if(a<0) ch++;

    if(s.empty()) return 1;
    ll b = s.top();
    s.pop();

    if(b<0) ch++;

    b/=a;
    if(ch==1) s.push(-abs(b));
    else s.push(abs(b));
    
    return 0;
}

int MOD(){
    int ch=0;

    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(a==0) return 1;

    if(s.empty()) return 1;
    ll b = s.top();
    s.pop();

    if(b<0) ch++;

    b%=a;
    if(ch==1) s.push(-abs(b));
    else s.push(abs(b));
    
    return 0;
}

int main(){
    string str; 
    ll n;
    int x, y, checkNum, errorCh; // �ݺ� Ƚ��, �� �Է� ����, NUM�� �� ������ ���� ��ġ, ERROR üũ

    while(1){
        errorCh = 0;

        // ��ɾ� �Է� (END�� QUIT ���� ������)
        while(1){
            cin >> str;
            if(str=="NUM"){
                cin >> n;
                num.push_back(n);
            }
            if(str=="END") break;
            if(str=="QUIT") return 0;
            vec.push_back(str); // ��ɾ� ���Ϳ� push_back
        }

        cin >> x; // �ݺ� Ƚ�� �Է�

        // ���� �Է�
        while(x>0){
            checkNum=0;

            cin >> y; s.push(y);

            // ��ɾ� ������ŭ �ݺ�
            for(int i=0; i<vec.size(); i++){
                if(vec[i]=="NUM"){
                    errorCh=NUM(num[checkNum]);
                    checkNum++;
                }
                else if(vec[i]=="POP") errorCh=POP();
                else if(vec[i]=="INV") errorCh=INV();
                else if(vec[i]=="DUP") errorCh=DUP();
                else if(vec[i]=="SWP") errorCh=SWP();
                else if(vec[i]=="ADD") errorCh=ADD();
                else if(vec[i]=="SUB") errorCh=SUB();
                else if(vec[i]=="MUL") errorCh=MUL();
                else if(vec[i]=="DIV") errorCh=DIV();
                else if(vec[i]=="MOD") errorCh=MOD();

                // ���� üũ (������ ������� �ʰ� MAX������ ũ�ų� -MAX������ ���� ���)
                if(!s.empty() && (s.top()>MAX || s.top()<-MAX)) errorCh=1;
                if(errorCh) break;
            }

            // ERROR�̰ų� ���� ũ�Ⱑ 1�� �ƴ� ���, ERROR ���
            if(errorCh || s.size()!=1) printf("ERROR\n");
            else printf("%d\n", s.top()); // �ƴ� ���, ������ ���� ���� �� ���

            while(!s.empty()) s.pop(); // ���� ����

            x--;
        }

        // ���� ����
        vec.clear();
        num.clear();
        printf("\n");
    }

    return 0;
}