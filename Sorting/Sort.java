import java.util.*;

class Sort{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        Sort tt = new Sort();
        // tt.mergesort(arr,0,n-1);
        tt.selectionsort(arr, n);
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
    }
    private int[] selectionsort(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int min_i = i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min_i])
                {
                    min_i=j;
                }
            }
            int temp=arr[min_i];
            arr[min_i]=arr[i];
            arr[i] = temp;
        }
        return arr;
    }
     
    private int[] insertionsort(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            int key= arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        return arr;
    }


    private int[] bubblesort(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
    }
    private int[] quicksort(int arr[],int l,int r)
    {
        if(l>r)
        {
            return arr;
        }
        int pivot = partition(arr,l,r);
        quicksort(arr, l, pivot-1);
        quicksort(arr, pivot+1, r);
        return arr;
    }
    private int partition(int arr[],int l,int r)
    {
        int pivot = arr[r];
        int i=l-1;
        for(int j=l;j<=r;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr,j,i);
            }
        }
        swap(arr,i+1,r);
        return i+1;
    }
    private void swap(int arr[],int x,int y)
    {
        int t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }
    void mergesort(int arr[],int l,int r)
    {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    
    }
    void merge(int arr[],int l,int m,int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i=0;i<n1;i++)
        {
            L[i] = arr[l+i];
        }
        for(int i=0;i<n2;i++)
        {
            R[i] = arr[m+i+1];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(L[i] <= R[j])
            {
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
            }
        }
        while(i<n1)
        {
            arr[k++] = L[i++];
        }
        while(j<n2)
        {
            arr[k++] = R[j++];
        }
    }
}