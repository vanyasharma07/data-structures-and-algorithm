class Solution {
public:
    int maxDepth(string s) {
        int maxx = 0;
        int count = 0;
        for(auto it: s){
            if(it == '('){
                count++;
                maxx = max(count,maxx);
            }
            if(it == ')'){
                count--;
            }
        }
        return maxx;
    }
};