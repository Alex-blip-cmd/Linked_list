#include <stdio.h>
#include <stdint.h>
#include "bitop.h"

int main(void) {
    uint16_t A;
    uint16_t B;
    int choice;
    do {
        print_status(A, B);
        printf("----------------------------------------\n");
        printf("1  A eingeben (Hex)\n");
        printf("2  B eingeben (Hex)\n");
        printf("3  A = A + B\n");
        printf("4  A = A UND B\n");
        printf("5  A = A ODER B\n");
        printf("6  A = A XOR B\n");
        printf("7  A = NICHT A\n");
        printf("8  A um B Stellen nach links schieben\n");
        printf("9  A um B Stellen nach rechts schieben\n");
        printf("10 Ein Bit in A setzen\n");
        printf("11 Ein Bit in A löschen\n");
        printf("12 Ein Bit in A umschalten\n");
        printf("13 Ein Bit in A pruefen\n");
        printf("0  Ende\n");
        printf("Wahl: ");
        if (scanf("%d", &choice) != 1) {
            printf("Fehleingabe! Bitte eine Zahl eingeben.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        unsigned int temp_hex;
        int bit_num;
        switch (choice) {
            case 0:
                printf("Programm beenden.\n");
                break;
            case 1:
                printf("Neue Hexzahl für A eingeben: ");
                if (scanf("%hx", &temp_hex) == 1) {
                    A = (uint16_t)temp_hex;
                    print_result(A);
                } else {
                    printf("Keine gueltige Hexzahl!\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            case 2:
                printf("Neue Hexzahl für B eingeben: ");
                if (scanf("%hx", &temp_hex) == 1) {
                    B = (uint16_t)temp_hex;
                } else {
                    printf("Keine gueltige Hexzahl!\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            case 3:
                A = A + B;
                print_result(A);
                break;
            case 4:
                A = A & B;
                print_result(A);
                break;
            case 5:
                A = A | B;
                print_result(A);
                break;
            case 6:
                A = A ^ B;
                print_result(A);
                break;
            case 7:
                A = ~A;
                print_result(A);
                break;
            case 8:
                if (B > 15) {
                    printf("B muss zwischen 0 und 15 liegen (ist %u)!\n", B);
                } else {
                    A = A << B;
                    print_result(A);
                }
                break;
            case 9:
                if (B > 15) {
                    printf("B muss zwischen 0 und 15 liegen (ist %u)!\n", B);
                } else {
                    A = A >> B;
                    print_result(A);
                }
                break;
            case 10:
                printf("Bitnummer (0 bis 15): ");
                if (scanf("%d", &bit_num) == 1 && bit_num >= 0 && bit_num <= 15) {
                    A = A | (1u << bit_num);
                    print_result(A);
                } else {
                    printf("Maximale Bitanzahl ist 15\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            case 11:
                printf("Bitnummer (0 bis 15): ");
                if (scanf("%d", &bit_num) == 1 && bit_num >= 0 && bit_num <= 15) {
                    A = A & ~(1u << bit_num);
                    print_result(A);
                } else {
                    printf("Maximale Bitanzahl ist 15\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            case 12:
                printf("Bitnummer (0 bis 15): ");
                if (scanf("%d", &bit_num) == 1 && bit_num >= 0 && bit_num <= 15) {
                    A = A ^ (1u << bit_num);
                    print_result(A);
                } else {
                    printf("Maximale Bitanzahl ist 15\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            case 13:
                printf("Bitnummer (0 bis 15): ");
                if (scanf("%d", &bit_num) == 1 && bit_num >= 0 && bit_num <= 15) {
                    int bit_val = (A >> bit_num) & 1u;
                    printf("Bit %d ist %d\n", bit_num, bit_val);
                } else {
                    printf("Maximale Bitanzahl ist 15\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            default:
                printf("Nur Zahlen zwischen 0 und 13.\n");
                break;
        }
        printf("\n");
    } while (choice != 0);
    return 0;
}
