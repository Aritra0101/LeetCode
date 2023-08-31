class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ac[] = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        for(int i=0; i<n; i++) {
            if(map.containsKey(target-nums[i])) {
                ac[0] = i;
                ac[1] = map.get(target-nums[i]);
                return ac;
            } else {
                map.put(nums[i], i);
            }
        }

        return ac;
    }
}