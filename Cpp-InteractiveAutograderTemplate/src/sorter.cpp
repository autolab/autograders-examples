#include <assert.h>

#include <iostream>
#include <vector>

using namespace std;

bool in_vec(vector<int>& arr, int n) {
  for (auto i : arr) {
    if (i == n) return true;
  }
  return false;
}

int main() {
  // turn off IO buffering
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  int N;
  int res;
  int num_found = 0;
  bool is_min;

  cin >> N;

  vector<int> arr(N, -1);

  while (num_found < N) {
    // find the num_found smallest element
    for (int i = 0; i < N; i++) {
      if (in_vec(arr, i)) continue;
      is_min = true;

      // let i be the new smallest element candidate
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (in_vec(arr, j)) continue;
        cout << i << " " << j << endl;
        cin >> res;
        if (res != -1) {
          is_min = false;
          break;
        }
      }

      if (is_min) {
        arr.at(num_found) = i;
        num_found++;
        break;
      }
    }
  }

  /* Answer is ready */
  cout << -1 << endl;

  /* Output answer */
  for (int i = 0; i < N; i++) {
    cout << arr.at(i) << " ";
  }
  cout << endl;

  return 0;
}
