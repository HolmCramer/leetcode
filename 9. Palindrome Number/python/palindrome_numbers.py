class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        if x < 0:
            return False
        elif x < 10:
            return True        
        else:
            numlist = [int(i) for i in list(str(x))]
            xlen = len(numlist)
            
            if xlen % 2 != 0:
                steps = int((xlen-1) /2)
            else:
                steps = int(xlen /2)   
        
            numleft = [numlist[i] for i in range(0, steps)]
            numright = [numlist[j] for j in range(xlen-1, xlen-1-steps, -1)]

            if numleft != numright:
                return False
            else:
                return True