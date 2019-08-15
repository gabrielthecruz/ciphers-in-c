#include<stdio.h>

void encrypt(char *str, int *key);
void decrypt(char *str, int *key);


void main() {
    char str[100], *ptr_str = str;
    int key, *ptr_key = &key;
    
    printf("Write your message: ");
    scanf("%[^\n]%*c", &str);

    printf("Digit your key: ");
    scanf("%d", &key);

    printf("Plain Text: %s\n", str);

    encrypt(ptr_str, ptr_key);
    printf("Encrypted Text: %s\n", str);

    decrypt(ptr_str, ptr_key);
    printf("Decrypted Text: %s\n", str);
}


void encrypt(char *str, int *key) {
    *key = *key < 0 ? *key + 26 : *key;

    while(*str) {
        if (*str >= 65 && *str <= 90)
            *str = (*str + *key - 65) % 26 + 65;
        
        else if (*str >= 97 && *str <= 122)
            *str = (*str + *key - 97) % 26 + 97;

        str++;
    }
}

void decrypt(char *str, int *key) {
    *key = 26 - *key;

    while(*str) {
        if (*str >= 65 && *str <= 90)
            *str = (*str + *key + 65) % 26 + 65;
        
        else if (*str >= 97 && *str <= 122)
            *str = (*str + *key - 97) % 26 + 97;

        str++;
    }
}
