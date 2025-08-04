#define int int64_t

const int64_t MOD = 1000000007;
const int M = 2;

std::array<std::array<int, M>, M>  mul(std::array<std::array<int, M>, M>& a, std::array<std::array<int, M>, M>& b){
    std::array<std::array<int, M>, M> res{};
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < M; ++j){
            // row i, col j
            for(int k = 0; k < M; ++k){
                res[i][j] += (a[i][k] * b[k][j]);
                if(res[i][j] >= MOD){
                    res[i][j] -= MOD;
                }
            }
        }
    }
    return res;
} 

std::array<std::array<int, M>, M> pow(std::array<std::array<int, M>, M> base, int exp){
    std::array<std::array<int, M>, M> res{};
    for(int i = 0; i < M; ++i){
        res[i][i] = 1;
    }

    while(exp){
        if(exp % 2){
            res = mul(res, base);
        }
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}

