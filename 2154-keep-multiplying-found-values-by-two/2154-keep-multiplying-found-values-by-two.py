# class Solution:
#     def findFinalValue(self, nums: List[int], k: int) -> int:
#         int res=0
#         unoredered_set<int>st
#         for i in range len(nums): 
#             st.insert(nums[i])

#         while(true):
#             if(st.find(k)):
#                 res=2*k
#                 k=res
#             else:
#                 break
#         return res

class Solution:
    def findFinalValue(self, nums: list[int], k: int) -> int:
        st = set(nums)  
        while k in st:  
            k *= 2  
        return k


        