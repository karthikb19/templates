void generateFactorsUtil(const std::unordered_map<int, int>& primeFactors, std::unordered_map<int, int>::const_iterator it, int currentFactor, std::vector<int>& factors) {
    if (it == primeFactors.end()) {
        factors.push_back(currentFactor);
        return;
    }
 
    int prime = it->first;
    int count = it->second;
    auto nextIt = std::next(it);
 
    // Include current prime factor 0 to 'count' times
    for (int i = 0; i <= count; ++i) {
        generateFactorsUtil(primeFactors, nextIt, currentFactor, factors);
        currentFactor *= prime;
    }
}
 
std::vector<int> generateFactors(const std::unordered_map<int, int>& primeFactors) {
    std::vector<int> factors;
    generateFactorsUtil(primeFactors, primeFactors.begin(), 1, factors);
    sort(factors.begin(), factors.end());
    return factors;
}
 
typedef uint32_t u32;
 
__attribute__((noinline))
void factor_helper(auto &vec, u32 &x, u32 y) {
    do {
    	vec.push_back(y);
    	x /= y;
    } while (x % y == 0);
}
 
const int maxp = 31623;
const int P = 3401; // number of primes below maxp
 
constexpr auto primes = []() constexpr {
    int idx = 0;
    array<u32, P> res{};
    array<bool, maxp> comp{};
    for(int p = 2; p < maxp; p++) {
        if(!comp[p]) {
            res[idx++] = p;
            for(int j = p; j < maxp; j += p) {
                comp[j] = 1;
            }
        }
    }
    assert(idx == P);
    return res;
}();
 
vector<u32> factor(u32 x) {
    vector<u32> vec;
    #pragma GCC unroll P
    for (int i = 0; i < P; i++)
        if (x % primes[i] == 0) [[unlikely]]
            factor_helper(vec, x, primes[i]);
    if (x > 1)
    	vec.push_back(x);
    return vec;
}   
 
