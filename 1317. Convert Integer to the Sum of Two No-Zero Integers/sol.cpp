class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        int a = n-1;
        int b = 1;
        while(contains_zeros(a) || contains_zeros(b)){
            a--;
            b++;
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }

private:
    bool contains_zeros(int num){
        string num_as_str = to_string(num);
        for(auto ch: num_as_str){
            if(ch=='0'){
                return true;
            }
        }
        return false;
    }
};