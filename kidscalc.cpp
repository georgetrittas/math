#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ask_question(char operation, int level);

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("\nSelect operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                ask_question('+', 1);
                break;
            case 2:
                ask_question('-', 1);
                break;
            case 3:
                ask_question('*', 1);
                break;
            case 4:
                ask_question('/', 1);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void ask_question(char operation, int level) {
    int num1 = rand() % 6;
    int num2 = rand() % 6;
    int correct_answer, user_answer, attempts = 0;

    if (operation == '-') {
        if (num1 < num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
    } else if (operation == '/') {
        while (num2 == 0) {
            num2 = rand() % 6;
        }
        num1 = num1 * num2;
    }

    switch (operation) {
        case '+':
            printf("What is: %d + %d? ", num1, num2);
            correct_answer = num1 + num2;
            break;
        case '-':
            printf("What is: %d - %d? ", num1, num2);
            correct_answer = num1 - num2;
            break;
        case '*':
            printf("What is: %d * %d? ", num1, num2);
            correct_answer = num1 * num2;
            break;
        case '/':
            printf("What is: %d / %d? ", num1, num2);
            correct_answer = num1 / num2;
            break;
    }

    while (attempts < 3) {
        scanf("%d", &user_answer);
        if (user_answer == correct_answer) {
            printf("Correct!\n");
            return;
        } else {
            printf("Wrong. Try again: ");
            attempts++;
        }
    }

    printf("The correct answer is: %d\n", correct_answer);
}
