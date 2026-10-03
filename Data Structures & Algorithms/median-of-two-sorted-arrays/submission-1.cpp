class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(), m=nums2.size();
        vector<int>smaller, larger;
        if(n>m)
        {
            smaller = nums2;
            larger=nums1;
        }else{
            smaller=nums1;
            larger=nums2;
        }
        int total = n+m;
        int left=0, right=smaller.size();
        while(left<=right)
        {
            int mid1 = left+(right-left)/2;
            int mid2 = (total+1)/2-mid1; //total+1/2 keeps median on the left side of the array for odd length hence we return max of (l1,l2) if we do total/2- mid1, we should return min(r1,r2)
            int l1 = mid1==0?INT_MIN:smaller[mid1-1];
            int r1 = mid1==smaller.size()?INT_MAX:smaller[mid1];
            int l2 = mid2==0?INT_MIN:larger[mid2-1];
            int r2= mid2==larger.size()?INT_MAX:larger[mid2];
            if(l1<=r2 && l2<=r1)
            {
                if(total%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2)*1.0;
            }
            else if(l1>r2)
            {
                right = mid1-1;
            }else 
            {
                left = mid1+1;
            }
        }
        return 0.0;
    }
};
