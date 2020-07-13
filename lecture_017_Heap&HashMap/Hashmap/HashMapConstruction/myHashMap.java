import java.util.ArrayList;
import java.util.LinkedList;

//to make generic replace by <K,V>

public class myHashMap<K,V>{
    public class Node{
        K key;
        V value;
        Node(K key,V value){
            this.key=key;
            this.value=value;
        }
        @Override  //this override for node, outside for class
        public String toString(){
            return this.key + "=" + this.value;
        }
    }

    private int size=0;
    private LinkedList<Node>[] buckets = new LinkedList[10];

    public myHashMap(){ //ctor
        reassign();
    }
    private void reassign(){
        for(int i=0;i<buckets.length;i++){
            buckets[i] = new LinkedList<>();
        }
        this.size = 0;
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        for(int i=0;i<buckets.length;i++){
            int size = buckets[i].size();
            if(size>0){
                LinkedList<Node> group = buckets[i];
                
                while(size-->0){
                    Node tNode = group.getFirst();
                    sb.append(tNode.toString()+", ");   //tostring defined in node
                    group.addLast(group.removeFirst());
                }

            }
        }
        sb.deleteCharAt(sb.length()-1);
        sb.deleteCharAt(sb.length()-1);
        sb.append("}");
        return sb.toString();
    }
    
    public void put(K key,V value){
        int code = MyGroup(key);
        LinkedList<Node> group = buckets[code];
        //if(group==null) buckets[code] = new LinkedList<>();  can be used instead of ctor
        
        Node rn = foundInGroup(group, key);

        if(rn!=null){
            rn.value = value;
        }else{
            Node node = new Node(key, value);
            group.addFirst(node);
            this.size++;
        }

        double lambda = group.size()*1.0/buckets.length;
        if(lambda>=0.3){ //  1000 len bucket, lambda=0.3, so in a group at max 300 possible, if exceed this then we increase bucket length
            System.out.println("Rehash: " + group.size());
            rehash();
        }
    }

    public void rehash(){   //inc bucket size when threshold value crossed  
        LinkedList<Node> [] oldBuckets = buckets;     //====group size must not > buckets====
        buckets = new LinkedList[oldBuckets.length*2];
        reassign();

        for(int i=0;i<oldBuckets.length;i++){
            if(oldBuckets[i].size()>0){
                LinkedList<Node> group = oldBuckets[i];
                int size = group.size();

                while(size-->0){
                    Node tnode = group.removeFirst();
                    put(tnode.key,tnode.value);
                }
            }
        }
    }

    public V get(K key){
        int code = MyGroup(key);
        LinkedList<Node> group = buckets[code];
        Node rn = foundInGroup(group, key);
        return rn==null?null:rn.value;
    }

    public Node remove(K key){
        int code = MyGroup(key);
        LinkedList<Node> group = buckets[code];
        Node rn = foundInGroup(group, key);

        if(rn!=null){
            this.size--;
            group.removeFirst();
        }else{
            System.out.println("ElementNotfound: -1");
        }

        return rn;
    }

    private Node foundInGroup(LinkedList<Node> group,K key){  //given a LL, finding a node in LL using its key
        if(group==null) return null;
        Node rn = null;
        int size = group.size();
        while(size-->0){
            Node tempNode = group.getFirst();
            if(tempNode.key == key){
                rn = tempNode;
            }
            group.addLast(group.removeFirst());
        }
        return rn;
    } 

    public boolean containsKey(K key){
        int code = MyGroup(key);
        LinkedList<Node> group = buckets[code];
        Node rn = foundInGroup(group, key);
        return rn!=null?true:false;
    }

    public ArrayList<K> keySet(){
        ArrayList<K> keys = new ArrayList<>();
        for(int i=0;i<buckets.length;i++){
            LinkedList<Node> group = buckets[i];
            int size = group.size();
            while(size-->0){
                keys.add(group.getFirst().key);
                group.addLast(group.removeFirst());
            }
        }
        return keys;
    }

    public V getOrDefault(K key,V val){
        int code = MyGroup(key);
        LinkedList<Node> group = buckets[code];
        Node rn = foundInGroup(group, key);
        return rn!=null?rn.value:val;
    }

    public int MyGroup(K key){
        return MyHashCode(key)%buckets.length;
    }
    public int MyHashCode(K key){
        int val = key.hashCode();
        return Math.abs(val);
    }

}