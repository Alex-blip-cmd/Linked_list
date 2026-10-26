//
// Created by pimen on 26.10.2026.
//

#include "bitop.h"
#include <stdio.h>

void print_bits(uint16_t val) {
    for (int i = 15; i >= 0; i--) {
        int bit = (val >> i) & 1;
        printf("%d", bit);
        if (i == 8) {
            printf(" ");
        }
    }
}

void print_status(uint16_t a, uint16_t b) {
    printf("A  Hex: %04X\n", a);
    printf("Bits: ");
    print_bits(a);
    printf("\n");
    printf("B  Hex: %04X\n", b);
    printf("Bits: ");
    print_bits(b);
    printf("\n");
}

void print_result(uint16_t a) {
    printf("A  Hex: %04X\n", a);
    printf("Bits: ");
    print_bits(a);
    printf("\n");
}
