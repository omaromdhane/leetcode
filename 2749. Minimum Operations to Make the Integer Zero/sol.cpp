class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; i <= 60; i++) {
            long long new_num = (long long)num1 - (long long)i * num2;
            if (new_num < i) continue;
            if (__builtin_popcountll(new_num) <= i) {
                return i;
            }
        }
        return -1;
    }
};