class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long mod = 1000000007;
        long long res = 0;
        vector<long long> people(n,0);
        people[0]=1;
        for(int i=0;i<n;i++){
            if(i>=n-forget){
                res+=people[i]%mod;
            }
            if(i+delay<n){
                for(int j=i+delay;j<min(i+forget,n);j++){
                    people[j]+=people[i]%mod;
                }
            }
        }
        return (int)(res % mod);
    }
};