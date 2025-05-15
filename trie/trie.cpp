#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* children[2];
    int mx;
    int cnt;

    Node() : children{nullptr, nullptr}, cnt(0), mx(INT_MIN) {}
};

class Trie{
    Node* root = new Node;

public:
    void insert(int x, int idx){
        Node* curr = root;
        for(int bit = 31; bit >= 0; --bit){
            int v = (x >> bit) & 1;
            if(!curr->children[v]){
                curr->children[v] = new Node;
            }
            curr = curr->children[v];
            curr->mx = max(curr->mx, idx);
        }
    }

    int query(int x, int k){
        Node* curr = root;
        int res = -1;
        for(int bit = 31; bit >= 0; --bit){
            int v_x = (x >> bit) & 1;
            int v_k = (k >> bit) & 1;
            if(v_k == 1){
                if(!curr->children[v_x^1]){
                    break;
                }
                curr = curr->children[v_x^1];
            } else{
                if(curr->children[v_x^1]){
                    res = max(res, curr->mx);
                }
                if(!curr->children[v_x]){
                    break;
                }
                curr = curr->children[v_x];
            }
        }
        return res;
    }
};

int main(){

}