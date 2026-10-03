class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0, right =nums.size()-1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[left]<=nums[mid])
            {
                if(target>nums[mid]|| target <nums[left])//check if target is smaller then the smallest value in the left sorted half, if that is the case it should be in the right half
                {
                    left = mid +1;
                }else
                {
                    right = mid-1;
                }
            } else
            {
                if(target <nums[mid] || target>nums[right]) //check if target is bigger than the biggest value in the right sorted half, then it has to be on the left
                {
                    right =mid-1;
                }else
                {
                    left = mid+1;
                }
            }

        }
        return -1;
    }
};
