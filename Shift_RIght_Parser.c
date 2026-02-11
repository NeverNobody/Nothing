#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

int reduce() {
    if (top >= 1 && stack[top] == 'd' && stack[top-1] == 'i') {
        top--;
        stack[top] = 'F';
        return 1;
    }
    if (top >= 2 && stack[top] == 'F' && stack[top-1] == '*' && stack[top-2] == 'T') {
        top -= 2;
        stack[top] = 'T';
        return 1;
    }
    if (top >= 2 && stack[top] == 'T' && stack[top-1] == '+' && stack[top-2] == 'E') {
        top -= 2;
        stack[top] = 'E';
        return 1;
    }
    if (top >= 0 && stack[top] == 'F') {
        stack[top] = 'T';
        return 1;
    }
    return 0;
}

int main() {
    char input[50];
    int i = 0;

    printf("Enter input: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while (input[i]) {
        if (input[i] == 'i' && input[i+1] == 'd') {
            push('i'); push('d');
            i += 2;
            printf("%s\t%s\tSHIFT id\n", stack, &input[i]);
        } else {
            push(input[i++]);
            printf("%s\t%s\tSHIFT\n", stack, &input[i]);
        }
        while (reduce())
            printf("%s\t%s\tREDUCE\n", stack, &input[i]);
    }

    /* final reduction */
    if (top == 0 && stack[top] == 'T')
        stack[top] = 'E';

    if (strcmp(stack, "E") == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}
