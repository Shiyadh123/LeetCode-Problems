class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        // int i=0,j=n-1;
        // while(i<j){
        //     int sum=numbers[i]+numbers[j];
        //     if(sum==target){
        //         return {i+1,j+1};
        //     }else if(sum>target){
        //         j--;
        //     }else{
        //         i++;
        //     }
        // }
        // return {};
        for(int i=0;i<n;i++){
            int toFind=target-numbers[i];
            int lo=i+1,hi=n-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(numbers[mid]==toFind) return {i+1,mid+1};
                else if(numbers[mid]>toFind) hi=mid-1;
                else lo=mid+1;
            }
        }
        return {};
    }
};