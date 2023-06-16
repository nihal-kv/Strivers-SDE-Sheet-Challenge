int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<int> v;
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size(); j++)
        {
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(), v.end());
    int n=v.size();
    if(n%2)
    {
        return v[n/2];
    }
    else
    {
        return (v[n/2-1]+v[n/2])/2;
    }
}