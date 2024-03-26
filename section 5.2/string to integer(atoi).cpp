class Solution {
public:
    int myAtoi(string s) 
    {
        int i=0;
        int sign=1;
        long ans=0;
        while(i<s.length() && s[i]==' ')//skip leading whitespaces
            i++;
        if(s[i]=='-')//if negative sign
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')//if positive sign
            i++;
        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')//if a digit
            {
                ans=ans*10+(s[i]-'0');
                //overflow and underflow condition for 32 bit integer
                if(ans>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX;
                i++;
            }
            else
                return ans*sign;//returns ans multiplied by sign, if positive then positive, if negative then negative ans
        }
        return (ans*sign);
    }
};
