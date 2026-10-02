class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int len=0;
        int i=0,j=0;
        while(j<s.length())
        {
            if(!st.contains(s[j]))
            {
                st.insert(s[j]);
                len = max(len, j-i+1);
                j++;
            }else{
                while(st.contains(s[j]))
                {
                    st.erase(s[i]);
                    i++;
                }
            }

        }
        return len;
    }
};
