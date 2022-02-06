#include <stdio.h>
#include "tests.h"

int main() {
    int basic_score = test_basic();

    int length_edge_case_score = test_length_edge_cases();

    int timing_score = test_timing();

    printf("{\"_presentation\": \"semantic\"}\n");
    printf("{\"scores\": { \"Basic Functionality\": %d, \"Edge cases\": %d, \"Timing\": %d } }\n", basic_score, length_edge_case_score, timing_score);

    return 0;
}