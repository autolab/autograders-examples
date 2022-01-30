#include <assert.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
  // turn off IO buffering
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  int N;
  int res;

  cin >> N;

  vector<int> arr(N);
  // map from current index to original index
  vector<int> m(N);

  for (int i = 0; i < N; i++) {
    arr.at(i) = i;
    m.at(i) = i;
  }

  /* Sorting Algorithm */
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      // cout << m.at(j - 1) << " " << m.at(j) << endl;
      int actual_j_pred, actual_j;
      for (int k = 0; i < N; k++) {
        if (m.at(k) == j - 1) {
          actual_j_pred = k;
          cout << actual_j_pred << " ";
          break;
        }
      }
      for (int k = 0; i < N; k++) {
        if (m.at(k) == j) {
          actual_j = k;
          cout << actual_j << endl;
          break;
        }
      }

      cin >> res;

      switch (res) {
        case -1:
        case 0:
          break;
        case 1:
          // swap(m.at(j - 1), m.at(j));
          // swap(arr.at(m.at(j - 1)), arr.at(m.at(j)));
          swap(m.at(actual_j_pred), m.at(actual_j));
          break;
        default:
          assert("Autograder broken?" && 0);
      }
    }
  }

  /* Answer is ready */
  cout << -1 << endl;

  /* Output answer */
  for (int i = 0; i < N; i++) {
    // cout << arr.at(i) << " ";
    cout << m.at(i) << " ";
  }
  cout << endl;

  return 0;
}
