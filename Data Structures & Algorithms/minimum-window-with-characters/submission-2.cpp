class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp,window;
        int current=0, need=0;
        for(auto c: t)
        {
            mp[c]++;
        }
        pair<int,int>index;
        int resLen=INT_MAX;
        need = mp.size();
        int i=0;
        for(int j=0; j<s.length(); j++)
        {
            window[s[j]]++;
            
            if(mp.count(s[j]) && mp[s[j]]==window[s[j]])
            {
                current++; //found one character count = mp[t's char]
            }
            while(current == need)
            {
                if(resLen>(j-i+1))
                {
                    resLen = j-i+1;//found a better min window
                    index = {i,j}; //store index for substr
                }
                window[s[i]]--;
                if(mp.contains(s[i])&& window[s[i]]<mp[s[i]])
                {
                   current--;

                }
                i++;

            }
        }
        return resLen==INT_MAX?"":s.substr(index.first,resLen);
    }
};
