def wordToInt(word, solution):
    result = 0
    for c in word:
        digit = solution.find(c)
        if (digit < 0):
            return None
        result = 10*result + digit
    return result

def solvesCryptarithm(puzzle, solution):
    plusIndex = puzzle.find(' + ')
    equalsIndex = puzzle.find(' = ')
    x1 = wordToInt(puzzle[0:plusIndex], solution)
    x2 = wordToInt(puzzle[3+plusIndex:equalsIndex], solution)
    x3 = wordToInt(puzzle[3+equalsIndex:], solution)
    return (x1 != None) and (x2 != None) and (x3 != None) and (x1 + x2 == x3)
