#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000000000

typedef long long ll;
using namespace std;

vector<ll> v;
vector<string> vs;
stack<ll> s;

bool NUM(ll x){
    s.push(x);
    return true;
}

bool POP(){
    if(s.empty())
        return false;
    
    s.pop();
    return true;
}

bool INV(){
    if(s.empty())
        return false;

    ll n=s.top();

    s.pop();
    s.push(-n);
    return true;    
}

bool DUP(){
    if(s.empty())
        return false;
    
    s.push(s.top());
    return true;
}

bool SWP(){
    if(s.empty())
        return false;
    ll n1=s.top();
    s.pop();

    if(s.empty())
        return false;
    ll n2=s.top();
    s.pop();

    s.push(n1);
    s.push(n2);

    return true;
}

bool ADD(){
    if(s.empty())
        return false;
    ll n1=s.top();
    s.pop();

    if(s.empty())
        return false;
    ll n2=s.top()+n1;
    s.pop();

    s.push(n2);

    return true;
}

bool SUB(){
    if(s.empty())
        return false;
    ll n1=s.top();
    s.pop();

    if(s.empty())
        return false;
    ll n2=s.top()-n1;
    s.pop();

    s.push(n2);

    return true;
}

bool MUL(){
    if(s.empty())
        return false;
    ll n1=s.top();
    s.pop();

    if(s.empty())
        return false;
    ll n2=s.top()*n1;
    s.pop();

    s.push(n2);

    return true;
}

bool DIV(){
    int cnt=0;
    if(s.empty())
        return false;
    ll n1=s.top();
    s.pop();

    if(n1==0) return false;

    if(s.empty())
        return false;
    ll n2=s.top();
    s.pop();

    if(n1<0)
        cnt++;
    if(n2<0)
        cnt++;

    ll r=n2/n1;
    if(cnt==1)
        r=-(abs(r));
    else
        r=abs(r);

    s.push(r);

    return true;
}

bool MOD(){
    int cnt=0;
    if(s.empty())
        return false;
    ll n1=s.top();
    s.pop();

    if(n1==0) return false;

    if(s.empty())
        return false;
    ll n2=s.top();
    s.pop();

    if(n2<0)
        cnt=1;

    ll r=n2%n1;
    if(cnt==1)
        r=-(abs(r));
    else
        r=abs(r);

    s.push(r);

    return true;
}

int main(){
    string str;

    while(1){
        while(1){
            cin >> str;
            if(str=="NUM"){
                ll n;
                scanf("%lld", &n);
                v.push_back(n);
            }

            vs.push_back(str);

            if(str=="QUIT")
                return 0;
            if(str=="END")
                break;
        }

        int x;
        scanf("%d", &x);

        while(x>0){
            ll a;
            int numVector=0;
            bool check=true; // 초기화 잘할 것
            scanf("%lld", &a);
            s.push(a);

            for(int i=0; i<vs.size(); i++){
                if(vs[i]=="NUM") check=NUM(v[numVector++]);
                else if(vs[i]=="POP") check=POP();
                else if(vs[i]=="INV") check=INV();
                else if(vs[i]=="DUP") check=DUP();
                else if(vs[i]=="SWP") check=SWP();
                else if(vs[i]=="ADD") check=ADD();
                else if(vs[i]=="SUB") check=SUB();
                else if(vs[i]=="MUL") check=MUL();
                else if(vs[i]=="DIV") check=DIV();
                else if(vs[i]=="MOD") check=MOD();

                if(!s.empty() && (s.top()>MAX || s.top()<-MAX))
                    check=false;
                if(!check) break;
            }

            if(!check || s.size()!=1) printf("ERROR\n");
            else printf("%lld\n", s.top());

            while(!s.empty()) s.pop();

            x--;
        }

        v.clear();
        vs.clear();
        printf("\n");
    }

    return 0;
}