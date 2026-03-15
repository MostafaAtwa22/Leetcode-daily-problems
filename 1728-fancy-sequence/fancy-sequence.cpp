class Fancy {
public:
    const long long MOD = 1e9+7;
    long long add = 0, mul = 1;
    vector<long long> a;

    long long modPow(long long x,long long y){
        long long r=1;
        while(y){
            if(y&1) r=r*x%MOD;
            x=x*x%MOD;
            y>>=1;
        }
        return r;
    }

    Fancy() {}

    void append(int val) {
        long long inv = modPow(mul, MOD-2);
        long long x = ( (val - add) % MOD + MOD ) % MOD;
        x = x * inv % MOD;
        a.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if(idx >= a.size()) return -1;
        return (a[idx] * mul + add) % MOD;
    }
};