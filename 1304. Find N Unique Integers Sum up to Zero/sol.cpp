class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int temp = 1;
        while(n>1){
            ans.push_back(temp);
            ans.push_back(-temp);
            n-=2;
            temp++;
        }
        if(n==1){
            ans.push_back(0);
        }
        return ans;
    }
};