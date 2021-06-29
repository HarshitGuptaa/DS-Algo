import java.util.*;
public class ass{

    public static void main (String[] args) 
	{
	    Scanner scn = new Scanner(System.in);
		int []arr = new int[]{1,2,3,4};
		System.out.println( permuteHelper(arr,0) ); 		

	}

	private static int permuteHelper(int[] arr, int index){
		if(index >= arr.length - 1){ //If we are at the last element - nothing left to permute
			//System.out.println(Arrays.toString(arr));
			//Print the array
			System.out.print("[");
			for(int i = 0; i < arr.length - 1; i++){
				System.out.print(arr[i] + ", ");
			}
			if(arr.length > 0) 
				System.out.print(arr[arr.length - 1]);
			System.out.println("]");
			return 1;
		}
		int count=0;
		for(int i = index; i < arr.length; i++){ //For each index in the sub array arr[index...end]
	
			//Swap the elements at indices index and i
			int t = arr[index];
			arr[index] = arr[i];
			arr[i] = t;
	
			//Recurse on the sub array arr[index+1...end]
			count+=permuteHelper(arr, index+1);
	
			//Swap the elements back
			t = arr[index];
			arr[index] = arr[i];
			arr[i] = t;
		}
		return count;
	}





	// public static void func(int r,String [][]arr,String ans){
		
	// 	// if(r<3 && c<arr[r].length && arr[r][c]!="") ans+=arr[r][c];

	// 	if(r==3){
	// 		System.out.println(ans);
	// 		return;
	// 	}

	// 	for(int i=0;i<arr[r].length;i++){
	// 		// if (arr[r+1][i] != "" && r < 3) 
	// 			func(r+1,arr,ans+arr[r][i]+" ");
	// 	}


	// }
	
	

}