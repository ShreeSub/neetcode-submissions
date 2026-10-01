class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())
        return "";
        vector<int>sz;
        for(auto s:strs)
        {
            sz.push_back(s.length());
        }
        string res;
        for(auto s:sz)
        {
            res.append(to_string(s));
            res.push_back(',');
        }
        res.push_back('#');
        for(string s:strs)
        {
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty())
        return {};
        vector<int>sizes;
        vector<string>res;
        int i=0;
        while(s[i]!='#')
        {
            int j=i;
            while(s[j]!=',')
            {
                j++;
            }
            sizes.push_back(stoi(s.substr(i,j-i)));
            i=j+1;
        }
        i++;
        for(int sz:sizes)
        {
            res.push_back(s.substr(i,sz));
            i+=sz;
        }
        return res;
    }
};
