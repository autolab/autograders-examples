functor MkAutograder 
  (val runTests : bool
   val showScore : bool) =
struct

  val TIME_LIMIT = Time.fromSeconds (LargeInt.fromInt 1)

  fun runTest fact (w, l, ans) =
    (let
      val x = TimeLimit.timeLimit TIME_LIMIT fact l
    in
      if x = ans
      then (print ("Test passed: " ^ (Int.toString l) ^ "! = " ^ (Int.toString ans) ^ "\n"); (w, w))
      else (print ("Test failed: " ^ (Int.toString l) ^ "! gave " ^ (Int.toString x) ^ ", expected " ^ (Int.toString ans) ^ "\n"); (0, w))
    end) handle TimeLimit.TimeOut => (print ("Test " ^ (Int.toString l) ^ "! timed out.\n"); (0, w))
              | _ => (print ("Test " ^ (Int.toString l) ^ "! raised an exception.\n"); (0, w))

  fun runAll fact nil = (0, 0)
    | runAll fact (T::Ts) =
      let
        val (p, t) = runTest fact T
        val (n, tot) = runAll fact Ts
      in
        (p + n, t + tot)
      end

  fun run () = 
    if runTests then
      let
        fun factScore () =
          let
            val (scored, possible) = runAll Factorial.fact Tests.tests
          in
            (Real.fromInt (scored) / Real.fromInt (possible)) * 100.0
          end

        val score = factScore ()
      in
        if showScore
        then print ("{\"scores\": {\"Correctness\": " ^ (Real.toString score) ^ "}}")
        else ()
      end
    else ()
end

structure Autograder = MkAutograder (val runTests = true
                                     val showScore = true)

val _ = Autograder.run ()                        