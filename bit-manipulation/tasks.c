#include <stdio.h>
#include <unistd.h>

int _putchar(int c) {
    return write(1, &c, 1);
}

// https://chat.whatsapp.com/JQXjqJ7S3apErm9dFuyoQV:
// Write a function that converts a binary number to an unsigned int.
unsigned int binary_to_uint(const char *b) {
    unsigned int decimal = 0;
    int i = 0;

    if (b != NULL) {
        while (b[i] != '\0') {

            /* 48 is the ASCII of 0 and 49 is the ASCII of 1 */
            if (b[i] != 48 && b[i] != 49) {
                return 0;
            } else {
                decimal = decimal * 2 + (b[i] - 48);
            }
            i++;
        }

    } else {
        return 0;
    }
    return decimal;
}

// Write a function that prints the binary representation of a number.
void print_binary(unsigned long int n) {

    if (n == 0) {
        putchar('0');
        return;
    }


    unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
    int flag = 0;
    while (mask) {
        if (n & mask) {
            putchar('1');
            flag = 1;
        } else if (flag) {
            putchar('0');
        }
        mask >>= 1;
    }
}

// Get endianess
int get_endianness(void) {
    int i = 1;
    char *p = (char *) &i;
    return (*p == 1);
}

int get_bit(unsigned long int n, unsigned int index) {
    if (n == 0 && index < 64) {
        return 0;
    }
    while (index <= 63 && n != 0) {
        if (index == 0) {
            return n & 1;
        }
        n >>= 1;
        index--;
    }
    return -1;
}

int set_bit(unsigned long int *n, unsigned int index) {
    if (index > 63) {
        return -1;
    }
    unsigned long int mask = 1;
    mask <<= index;
    if ((*n & mask) == 0) {
        *n |= mask;
    }
    return 1;
}

/**
 * clear_bit - sets the value of a bit to 0.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if it worked, -1 if it didn't.
 */
int clear_bit(unsigned long int *n, unsigned int index) {
    if (index > 63) {
        return -1;
    }
    unsigned long int mask = ~(1UL << index);
    *n &= mask;
    return 1;
}
unsigned int flip_bits(unsigned long int n, unsigned long int m) {
    unsigned int nbits = 0;
    unsigned long int diff = n ^ m;
    while (diff) {
        nbits += diff & 1;
        diff >>= 1;
    }
    return nbits;
}
void generalDisplay() {
    unsigned long int n;

    n = 1024;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 0;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    clear_bit(&n, 1);
    printf("%lu\n", n);


}


