#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool nfa(char *str, int pos, bool start_b, bool end_a) {
    if (pos == strlen(str)) return start_b && end_a;

    char ch = str[pos];

    if (!start_b) {
        if (ch == 'b') return nfa(str, pos + 1, true, end_a);
        return false;
    } else {
        if (ch == 'a') return nfa(str, pos + 1, start_b, true);
        return nfa(str, pos + 1, start_b, end_a);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (nfa(str, 0, false, false))
        printf("The string is accepted by the NFA.\n");
    else
        printf("The string is not accepted by the NFA.\n");

    return 0;
}

