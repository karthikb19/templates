
typedef complex<double> cd;
 
const double PI = acos(-1);
 
// Performs the in-place FFT (or inverse FFT if invert = true)
// The vector size n must be a power of two.
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    
    // Bit-reversal permutation
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    
    // Cooley-Tukey FFT
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len/2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    
    // If we're doing the inverse FFT, divide by n
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
 
// Multiplies two polynomials represented as coefficient vectors 'a' and 'b'
// Returns the coefficients of the resulting polynomial.
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    // n must be a power of two and at least as large as a.size()+b.size()-1
    while (n < int(a.size() + b.size()))
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    
    // Compute FFT on both coefficient arrays
    fft(fa, false);
    fft(fb, false);
    
    // Pointwise multiplication
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    
    // Inverse FFT to get the convolution result
    fft(fa, true);
    
    // Round the results (they should be integers if inputs were integers)
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = int(round(fa[i].real()));
    return result;
}