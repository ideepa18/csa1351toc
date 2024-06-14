#include <stdio.h>
#include <string.h>

int dfa(char *str) {
    int state = 0;  // Initial state

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        switch (state) {
            case 0:
                if (ch == 'a') state = 1;
                else state = 3; // Dead state
                break;
            case 1:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 2;
                else state = 3; // Dead state
                break;
            case 2:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 2;
                else state = 3; // Dead state
                break;
            case 3:
                break;  // Dead state, remain here
        }
    }

    return state == 1;  // Accepting state
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (dfa(str))
        printf("The string is accepted by the DFA.\n");
    else
        printf("The string is not accepted by the DFA.\n");

    return 0;
}

