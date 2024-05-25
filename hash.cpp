const int MOD1 = 1e9 + 9;
const int MOD2 = 998244353;
const int P1 = 69;
const int P2 = 53;


pair<vector<int>, vector<int>> compute_prefix_hashes(const string &s, int p, int m) {
    int n = s.size();
    vector<int> prefix_hash(n + 1, 0);
    vector<int> p_powers(n + 1, 1);
    
    for (int i = 1; i <= n; ++i) {
        prefix_hash[i] = (prefix_hash[i - 1] * p + (s[i - 1] - 'a' + 1)) % m;
        p_powers[i] = (p_powers[i - 1] * p) % m;
    }
    
    return {prefix_hash, p_powers};
}

pair<vector<int>, vector<int>> compute_suffix_hashes(const string &s, int p, int m) {
    int n = s.size();
    vector<int> suffix_hash(n + 1, 0);
    vector<int> p_powers(n + 1, 1);
    
    for (int i = n - 1; i >= 0; --i) {
        suffix_hash[i] = (suffix_hash[i + 1] * p + (s[i] - 'a' + 1)) % m;
        p_powers[n - i] = (p_powers[n - i - 1] * p) % m;
    }
    
    return {suffix_hash, p_powers};
}

int get_prefix_hash(const vector<int> &prefix_hash, const vector<int> &p_powers, int l, int r, int p, int m) {
    int hash_value = (prefix_hash[r + 1] - prefix_hash[l] * p_powers[r - l + 1] % m + m) % m;
    return hash_value;
}

int get_suffix_hash(const vector<int> &suffix_hash, const vector<int> &p_powers, int l, int r, int p, int m) {
    int n = suffix_hash.size() - 1;
    int hash_value = (suffix_hash[l] - suffix_hash[r + 1] * p_powers[r - l + 1] % m + m) % m;
    return hash_value;
}

bool is_substring_palindrome(const string &s, int l, int r, const vector<int> &prefixHash1, const vector<int> &p_powers1, const vector<int> &suffixHash1, const vector<int> &s_powers1, const vector<int> &prefixHash2, const vector<int> &p_powers2, const vector<int> &suffixHash2, const vector<int> &s_powers2) {
    int n = s.size();
    int prefix_hash1 = get_prefix_hash(prefixHash1, p_powers1, l, r, P1, MOD1);
    int suffix_hash1 = get_suffix_hash(suffixHash1, s_powers1, l, r, P1, MOD1);
    int prefix_hash2 = get_prefix_hash(prefixHash2, p_powers2, l, r, P2, MOD2);
    int suffix_hash2 = get_suffix_hash(suffixHash2, s_powers2, l, r, P2, MOD2);

    return prefix_hash1 == suffix_hash1 && prefix_hash2 == suffix_hash2;
}

/*
 auto [prefixHash1, p_powers1] = compute_prefix_hashes(S, P1, MOD1);
    auto [prefixHash2, p_powers2] = compute_prefix_hashes(S, P2, MOD2);

    // Compute suffix hashes
    auto [suffixHash1, s_powers1] = compute_suffix_hashes(S, P1, MOD1);
    auto [suffixHash2, s_powers2] = compute_suffix_hashes(S, P2, MOD2);

*/