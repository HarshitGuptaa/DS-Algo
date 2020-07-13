
import java.util.ArrayList;

public class heap{
    
    private ArrayList<Integer>arr;
    private boolean isMax = false;
    
    public void createHeap(int [] arr){
        this.arr = new ArrayList<>();

        for(int ele:arr){
            this.arr.add(ele);
        }

        for(int i=arr.length-1;i>=0;i--){
            downHeapify(i);
        }

    }


    public heap(int []arr){
        createHeap(arr);
    }

    public heap(int []arr, boolean isMax){
        this.isMax = isMax;
        createHeap(arr);
    }

    public void upHeapify( int cidx){
         int pidx = (cidx-1)/2;

        if(pidx>=0 && compareTo(cidx, pidx)>0){
            swap(cidx, pidx);
            upHeapify(pidx);
        }
    }

    public void downHeapify( int idx){
        int maxIdx = idx;
         int lci = 2*idx+1;
         int rci = 2*idx+2;

        if(lci<arr.size() && compareTo(lci, maxIdx)>=0){
            maxIdx = lci;
        }

        if(rci<arr.size() && compareTo(rci, maxIdx)>=0){
            maxIdx = rci;
        }

        if(maxIdx!=idx){
            swap(maxIdx, idx);
            downHeapify(maxIdx);
        }
    }

    public void swap( int i, int j){
         int val1 = arr.get(i);
         int val2 = arr.get(j);

        arr.set(i, val2);
        arr.set(j, val1);
    }

    public void push( int val){
        arr.add(val);
        upHeapify(arr.size()-1);
    }

    public void remove( int idx){
        swap(idx, arr.size()-1);
        arr.remove(arr.size()-1);
        downHeapify(idx);
    }

    public int top(){
        return arr.get(0);
    }

    public void update( int preval,  int newval){
        int idx=-1;

        for(int i=0;i<arr.size();i++){
            if(arr.get(i)==preval){
                idx=i;
                break;
            }
        }

        if(idx==-1) return;

        arr.set(idx,newval);
        downHeapify(idx);
        upHeapify(idx);
    }

    public int compareTo( int child, int parent){
        if(isMax){                      //isMax true : max heap
            return arr.get(child)-arr.get(parent);
        }else{
            return arr.get(parent)-arr.get(child);
        }
    }

public int size(){
    return arr.size();
}

}