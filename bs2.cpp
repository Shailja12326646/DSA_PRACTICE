class Solution {
public:
 int mini(vector<int>arr)
 {
   int  minm=INT_MAX;
    for (int i=0;i<arr.size();i++)
    {
        minm=min(arr[i],minm);
    }
    return minm;
 }
 int maxi(vector<int>arr)
 {
    int maxm=INT_MIN;
    for (int i=0;i<arr.size();i++)
    {
        maxm=max(arr[i],maxm);
    }
    return maxm;
 }

 bool possible(vector<int>arr,int day,int m,int k)
 {
    int bookays=0,c=0;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i]<=day)
         { 
            c++;
         }
         else
         {
            bookays+=c/k;
            c=0;
         }
    }
    bookays+=c/k;
    if(bookays>=m)return true;
    return false;

 }

    int minDays(vector<int>& bloomDay, int m, int k) {

    //    for (int i=mini(bloomDay);i<=maxi(bloomDay);i++)
    //    {
    //      if (possible(bloomDay,i,m,k)==true)
    //       return i;
    //    }

    //    return -1;

        int start=0;
        int end=maxi(bloomDay);
       if (1LL * m * k > bloomDay.size()) return -1;

        while (start<=end)
        {
            int mid=(start+end)/2;
            if(possible(bloomDay,mid,m,k)==true)
            {
                end=mid-1;
            }
            else
             {
                start=mid+1;
             } 
        }
        return start;
    }
};
