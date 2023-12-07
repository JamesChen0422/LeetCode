int totalMoney(int n) 
{
    int week=n/7;
    int day=n%7;

    int ans = 0;
    for(int i=0;i<week;i++)
    {
        ans+=28+(i*7);
    }

    if(day==0)
    {
        return ans;
    }
    else
    {
        week++;
        while(day--)
        {
            ans+=week++;
        }
    }
    return ans;
}


/////////////////////////////////////////////////////


int totalMoney(int n) 
{
   int x=1;
    int sum = 0;
    for(int i = 1,k=1; i <= n ; i+=7,k++)
    {
        for(int j = k ; j <= 6+k;j++)
        {
            if(x > n)
            {
                break;
            }
            sum = sum + j;
            x++;
        }
    }
    return sum;
}
