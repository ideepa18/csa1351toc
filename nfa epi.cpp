#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100

void e_closure(int state, int nfa[][MAX_STATES], int n, int *closure) {
    closure[state] = 1;
    for (int i = 0; i < n; i++) {
        if (nfa[state][i] && !closure[i]) {
            e_closure(i, nfa, n, closure);
        }
    }
}

int main() {
    int n, nfa[MAX_STATES][MAX_STATES] = {0};
    int closure[MAX_STATES] = {0};

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the e-moves (state pairs) (enter -1 -1 to end):\n");
    while (1) {
        int from, to;
        scanf("%d %d", &from, &to);
        if (from == -1 && to == -1) break;
        nfa[from][to] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) closure[j] = 0;
        e_closure(i, nfa, n, closure);
        printf("e-closure(%d): ", i);
        for (int j = 0; j < n; j++) {
            if (closure[j]) printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}

