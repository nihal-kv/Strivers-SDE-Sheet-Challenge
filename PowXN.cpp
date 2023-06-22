double myPow(double x, int n) {
        if(n==0) return 1;
        int h=abs(n);
        double temp=myPow(x, h/2);
        temp=temp*temp;
        if(h%2==0)
        {
            if(n>0) return temp;
            else return 1/temp;
        }
        else
        {
            if(n>0) return temp*x;
            else return 1/(temp*x);
        }
    }