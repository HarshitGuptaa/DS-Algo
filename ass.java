import java.util.*;
public class ass{

    public static void main (String[] args) throws java.lang.Exception
	{
	    // 	Scanner scn = new Scanner(System.in);
		// int t = scn.nextInt();

		// for (int i = 1; i <= t; i++) {

		// 	int n = scn.nextInt();
		// 	int x = scn.nextInt();
		// 	int y = scn.nextInt();
		// 	int k = scn.nextInt();
		// 	boolean[] arr = new boolean[n];
			
		// 	Arrays.fill(arr, false);
		// 	int idx = x;
			
		// 	System.out.println(covid(n,x,y,k,arr,idx));
		// }
			int []arr = {1,3,2,-3};
		System.out.println(subset(arr,0,0,0));
	}
	
	// public static boolean covid(int n,int x,int y,int k,boolean []arr,int idx){
    //     if(x==y) return true;
    //     if(x==idx) return false;
	    
	//     arr[x]=true;
	    
	// 	boolean res = false;
	// 	res = res || covid(n,(x+k)%n,y,k,arr,idx);
	// 	return res;
	// }
	
	public static int subset(int []arr,int tar,int idx,int sum){
		if(idx==arr.length){
		if(sum==tar) return 1;
		return 0;
		}
	
		int count=0;
	
		count+= subset(arr,tar,idx+1,sum+arr[idx]);
		count+= subset(arr,tar,idx+1,sum);
	
		return count;
	}
	

}