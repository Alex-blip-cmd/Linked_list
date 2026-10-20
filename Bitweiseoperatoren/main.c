#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint16_t A;
    uint16_t B;
    do {
        printf("A in HEX eingeben: ");
        if (scanf("%X", &A) != 1) {
            printf("Error\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }
    }while (1);
    printf("B in HEX eingeben: ");
    scanf("%hx", &B);
    printf("%hx\n", A);
    printf("%hx\n", B);
    return 0;
}
