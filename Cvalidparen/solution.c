#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * Returns whether `parenString` has valid parentheses. 
 *
 * A string has valid parentheses if:
 * - Each open parenthesis has a corresponding close parenthesis.
 * - Open parentheses are closed in the correct order.
 * - There are no extra close parentheses. 
 * 
 * @pre The only characters in `parenString` are '(' and ')'.
 */
bool validParenthesis(const char *parenString) {
    int length = strlen(parenString);
    int numOpen = 0;
    for (int i = 0; i < length; i++)
        if (parenString[i] == '(')
            numOpen++;
        else if (parenString[i] == ')')
            numOpen--;
        if (numOpen < 0)
            return false;
    return numOpen == 0;
}
