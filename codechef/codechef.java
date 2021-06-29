import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scn = new Scanner(System.in);
		
		try{

		    int t = scn.nextInt();
		
		while(t-->0){
		    int n = scn.nextInt();
		    String s = scn.nextLine();
		    String p = scn.nextLine();
		    
		    int oneS=0,oneP=0;
		    for(int i=0;i<n;i++){
		        if(s.charAt(i)=='1') oneS++;
		        if(p.charAt(i)=='1') oneP++;
		    }
		    
		    if(oneP == oneS) System.out.println("Yes");
		    else System.out.println("No");
		}
		}
		catch(Exception error){
		    System.out.println(error);
		}
		
		
	}
}