def palindrome(integer):
    strInt = str(integer)
    reversedStrInt = strInt[::-1]
    if strInt == reversedStrInt:
        return True
    return False

# palindrome without strings
def palindromeWithoutStrings(n):
        if n < 0:
            return False
        
        # find length of integer
        length = 0
        while n > 0:
            length += 1
            n //= 10
        
        if length == 1:
            return True
        
        reverse = 0

        for i in range(length):
            last_digit = temp_n % 10 
            reverse = reverse + last_digit * (10 ** (length - i - 1))
            temp_n = temp_n // 10
        
        if reverse == n:
            return True
        return False