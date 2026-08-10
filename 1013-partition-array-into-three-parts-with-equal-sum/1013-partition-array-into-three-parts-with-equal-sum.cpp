class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        for(int i : arr){
            total += i; 
        }

        int count = 0;

        if (total % 3 != 0)
        return false;
        int target = total / 3;
        int sum = 0; 
       
       for(int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    if(sum == target && i < arr.size() - 1) {
        count++;
        sum = 0;
    }
}
        if(count >= 2)
    return true;

        return false;
    }
};