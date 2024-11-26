class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.length() != t.length()) 
        {
            return false;
        }
        
        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;
        
        for (int i = 0; i < s.length(); ++i) 
        {
            
            if (map_s_to_t.find(s[i]) != map_s_to_t.end()) 
            {
                if (map_s_to_t[s[i]] != t[i]) 
                {
                    return false;
                }
            } 
            else 
            {
                map_s_to_t[s[i]] = t[i];
            }

            if (map_t_to_s.find(t[i]) != map_t_to_s.end()) 
            {
                if (map_t_to_s[t[i]] != s[i]) 
                {
                    return false;
                }
            } 
            else 
            {
                map_t_to_s[t[i]] = s[i];
            }
        }
        
        return true;
    }
};
