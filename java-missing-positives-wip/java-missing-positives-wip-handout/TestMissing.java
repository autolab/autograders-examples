public class TestMissing {
  // Test cases
  static int[] emptyArray = new int[]{};
  static int[] singleElementArray = new int[]{5};
  static int[] justOneArray = new int[]{1};
  static int[] oddsArray = new int[]{11, 5, 3, 1, 7};
  static int[] missingLastArray = new int[]{9, 8 ,7, 6, 1, 2, 3, 4, 5};
  static int[] randomMissingArray = new int[]{5, 1, 2, 8, 3, 9, 11};

  public static void main(String[] args) {
    // Can only receive credit if all tests are passed
    assert Missing.findSmallestMissingPositive(emptyArray) == 1;
    assert Missing.findSmallestMissingPositive(emptyArray) == 1;
    assert Missing.findSmallestMissingPositive(emptyArray) == 2;
    assert Missing.findSmallestMissingPositive(emptyArray) == 2;
    assert Missing.findSmallestMissingPositive(emptyArray) == 10;
    assert Missing.findSmallestMissingPositive(emptyArray) == 4;
  }
}
