string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.size();
    int l, h;
    int start=0, end=1;

    for(int i=1; i<n; i++)
    {
        //even
        l=i-1;
        h=i;
        while(l>=0 && h<n && str[l]==str[h])
        {
            if(h-l+1>end)
            {
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }

        //odd
        l=i-1;
        h=i+1;
        while(l>=0 && h<n && str[l]==str[h])
        {
            if(h-l+1>end)
            {
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
        
    }
    return str.substr(start, end);
}