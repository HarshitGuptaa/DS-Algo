public class trieBasic{

    public class Node{
        int wordEnd = 0;
        Node[]childs;

        Node(){
            this.wordEnd=0;
            this.childs = new Node[26];
        }
    }

    Node root = null;

    public void insert(String word){
        Node curr = root;
        int n=word.length();

        for(int i=0;i<n;i++){
            int idx = word.charAt(i) - 'a';
            if(curr.childs[idx]==null) curr.childs[idx] = new Node();
            curr=curr.childs[idx];
        }
        curr.wordEnd++;
    }

    public boolean search(String word){
        Node curr = root;
        int n=word.length();

        for(int i=0;i<n;i++){
            int idx = word.charAt(i)-'a';
            if(curr.childs[idx]==null) return false;
            curr=curr.childs[idx];
        }
        return curr.wordEnd>0;
    }

    public boolean startsWith(String word){
        Node curr = root;
        int n=word.length();

        for(int i=0;i<n;i++){       
            int idx = word.charAt(i)-'a';
            if(curr.childs[idx]==null) return false;
            curr=curr.childs[idx];
        }
        return true;
    }

}