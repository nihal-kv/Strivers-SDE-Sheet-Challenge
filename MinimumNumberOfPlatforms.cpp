int calculateMinPatforms(int arr[], int dept[], int n) {
    // Write your code here.
    sort(arr, arr+n);
    sort(dept, dept+n);

    int count=1, ans=1;
    int i=1, j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dept[j])
        {
            count++;
            ans=max(ans, count);
            i++;
        }
        else
        {
            count--;
            j++;
        }
    }
    return ans;
}