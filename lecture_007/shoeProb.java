public class shoeProb{
	    public static void main(String[] args) {
        int[]arr={1,1,2,2,3,3,4,4,5,5,6,7,7,8,8,9,9};
      	// int[]arr={1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
      	// int[]arr={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8};

       	int li=0;
        int ri=arr.length-1;
}

    public static int BS(int[] arr, int data,int li,int ri) {
		
        while (li <= ri) {
			int mid = (li + ri) / 2;
			if(mid%2==0)
				if(arr[mid]!=arr[mid-1]){ //stolen on left of this
					ri=mid-1;
				}else if(li==ri){
					return mid;
				}
				else li=mid+1;
				




			}

        }

        return -1;

    }


}
