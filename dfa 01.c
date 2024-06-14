#include <stdio.h>
#include <string.h>

// DFA function to check if the string is accepted
int dfa(char *str) {
    int state = 0;  // Initial state

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        switch (state) {
            case 0:  // Initial state
                if (ch == '0') state = 1;
                else state = 3;  // Dead state
                break;
            case 1:  // After seeing the initial '0'
                if (ch == '0') state = 1;
                else if (ch == '1') state = 2;
                else state = 3;  // Dead state
                break;
            case 2:  // Accept state if we see '1' at the end
                if (ch == '0') state = 1;
                else if (ch == '1') state = 2;
                else state = 3;  // Dead state
                break;
            case 3:  // Dead state
                break;
        }
    }

    return state == 2;  // Accepting state
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

