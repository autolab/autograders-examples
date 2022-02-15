public class Missing {
  public static int findSmallestMissingPositive(int[] L) {
    // brute force solution
    int currentPosInt = 0;
    boolean found = true;
    while (found) {
      currentPosInt++;
      found = false;
      for (int i = 0; i < L.length; i++) {
        if (L[i] == currentPosInt) {
          found = true;
        }
      }
    }
    return currentPosInt;
  }
}
