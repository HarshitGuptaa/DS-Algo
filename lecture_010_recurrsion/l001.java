public class l001 {

    public static void main(String[] args) {
        //System.out.println(fact(4));
        //System.out.println(power(2, 10));
        // System.out.println(euler2(6,0));
        System.out.println(euler(5,0));

    }

    // FACTORIAL
    public static int fact(int n) {
        if (n == 1)
            return 1;
        int smallAns = fact(n - 1);
        return n * smallAns;
    }

    // power
    public static int power(int a, int b) {
        if (b==1)
            return a;
        int smallAns = power(a, b-1);
        return a*smallAns;
    }

    // POWER WITH LOG COMPLEXITY
    public static int power_better(int a, int b) {
        if (b == 1)
            return a;
        int smallAns = power_better(a, b / 2);
        smallAns *= smallAns;
        return (b % 2 != 0 ? smallAns * a : smallAns);
    }


public static int euler(int n,int level){
    if(n<=1){
        System.out.println("Base: "+ n +"@" + level);
        return n;
    }
    
    System.out.println("Pre: "+ n + "@" +level);

    int a=euler(n-1,level+1);
    System.out.println("In: "+ n + "@" +level);
    int b=euler(n-2,level+1);
    
    System.out.println("Post: "+ n+ "@" +level);

    return a+b+3;
  }

  public static int euler2(int n,int level){
    if(n<=2){
        System.out.println("Base: "+ n*level);
        return n;
    }
    
    System.out.println("Pre: "+ n*level);
    int a=euler2(n-1,level+1);

    System.out.println("In1: "+ n*level);
    int b=euler2(n-2,level+1);
    
    System.out.println("In2: "+ n*level);
    int c=euler2(n-3,level-1);

    System.out.println("Post: "+ n*level);

    return a+b+c+3;
  }

}



// public static int nokiaKeyPad(String[] words,String num,String ans){
//     if(num.length()==0){
//      System.out.print(ans + " ");
//      return 1; 
//     }

// char ch=num.charAt(0);
// String newNum=num.substring(1);
// String word=words[ch-'0'];
// int count=0;

//  for(int i=0;i<word.length();i++){
//   count+=nokiaKeyPad(words,newNum,ans + word.charAt(i));
// }
//  return count;
//       }




    //  public static int[] allIdx(int[] arr,int idx,int data,int count){
    //        if(idx==arr.length){
    //            int[] base=new int[count];
    //            return base;
    //        }

    //   if(arr[idx]==data){
    //       count++;
    //   }

    //   int[] recAns=allIdx(arr,idx+1,data,count);

    //   if(arr[idx]==data){
    //     recAns[count-1]=idx;
    //   }

    //   return recAns;


    //  } 




