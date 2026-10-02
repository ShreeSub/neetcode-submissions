class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxFreq=0;
        int ans=0;
        int i=0;
        for(int j=0; j<s.length(); j++)
        {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]); //don't need to update maxfreq while removing char because that is max that we have found, only update when it increases. 
            while( (j-i +1)-maxFreq >k) //until the window is valid again remove element
            {
                mp[s[i]]--;
                i++;
                
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
