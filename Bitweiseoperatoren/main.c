#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint16_t A;
    uint16_t B;
    do {
        printf("A in HEX eingeben: ");
        if (scanf("%04X", &A) != 1) {
            printf("Keine gueltige HEX Zahl\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }
    }while (1);
    do {
        printf("B in HEX eingeben: ");
        if (scanf("%04X", &B) != 1) {
            printf("Keine gueltige HEX Zahl\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }
    }while (1);
    printf("%hx\n", A);
    printf("%hx\n", B);
    return 0;
}
