import solvesCryptarithm, random, string

def shuffleWord(s):
    s = list(s)
    random.shuffle(s)
    return "".join(s)

def test(name, tests):
    score = 0
    for test in tests:
        puzzle = test[0]
        solution = test[1]
        expectedResult = test[2]
        studentResult = solvesCryptarithm.solvesCryptarithm(puzzle, solution)
        if studentResult == expectedResult: score += 1
        else: print(f'Test failed: solvesCryptarithm({puzzle}, {solution})')
    print(f'{name} Tests Score: {score}/{len(tests)}')
    return score

def basicTests():
    print('Running Tests...')
    tests = [
        ('SEND + MORE = MONEY', 'OMY--ENDRS', True),
        ('NUMBER + NUMBER = PUZZLE', 'UMNZP-BLER', True),
        ('TILES + PUZZLES = PICTURE', 'UISPELCZRT', True),
        ('ANT + BAT = BEE', 'ANEB--T', True),
        ('ANT + EEL = DOG', 'GEADLNTO', True),
        ('SEND + MORE = MONEY', 'OMY-ENDRS', False),
        ('SEND + MORE = MONY', 'OMY--ENDRS', False),
        ('SEND + MORE = MONEY', 'OMY--ENDR-', False),
        ('HI + BYE = BOB', '---------', False),
        ('ANT + BAT = BEE', 'NETBA--', False)
    ]
    return test('Basic', tests)

def randomTests():
    tests = []
    crypts = [
    ( 'ANT + BAT = BEE' , 'ANEB--T' ),
    ( 'ANT + BAT = DOG' , 'GBNADTO' ),
    ( 'ANT + BAT = EEL' , 'LANBET' ),
    ( 'ANT + BAT = FLY' , 'YBNAFTL' ),
    ( 'ANT + BAT = FROG', 'FAGBRNTO' ),
    ( 'ANT + BAT = HEN' , 'NAEBHT' ),
    ( 'ANT + BAT = RAM' , 'NAT-MBR' ),
    ( 'ANT + BEE = DOG' , 'AOTBDENG' ),
    ( 'ANT + BEE = EEL' , 'NBTAE-L' ),
    ( 'ANT + BEE = FLY' , 'ALTBFENY' ),
    ( 'ANT + BEE = RAM' , 'AMBRNET' ),
    ( 'ANT + CAT = BEE' , 'NAECB-T' ),
    ( 'ANT + CAT = DOG' , 'GCNADTO' ),
    ( 'ANT + CAT = EEL' , 'LANCET' ),
    ( 'ANT + CAT = FLY' , 'YCNAFTL' ),
    ( 'ANT + CAT = FROG', 'FAGCRNTO' ),
    ( 'ANT + CAT = HEN' , 'NAECHT' ),
    ( 'ANT + CAT = RAM' , 'NAT-MCR' ),
    ( 'ANT + DOG = BAT' , 'GODNATB' ),
    ( 'ANT + DOG = BEE' , 'EAODGBTN' ),
    ( 'ANT + DOG = CAT' , 'GODNATC' ),
    ( 'ANT + DOG = EEL' , 'AGDETLON' ),
    ( 'ANT + DOG = HEN' , 'ONEDAGTH' ),
    ( 'ANT + DOG = RAM' , 'DARTGONM' ),
    ( 'ANT + DOG = RAT' , 'GODNATR' ),
    ( 'ANT + EEL = BAT' , 'LNEATB' ),
    ( 'ANT + EEL = BEE' , 'NATL-EB' ),
    ( 'ANT + EEL = CAT' , 'LNEATC' ),
    ( 'ANT + EEL = DOG' , 'GEADLNTO' ),
    ( 'ANT + EEL = FLY' , 'YNEALFT' ),
    ( 'ANT + EEL = RAM' , 'ATLMERN' ),
    ( 'ANT + EEL = RAT' , 'LNEATR' ),
    ( 'ANT + FLY = BAT' , 'YLFNATB' ),
    ( 'ANT + FLY = BEE' , 'EALFYBTN' ),
    ( 'ANT + FLY = CAT' , 'YLFNATC' ),
    ( 'ANT + FLY = HEN' , 'LNEFAYTH' ),
    ( 'ANT + FLY = RAM' , 'FARTYLNM' ),
    ( 'ANT + FLY = RAT' , 'YLFNATR' ),
    ( 'ANT + FROG = SANTA', 'SOGNTFAR' ),
    ( 'ANT + HEN = DOG' , 'HOTADNEG' ),
    ( 'ANT + HEN = FLY' , 'HLTAFNEY' ),
    ( 'ANT + HEN = RAM' , 'AMHRENT' ),
    ( 'ANT + RAM = DOG' , 'GARDMNTO' ),
    ( 'ANT + RAM = EEL' , 'LNRAMET' ),
    ( 'ANT + RAM = FLY' , 'YARFMNTL' ),
    ( 'ANT + RAT = BEE' , 'NAERB-T' ),
    ( 'ANT + RAT = DOG' , 'GRNADTO' ),
    ( 'ANT + RAT = EEL' , 'LANRET' ),
    ( 'ANT + RAT = FLY' , 'YRNAFTL' ),
    ( 'ANT + RAT = HEN' , 'NAERHT' )]
    # Correct
    for _ in range(5):
        cryptarithm = random.choice(crypts)
        puzzle, soln = cryptarithm
        newTest = (puzzle, soln, True)
        tests.append(newTest)
    # Incorrect
    for _ in range(5):
        puzzle, soln = random.choice(crypts)
        word1, plus, word2, equal, word3 = tuple(puzzle.split(" "))
        c = random.choice(string.ascii_uppercase)
        while (c in word1 or
               c in word2 or
               c in word3):
            c = random.choice(string.ascii_uppercase)
        soln = c * len(soln)
        newTest = (puzzle, soln, False)
        tests.append(newTest)
    return test('Random', tests)

def main():
    basicScore = basicTests()
    randomScore = randomTests()
    print('{"scores": {"Basic Tests": %s, "Random Tests": %s}}' % (basicScore, randomScore))

main()
