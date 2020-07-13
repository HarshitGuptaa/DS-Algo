import java.util.*;

public class Huffman_again{
    
    private static HashMap<String,String> encode = new HashMap<>();
    private static HashMap<String,String> decode = new HashMap<>();

    private static class Node implements Comparable<Node>{
        String data="";
        int freq=0;
        Node left=null;
        Node right=null;

        Node(String data,int freq,Node left,Node right){
            this.data=data;
            this.freq=freq;
            this.left=left;
            this.right=right;
        }

        @Override
        public int compareTo(Node o){
            return this.freq - o.freq;  //min priority queue
        }
    }

    private static void HuffmanTree(String str){
        int [] freq = new int[256];
        for(int i=0;i<str.length();i++){
            freq[str.charAt(i)-'a']++;
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i=0;i<freq.length;i++){
            if(freq[i]>0){
                pq.add(new Node((char)(i+'a')+"", freq[i], null, null));
            }
        }

        while(pq.size()!=1){
            Node one = pq.poll();
            Node two = pq.poll();
            Node node = new Node("", one.freq+two.freq,one,two);
            pq.add(node);
        }

        HuffmanTraverse(pq.remove(), "");
    }

    private static void HuffmanTraverse(Node root,String Binarycode){

        if(root.left==null&&root.right==null){
            encode.put(root.data,Binarycode);
            decode.put(Binarycode,root.data);
            return;
        }

        HuffmanTraverse(root.left, Binarycode+"0");
        HuffmanTraverse(root.right, Binarycode+"1");
    }

    public static String encode(String str){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<str.length();i++){
            String s = str.charAt(i)+"";
            String res = encode.get(s);
            sb.append(res);
        }
        return sb.toString();
    }

    public static String decode(String str){
        StringBuilder sb = new StringBuilder();
        int j=0;
        for(int i=1;i<=str.length();i++){
            String possiblestr = str.substring(j,i);
            if(decode.containsKey(possiblestr)){
                j=i;
                sb.append(decode.get(possiblestr));
            } 
        }
        return sb.toString();
    }

    public static void main(String[] args){
        HuffmanTree("aabbbccccddeeeef");
        String enc = encode("abcd");
        String dec = decode(enc);

        System.out.println(enc);
        System.out.println(dec);
    }


}