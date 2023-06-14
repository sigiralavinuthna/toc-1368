#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 100
int current_state = 0;
int simulate_NFA(char* input_string) {
    int length = strlen(input_string);
    for (int i = 0; i < length; i++) {
        if (current_state == 0 && input_string[i] == '0') {
            current_state = 1;
        } else if (current_state == 1 && input_string[i] == '1') {
            current_state = 2;
            return 1;
        } else {
            current_state = 0;
            return 0;
        }
    }
    return 0;
}
int main() {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string to check: ");
    scanf("%s", input_string);
    if (simulate_NFA(input_string)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    return 0;
}
