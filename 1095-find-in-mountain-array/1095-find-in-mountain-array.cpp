/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int index = findPeakElement(mountainArr);
        int n = mountainArr.length();
        
        // Check if the peak element is the target
        if(mountainArr.get(index) == target) return index;
        
        // Check the left side of the peak
        int i1 = binarySearch(mountainArr, target, 0, index - 1, true);
        if(i1 != -1) return i1;
        
        // Check the right side of the peak
        return binarySearch(mountainArr, target, index + 1, n - 1, false);
    }

private:
    int findPeakElement(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0;
        int h = n - 1;
        
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return l;
    }
    
    int binarySearch(MountainArray &mountainArr, int target, int l, int h, bool ascending) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int midVal = mountainArr.get(mid);
            
            if (midVal == target) return mid;
            
            if (ascending) {
                if (midVal < target) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            } else {
                if (midVal > target) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};
