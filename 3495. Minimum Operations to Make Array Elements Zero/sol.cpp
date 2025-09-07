class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long total = 0;

        for (const auto& range : queries) {
            long long left = range[0];
            long long right = range[1];

            long long currentPower = largestPowerOf4(left);
            long long nextPower = currentPower * 4;

            long long rangeSum = 0;

            while (currentPower <= right) {
                long long start = max(left, currentPower);
                long long end   = min(right, nextPower - 1);

                if (start <= end) {
                    long long count = end - start + 1;
                    long long exponent = extractExponentFromPowerOf4(currentPower);
                    rangeSum += count * (exponent + 1);
                }

                currentPower = nextPower;
                nextPower *= 4;
            }

            total += (rangeSum + 1) / 2;
        }

        return total;
    }

private:
    long long largestPowerOf4(long long x) {
        long long p = 1;
        while (p * 4 <= x) {
            p *= 4;
        }
        return p;
    }

    long long extractExponentFromPowerOf4(long long n) {
        return (63 - __builtin_clzll(n)) >> 1; 
    }
};
