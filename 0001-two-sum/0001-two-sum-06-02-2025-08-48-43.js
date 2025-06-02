/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const mp = new Map();
    for(let i=0;i<nums.length;i++){
        mp.set(nums[i],i);
    }
    // code 
    for (let i = 0; i < nums.length; i++) {
        let req = target - nums[i];
        if (mp.has(req) &&mp.get(req)!= i ) {
            return [mp.get(req), i];
        }
        mp.set(nums[i], i);
    }

    return [];

};