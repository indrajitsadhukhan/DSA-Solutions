import java.util.*;

class b{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        char[] arr = str.toCharArray();
        int n = str.length();
        b tt = new b();
        arr = tt.mergesort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]);
        }
    }
    char[] mergesort(char arr[],int l,int r)
    {
        if(l>=r)
        return arr;
        int m = (l+r)/2;
        arr = mergesort(arr,l,m);
       arr =  mergesort(arr,m+1,r);
       arr = merge(arr,l,m,r);
        return arr;
    }
   char[] merge(char[] arr,int l,int m,int r)
    {
        
        int sl = m-l+1;
        int sr = r-m;
        char[] L = new char[sl];
        char[] R= new char[sr]; 
        for(int i=0;i<sl;i++)
        {
            L[i] = arr[i+l];
        }
        for(int i=0;i<sr;i++)
        {
            R[i] = arr[m+i+1];
        }
        int i=0,j=0,k=l;
        while(i<sl && j<sr)
        {
            if(L[i]<=R[j])
            {
                arr[k] = L[i++];
            }
            else{
                arr[k] = R[j++];
            }
            k++;
        }
        while(i<sl)
        {
            arr[k++] = L[i++];
        }
        while(j<sr)
        {
            arr[k++] = R[j++];
        }
        return arr;
    }
}