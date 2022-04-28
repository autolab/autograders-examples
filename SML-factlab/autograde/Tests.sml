structure Tests = 
struct

  (* Each test case consists of a tuple (w, n, a) where 
    w: weight of each test (for scoring)
    n: n! will be calculated
    a: the correct answer of n! *)
  
  val tests = [
    (1, 1, 1),
    (1, 2, 2),
    (1, 3, 6),
    (1, 10, 3628800)
  ]

end