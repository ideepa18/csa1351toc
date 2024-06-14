#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool S(char *str, int left, int right);
bool A(char *str, int left, int right);

bool S(char *str, int left, int right) {
    if (left > right) return false;

    if (left == right && str[left] == '\0') return true;  // Accept epsilon
    
    if (left < right && str[left] == '0' && str[right] == '0')
        return S(str, left + 1, right - 1);
    
    return A(str, left, right);
}

bool A(char *str, int left, int right) {
    if (left > right) return true;  // Accept epsilon

    if (str[left] == '1')
        return A(str, left + 1, right);
    
    return false;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (S(str, 0, strlen(str) - 1))
        printf("The string belongs to the language.\n");
    else
        printf("The string does not belong to the language.\n");

    return 0;
}

