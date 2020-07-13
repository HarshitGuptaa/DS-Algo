public class leet25{

//25. Reverse Nodes in k-Group: imp


    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    ListNode oh = null;
    ListNode ot = null;
    ListNode th = null;
    ListNode tt = null;
    
    public void addFirst(ListNode node){
        if(th==null){
            th=node;
            tt=node;
        }else{
            node.next=th;
            th=node;
        }
    }
    
    public int size(ListNode head){
        int count=0;
        ListNode curr = head;
        while(curr!=null){
            count++;
            curr=curr.next;
        }
        return count;
    }
    
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null || head.next==null || k==0 || k==1) return head;
        
        int size = size(head);
        if(size<k) return head;
        
        ListNode curr = head;
        
        while(curr!=null){
            int tk=k;            
            while(tk-- > 0){
                ListNode forw = curr.next;
                curr.next=null;
                addFirst(curr);
                curr=forw;
            }
            
            size-=k;
            
            if(ot==null){  //for reversing in starting
                oh=th;
                ot=tt;
            }else{     //for reversing in middle
                ot.next=th;
                ot=tt;
            }
            
            th=null;
            tt=null;
            
            
            if(size<k){   //just adding leftovers to last
                ot.next=curr;
                curr=null;
            }
        }
        return oh;
    }


}