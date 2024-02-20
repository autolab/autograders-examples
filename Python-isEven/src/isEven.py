def isEven(x):
    if not isinstance(x, int):
        raise ValueError("Input must be an integer")
    return (x % 2 == 0)