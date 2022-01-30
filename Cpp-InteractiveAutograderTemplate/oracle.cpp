#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#define N 10

using namespace std;

int main() {
  // turn off IO buffering
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  vector<int> data;

  for (int i = 0; i < N; i++) {
    data.push_back(i);
  }

  auto rng = default_random_engine{};
  shuffle(begin(data), end(data), rng);

  // Represents number of elements
  cout << N << endl;

  // wait for user queries of comparison between element at index i and index j
  // exits loop when user sends non-integer, i.e DONE
  int query_i, query_j;
  while (cin >> query_i >> query_j) {
    if (query_i < 0 || query_j < 0 || query_i >= N || query_j >= N) {
      cout << "INVALID" << endl;
      continue;
    }
    if (data[query_i] == data[query_j])
      cout << 0 << endl;
    else if (data[query_i] < data[query_j])
      cout << -1 << endl;
    else
      cout << 1 << endl;
  }

  // user outputs sorted array of N indices as answer
  vector<int> user_answer;
  int next_idx;
  int n = N;
  while (n-- && cin >> next_idx) {
    user_answer.push_back(next_idx);
  }

  /* Check if user answer is correct */
  int c = 0;
  bool success = true;
  for (auto idx : user_answer) {
    if (data[idx] != c) {
      success = false;
      break;
    }
    c++;
  }
  if (c != N) success = false;

  // Magic constant to indicate to driver that what comes next should be
  // regarded as autograding result and not piped back to student binary
  cout << "AUTOGRADER_COMPLETE" << endl;

  if (success) {
    cout << "{\"scores\": {\"Correctness\": 100}}" << endl;
  } else {
    cout << "{\"scores\": {\"Correctness\": 0}}" << endl;
  }
}
