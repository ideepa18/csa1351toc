#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to simulate the NFA
bool nfa(char *str, int pos, bool start_with_0, bool end_with_1) {
    if (pos == strlen(str)) {
        return start_with_0 && end_with_1;
    }

    char ch = str[pos];

    if (!start_with_0) {
        // If we haven't found the starting '0', check if the current character is '0'
        if (ch == '0') {
            return nfa(str, pos + 1, true, end_with_1);
        }
        return false; // If the string doesn't start with '0', reject it
    } else {
        // If the string has started with '0', continue checking
        if (ch == '1') {
            return nfa(str, pos + 1, start_with_0, true);
        } else {
            return nfa(str, pos + 1, start_with_0, end_with_1);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (nfa(str, 0, false, false)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}

