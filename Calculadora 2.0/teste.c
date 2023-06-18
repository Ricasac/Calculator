#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Base functions
void intro();
int menu();
void help();
float calculator();

// Aux functions
int read_int_from_stdin(int lower_bound, int upper_bound, char *input_msg);
void cleanBufferStdin();
void WinOrLin();

int main() {
    intro();
    menu();
    return 0;
}

void intro() {
    puts("Hello, this program was made as a simple calculator.");
    puts("It can only add, subtract, multiply and divide.");
#ifdef _WIN32
    Sleep(5000); // Sleep for 5 seconds (Windows specific)
#else
    sleep(5); // Sleep for 5 seconds (Unix/Linux specific)
#endif
    WinOrLin();
}

int read_int_from_stdin(int lower_bound, int upper_bound, char *input_msg) {
    int option;

    do {
        puts(input_msg);
        printf("Option: ");
        scanf("%d", &option);
        cleanBufferStdin();
    } while (option < lower_bound || option > upper_bound);

    return option;
}

void help() {
    WinOrLin();
    puts("You will be asked to insert two digits.");
    puts("After that, you will be asked which kind of operation you want to make.");
    puts("Remember that, in the division, the first number you input will be the dividend and the second will be the divisor.");
    puts("And in subtraction, it will be the first number minus the second.");
    getchar();
    WinOrLin();
}

float calculator() {
    float num1, num2, result;
    char operator;

    WinOrLin();
    puts("Please insert the first number:");
    scanf("%f", &num1);
    puts("Please insert the second number:");
    scanf("%f", &num2);

    puts("What kind of operation do you want to use?");
    scanf(" %c", &operator); // Read operator with a space before %c to skip whitespace characters

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;

        default:
            puts("Invalid operator.");
            return 0;
    }
    return result;
}

void cleanBufferStdin(void) {
    int chr;
    do {
        chr = getchar();
    } while (chr != '\n' && chr != EOF);
}

void WinOrLin(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int menu() {
    int option;

    do {
        puts("***********************************************Menu***********************************************\n");
        puts("1 - Calculate");
        puts("2 - Help");
        puts("3 - Exit");

        option = read_int_from_stdin(1, 3, "Please input the appropriate number to advance");

        switch (option) {
            case 1:
                printf("Result: %.2f\n", calculator());
                cleanBufferStdin();
                getchar();
                WinOrLin();
                break;
            case 2:
                help();
                break;
            default:
                break;
        }
    } while (option != 3);

    return 0;
}