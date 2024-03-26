class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1,m2;
        int i=0,j=0;
        while(i<s.length() and j<t.length()){
            if(!m1.count(s[i]) and !m2.count(t[j])){
                m1[s[i]]=t[j];
                m2[t[j]]=s[i];
            }
            else{
                if(m1[s[i]]!=t[j] or m2[t[j]]!=s[i]) return false;
            }
            i++;j++;
        }
        return true;
    }
};
