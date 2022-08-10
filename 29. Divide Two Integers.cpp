class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        long int tmp_dividend = abs(dividend);
        long int tmp_divisor = abs(divisor);
        int ans = 0;
        while(tmp_divisor<=tmp_dividend){
           long int mul = tmp_divisor,tmp = 1;
            while(mul<=tmp_dividend-mul){
                mul+=mul;
                tmp+=tmp;
            }
            ans+=tmp;
            tmp_dividend-= mul;
        }
        if((dividend<0&&divisor>0)||(divisor<0&&dividend>0))return (-ans);
        return ans;
    }
};
