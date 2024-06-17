

int BSR(int a[],int k,int start,int end){
    if (start>end)
    {
        return -1;  //NOT FOUND
    }
    int mid=start+(end-start)/2;
    if (a[mid]==k)
    {
        return k;   //FOUND  or we can return its index
    }
    else if (k> a[mid])
    {
        return BSR(a,k,mid+1,end);
    }
    else
    {
        return BSR(a,k,start,mid-1);
    }
}