class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int>rank;
        int rankk = 1;
        for(int val: sorted){
            if(rank.find(val) == rank.end() ){
                rank.insert({val, rankk});
                rankk++;
            }
            
        }
        for(int &num : arr){
            num = rank[num];
        }

    return arr;
    }
};