#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int priorty(char c){
    if (c == 'm' or c == 'M')
        return 1;
    return -1;
}

bool is_op(char c){
    return (c == 'm' or c == 'M');
}

void process(stack<int> &stk, char op){
    int r = stk.top();
    stk.pop();
    int l = stk.top();
    stk.pop();

    if (op == 'm')
        stk.push(min(r, l));
    else if (op == 'M')
        stk.push(max(r, l));
}

int evaluare(string s){
    stack<int> val;
    stack<char> op;

    for (int i = 0; i < s.len; i++){
        if (s[i] == '(')
            op.push('(');

        else if (s[i] == ')'){
            while (op.top() != '('){
                process(val, op.top());
                op.pop();
            }
            op.pop();
        }

        else if (is_op(s[i])){
            char curr = s[i];
            while (!op.empty() and priorty(op.top()) >= priorty(curr)){
                process(val, op.top());
                op.pop();
            }
            op.push(curr);
        }


        else{
            int num = 0;
            while (i < s.len and isdigit(s[i])){
                num = num * 10 + s[i++] - '0';
            }
            --i;
            val.push(num);
        }
    }

    while(!op.empty()){
        process(val, op.top());
        op.pop();
    }

    return val.top();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("emm.in");
    ofstream cout("emm.out");

    string s;
    cin >> s;
    cout << evaluare(s);

    return 0;
}
