struct dsu{
     vector<int> sz; vector<int> parent;
     void init(int N){
          sz = vector<int>(N, 1);
          parent = vector<int>(N);
          std::iota(all(parent), 0);
     }

     int find(int x){
          return x == parent[x] ? x : parent[x] = find(parent[x]);
     }
     bool join(int a, int b){
          a = find(a); b = find(b);
          if(a == b){
               return false;
          }
          if (sz[a] > sz[b]) swap(a, b);
          parent[a] = b;
          sz[b] += sz[a];
          return true;
     }
     bool sameSet(int a, int b){
          return find(a) == find(b);
     }
     int size(int x){
          return sz[find(x)];
     }
     void print(int N){
          for(int i = 0; i < N; ++i){
               cerr << find(i) << " ";
          }
          cerr << endl;
     }
} d;
