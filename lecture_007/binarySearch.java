//do bs then find lower bound &uppnound of same elt
import java.util.Arrays;
public class binarySearch {
    public static void main(String[] args) {
        // int[] arr = { -2, -1, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 6, 7, 8, 9, 12, 14, 15, 16,
        //         18 };
        int[]arr={5,6,7,8,9,10,1,2};
      // int[]arr={3,4,5,0,1,2}; 
       int li=0;
        int ri=arr.length-1;
        int data=9;
       // System.out.println(BS(arr, 2));
        //System.out.println(lowerBound(arr, 2));
//        System.out.println(upperBound(arr, 2));




//      FOR ROTATED ARRAY
        int pivot=pivot(arr,data,li,ri);
        if(data<arr[pivot]&&data>arr[0]){
            System.out.println("given data located at index: " +BS(arr, data, li, pivot));
        } else{
           System.out.println("given data located at index: " + BS(arr, data, pivot+1,ri));

        }

    }

    public static int BS(int[] arr, int data,int li,int ri) {

        while (li <= ri) {
            int mid = (li + ri) / 2;
            if (arr[mid] == data) {
                return mid;
            } else if (arr[mid] > data) {
                ri = mid - 1;
            } else {
                li = mid + 1;
            }
        }

        return -1;

    }

    public static int lowerBound(int[] arr, int data) {
        int li = 0;
        int ri = arr.length - 1;
        while (li <= ri) {
            int mid = (li + ri) / 2;
            if (arr[mid] == data) {
                if (mid - 1 > 0 && arr[mid] == arr[mid - 1]) {
                    ri = mid - 1;
                } else {
                    return mid;
                }
            } else if (arr[mid] > data) {
                ri = mid - 1;
            } else {
                li = mid + 1;
            }
        }

        return -1;

    }

    public static int upperBound(int[] arr, int data) {
        int li = 0;
        int ri = arr.length - 1;
        while (li <= ri) {
            int mid = (li + ri) / 2;
            if (arr[mid] == data) {
                if (mid + 1 < arr.length && arr[mid] == arr[mid + 1]) {
                    li = mid + 1;
                } else {
                    return mid;
                }
            } else if (arr[mid] > data) {
                ri = mid - 1;
            } else {
                li = mid + 1;
            }
        }

        return -1;

    }

    public static int BSclosestElt(int[] arr, int data) {
        int li = 0;
        int ri = arr.length - 1;

        if (data < arr[li])
            return li;
        if (data > arr[ri])
            return ri;

        while (li <= ri) {
            int mid = (li + ri) / 2;
            if (arr[mid] == data) {
                return mid;
            } else if (arr[mid] > data) {
                ri = mid - 1;
            } else {
                li = mid + 1;
            }
        }

        return (data - arr[ri] <= arr[li] - data ? ri : li); // if not found ri<data<li 

    }


    //if a sorted array is rotated by unknown r, now find the position using binary search in O(logn)
    public static int pivot(int[]arr,int data,int li,int ri){
        while(li<=ri){
            int mid = (li + ri) / 2;
            if(arr[mid]<=arr[0]){
                ri=mid-1;
            }else li=mid+1;
          
        }
        System.out.println("li is.."+li+"  ri is.."+ri);
        return ri; //here ri comes before than li
       //arr[ri] is pivot: 5 in 3,4,5,1,2
    }

}