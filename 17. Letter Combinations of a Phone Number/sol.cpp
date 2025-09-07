class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vals = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        string temp_sol = "";
        vector<string> sol;
        backtrace(sol, temp_sol, 0, digits, vals);
        return sol;
    };

private:
    void backtrace(vector<string>& sol, string temp_sol, int idx, string digits, vector<string> vals){
        if(idx==digits.size()){
            if(temp_sol.size()>0){
                sol.push_back(temp_sol);
            }
            return;
        }
        int num = digits[idx] - '0';
        const string& letters = vals[num - 2];
        for(int i=0;i<letters.size();i++){
            temp_sol.push_back(letters[i]);
            backtrace(sol, temp_sol, idx+1, digits, vals);
            temp_sol.pop_back();
        }
    };
};