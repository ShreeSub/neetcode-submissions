class Solution {
public:
    int countSubstrings(string s) {
        int res =0;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            int low = i;
            int high = i;
            while(low>=0 && high<n && s[low]==s[high])
            {
                res++;
                low--;
                high++;
            }
            low=i;
            high = i+1;
            while(low>=0 && high<n && s[low]==s[high])
            {
                res++;
                low--;
                high++;
            }
        }
        return res;
    }
};
