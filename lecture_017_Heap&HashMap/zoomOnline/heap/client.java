public class client{

    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
        heap pq= new heap(arr);

        while(pq.size()!=0){
            System.out.println(pq.top());
            pq.remove(0);
        }

    }

}

