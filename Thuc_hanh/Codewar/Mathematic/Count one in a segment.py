def  countOnes (left, right) :  
    return count(right) -count ( left- 1 )
def  count (n) : 
    s = 0 
    while n:
        p = n.bit_length()- 1  
        p2 = 1 <<p
        n -= p2
        s += p*(p2>> 1 )+ 1 + n
        
    return s
# source: https://blog.katastros.com/a?ID=00700-203694ab-cff9-40e3-9179-ad6dd44ebf84
