struct Tree{
    // pair<int, int> -> second largest, largest
    pair<int, int> combine(pair<int, int> a, pair<int, int> b){
        array<int, 4> ff = {a.first, a.second, b.first, b.second};
        sort(ff.rbegin(), ff.rend());
        vector<int> un; 
        un.push_back(ff[0]);
        for(int x : ff){
            if(un.back() != x){
                un.push_back(x);
            }
        }
        if(un.size() == 1){
            return {un[0], un[0]};
        } else{
            return {un[1], un[0]};
        }
    }
    
    int n;
    vector<pair<int, int>> T; 
    Tree(int n = 0) : T(4*n, {-1, -1}), n(n) {}

    void build(vector<int> a, int v, int tl, int tr){
        if(tl == tr){
            T[v] = {a[tl], a[tl]};
        } else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            T[v] = combine(T[v*2+1], T[v*2]);
        }
    }

    pair<int, int> query(int v, int tl, int tr, int l, int r){
        if(l > r){
            return {-1, -1};    
        } if(l == tl and r == tr){
            return T[v];
        }
        int tm = (tl + tr)/2;
        return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int newVal){
        if(tl == tr){
            T[v] = {newVal, newVal};
        } else{
            int tm = (tl+tr)/2;
            if(pos <= tm){ // go left
                update(v*2, tl, tm, pos, newVal);
            } else{ // go right
                update(v*2+1, tm+1, tr, pos, newVal);
            }
            T[v] = combine(T[v*2], T[v*2+1]);
        }
    }

};


// st.build(A, 1, 0, N-1);