class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        //for traversing all characters of first string
        for(int i=0;i<strs[0].length();i++){
            char ch=strs[0][i];
            bool match=true;
            //for comparing ch with rest of the strings
            int n=strs.size();
          for(int j=1;j<n;j++){
              //not match
              if(ch!=strs[j][i]||strs[j].size()<i){
                match=false;
                break;
              }
          }
          if(match==false){
              break;
          }
          else{
              ans.push_back(ch);
          }
        }
          return ans;
    }
};
