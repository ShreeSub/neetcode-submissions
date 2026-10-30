class Solution {
public:
    string longestPalindrome(string s) {
        string res ="";
        if(s.length()<2)
        return s;
        int resLen=0;
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            int low=i;
            int high=i;
            while(low>=0 && high <len && s[low]==s[high])
            {
                if(high-low+1>resLen)
                {
                    resLen = high-low+1;
                    res = s.substr(low, resLen);

                }
                low--;
                high++;

            }
            low=i;
            high = i+1;
            while(low>=0 && high <len && s[low]==s[high])
            {
                if(high-low+1>resLen)
                {
                    resLen = high-low+1;
                    res = s.substr(low, resLen);

                }
                low--;
                high++;

            }
        }
        return res;
    }
};
