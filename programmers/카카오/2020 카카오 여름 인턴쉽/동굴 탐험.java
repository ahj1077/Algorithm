import java.util.*;

class Solution {
    public boolean solution(int n, int[][] path, int[][] order) {
        boolean answer = true;
        
        ArrayList<Integer> adlist[] = new ArrayList[200000]; 
		ArrayList<Integer> lock[] = new ArrayList[200000]; 
		Integer locked[] = new Integer[200000];
		boolean inQueue[] = new boolean[200000];
		boolean visit[] = new boolean[200000];
		boolean reached[] = new boolean[200000];
		
		
		 for(int i=0; i<n; i++) {
	        	adlist[i] = new ArrayList<Integer>();
	        	lock[i] = new ArrayList<Integer>();
	        	locked[i] = 0;
	     }
	        
	     for(int i=0; i<path.length; i++) {
	    	 int node1 = path[i][0];
	    	 int node2 = path[i][1];
	    	 
	    	 adlist[node1].add(node2);
	    	 adlist[node2].add(node1);
	     }
	     
	     for(int i=0; i<order.length; i++) {
	    	 int node1 = order[i][0];
	    	 int node2 = order[i][1];
	    	 
	    	 locked[node2]++;
	    	 lock[node1].add(node2);
	     }
	     
	     Queue<Integer> q = new LinkedList<>();
	     if(locked[0] == 0) {
	    	 reached[0] = true;
	    	 inQueue[0] = true;
	    	 visit[0] = true;
	    	 q.add(0);
	     }
	     
	     while(!q.isEmpty()) {
	    	 int node = q.poll();
	    	 inQueue[node] = false;
	    	 
	    	 for(int i=0; i<lock[node].size(); i++) {
	    		 locked[lock[node].get(i)]--;
	    		 if(locked[lock[node].get(i)] == 0 && reached[lock[node].get(i)]) {
	    			 inQueue[lock[node].get(i)] = true;
	    			 visit[lock[node].get(i)] = true;
	    			 q.add(lock[node].get(i));
	    		 }
	    	 }
	    	 
	    	 for(int i=0; i<adlist[node].size(); i++) {
	    		 int nextNode = adlist[node].get(i);
	    		 
	    		 if(locked[nextNode] == 0 && !visit[nextNode]) {
	    			 if(!inQueue[nextNode]) {
	    				 inQueue[nextNode] = true;
	    				 visit[nextNode] = true;
	    				 q.add(nextNode);
	    			 }
	    		 }
	    		 else if(locked[nextNode] > 0){
	    			 reached[nextNode] = true;
	    		 }
	    	 }
	     }
	     
	     for(int i=0; i<n-1; i++) {
	    	 if(!visit[i]) {
	    		 answer = false;
	    	 }
	     }
	     
        return answer;
    }
}