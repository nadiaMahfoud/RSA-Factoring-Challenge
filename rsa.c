#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ullong;

int is_prime(ullong num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for (ullong i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    
    return 1;
}

void factorize(ullong n) {
    for (ullong i = 2; i <= n / 2; i++) {
        if (is_prime(i) && n % i == 0 && is_prime(n / i)) {
            printf("%llu=%llu*%llu\n", n, i, n / i);
            return;
        }
    }
    
    printf("No factorization found for %llu\n", n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        printf("File not found: %s\n", input_file);
        return 1;
    }

    ullong n;
    if (fscanf(file, "%llu", &n) == 1) {
        factorize(n);
    }

    fclose(file);
    return 0;
}

