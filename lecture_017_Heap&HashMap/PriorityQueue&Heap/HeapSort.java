public class HeapSort{
    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
        heapsort(arr,true);    
    }

    public static void heapsort(int [] arr, boolean isMax){
        for(int i=arr.length-1;i>=0;i--){
            downHeapify(arr,i,arr.length-1,isMax);

        }
        for(int j=0;j<arr.length;j++){
            System.out.print(arr[j] + " ");
        } 
        for(int i=0;i<arr.length;i++){
            swap(arr,0,arr.length - i -1);
            downHeapify(arr, 0, arr.length - i -1, isMax);
            for(int j=0;j<arr.length;j++){
                System.out.print(arr[j] + " ");
            }  
            System.out.println();          
        }

        // for(int i=0;i<arr.length;i++){
        //     System.out.print(arr[i] + " ");
        // }
    }

    public static int compareTo(int val1,int val2,boolean isMax){
        if(isMax){
            return val1-val2;
        }else{
            return val2-val1;
        }
    }

    public static void swap(int[]arr,int x,int y){
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    public static void downHeapify(int []arr,int idx, int n,boolean isMax){
        int maxIdx = idx;
        int lci = 2*idx + 1;
        int rci = 2*idx + 2;
        
        if(lci< n && compareTo(arr[lci], arr[maxIdx],isMax)>0){
            maxIdx = lci;
        }

        if(rci< n && compareTo(arr[rci], arr[maxIdx],isMax)>0){
            maxIdx = rci;
        }

        if(maxIdx!=idx){
            swap(arr,maxIdx, idx);
            downHeapify(arr,maxIdx,n,isMax);
        }
   }

}