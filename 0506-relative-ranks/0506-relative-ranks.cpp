class Solution {
    public String[] findRelativeRanks(int[] score) {
        
        int n = score.length;
        
        PriorityQueue<Pair<Integer, Integer>> maxheap = new PriorityQueue<>((p1, p2) -> (p2.getValue() - p1.getValue()));
        
        for (int i = 0 ; i < n ; i++) {
            maxheap.add(new Pair(i, score[i]));
        }
        
        String[] ans = new String[n];
        
        int place = 1;
        
        while (!maxheap.isEmpty()) {
            Pair<Integer, Integer> top = maxheap.poll();
            
            int curIndex = top.getKey();
            
            if (place == 1) {
                ans[curIndex] = "Gold Medal";
            } else if (place == 2) {
                ans[curIndex] = "Silver Medal";
            } else if (place == 3) {
                ans[curIndex] = "Bronze Medal";
            } else {
                ans[curIndex] = String.valueOf(place);
            }
            place++;
             
        }
        
        return ans;
    }
}