#include <math.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#define N 20

using namespace std;

int main() {
  auto rng = default_random_engine{};
  vector<int> data, answer(N);
  vector<int> user_answer;
  int query_i, query_j;
  int next_idx;
  int n;
  int n_queries = 0;
  string answer_string;
  string array_string;
  string correctness;
  string queries;
  ostringstream stream;

  // turn off IO buffering
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  for (int i = 0; i < N; i++) {
    data.push_back(i);
  }

  shuffle(begin(data), end(data), rng);

  for (int i = 0; i < N; i++) {
    stream << data.at(i) << " ";
  }
  array_string = stream.str();
  stream.str("");
  stream.clear();

  for (int i = 0; i < N; i++) {
    answer[data.at(i)] = i;
  }

  for (int i = 0; i < N; i++) {
    stream << answer.at(i) << " ";
  }

  answer_string = stream.str();

  // Represents number of elements
  cout << N << endl;
  n = N;

  // wait for user queries of comparison between element at index i and index j
  // exits loop when user sends non-integer, i.e DONE
  while (cin >> query_i) {
    if (query_i == -1) {
      break;
    }
    cin >> query_j;
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

    n_queries++;
  }

  cout << "AWAITING_ANSWER" << endl;

  // user outputs sorted array of N indices as answer
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

  // query score scales inversely with number of queries made,
  // ideally expecting N log(N) solution up to a scaling constant C
  float C = 3.;
  float query_score = min(C * (N * log(N) * 100. / n_queries), 100.);
  if (success) {
    correctness =
        "{\"correctness\": 100, \"query_score\": " + to_string(query_score) +
        string("}");
  } else {
    correctness = "{\"correctness\": 0, \"query_score\": 0 }";
    queries = "{\"query_score\": 0}";
  }

  cout << "{\"scores\": " + correctness +
              ", \"queries\": " + to_string(n_queries) +
              ", \"correct_answer\": \"" + answer_string +
              "\", \"array:\": \"" + array_string + "\"}"
       << endl;
}
