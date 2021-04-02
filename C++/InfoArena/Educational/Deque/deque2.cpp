/******** Ordered Set ********
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int INF = INT_MAX;
ll t, n, k, num, ans;

struct Node{
    int value;
    int idx;
    Node* Left;
    Node* Right;

    Node(int _value, int _idx, Node* _Left = nullptr, Node* _Right = nullptr) : value(_value), idx(_idx), Left(_Left), Right(_Right) {}
    ~Node() {
        value = 0;
        Left = nullptr;
        Right = nullptr;
    }
};

class Deque{
    private:
        Node* Front;
        Node* Back;
        int Size;
    public:
        Deque() : Front(nullptr), Back(nullptr), Size(0) {}

        void Pop_front(){
            Node* toPop = Front;
            if (Size == 1){
                Front = nullptr, Back = nullptr;
            } else {
                Front = Front->Right;
                Front->Left = nullptr;
            }
            delete toPop;
            --Size;
        }
        void Pop_back(){
            Node* toPop = Back;
            if (Size == 1){
                Front = nullptr, Back = nullptr;
            } else {
                Back = Back->Left;
                Back->Right = nullptr;
            }
            delete toPop;
            --Size;
        }
        void Push_front(int val, int idx){
            Node* newNode = new Node(val, idx);
            if (Size == 0){
                Front = newNode;
                Back = newNode;
            } else {
                Front->Left = newNode;
                newNode->Right = Front;
                Front = newNode;
            }
            ++Size;
        }
        void Push_back(int val, int idx){
            Node* newNode = new Node(val, idx);
            if (Size == 0){
                Front = newNode;
                Back = newNode;
            } else {
                Back->Right = newNode;
                newNode->Left = Back;
                Back = newNode;
            }
            ++Size;
        }
        int getFront(){
            if (Size > 0)
                return Front->value;
            return 0;
        }
        int getFrontIdx(){
            if (Size > 0)
                return Front->idx;
            return 0;
        }
        int getBack(){
            if (Size > 0)
                return Back->value;
            return 0;
        }
        int getBackIdx(){
            if (Size > 0)
                return Back->idx;
            return 0;
        }
        bool Empty(){
            if (Size > 0)
                return 0;
            return 1;
        }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("deque.in");
    ofstream cout("deque.out");

    Deque deq;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> num;
        while (!deq.Empty() and i - deq.getFrontIdx() >= k)
            deq.Pop_front();
        while (!deq.Empty() and deq.getBack() >= num)
            deq.Pop_back();
        deq.Push_back(num, i);
        if (i >= k) ans += deq.getFront();
    }

    cout << ans;
    return 0;
}
