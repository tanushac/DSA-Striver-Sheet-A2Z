class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.length()!=goal.length()){
        return false;
       }
        //temp=s+s;
        //example abcdeabcde
       string temp=s.append(s);
       //if goal is a substring of s then the strings are a rotation of each other
        if(temp.find(goal) != string::npos){
            return true;
        }
       return false;
}
};
