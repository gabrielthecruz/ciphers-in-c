#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(char *msg, char *key);
void decrypt(char *msg, char *key);


void main() {
    char str[100], *ptr_str = str;
    char key[100], *ptr_key = key;

    printf("Write your message: ");
    scanf("%[^\n]%*c", &str);
    printf("Write your key: ");
    scanf("%s", &key);
    
    printf("\nMessage: %s\n", str);

    encrypt(ptr_str, ptr_key);
    printf("Encrypted: %s\n", str);

    decrypt(ptr_str, ptr_key);
    printf("Decrypted: %s\n", str);
}


void encrypt(char *msg, char *key) {
    char *key_start = key;

    while(*msg) {
        if (isalpha(*msg))
            *msg = 97 + ((tolower(*msg) - 97) + (tolower(*key) - 97)) % 26;

        msg++;
        key++;

        if(!*key)
            key = key_start;
    }
}

void decrypt(char *msg, char *key) {
    char *key_start = key;

    while(*msg) {
        if (isalpha(*msg))
            *msg = 97 + ((tolower(*msg) - 97) - (tolower(*key) - 97) + 26) % 26;

        msg++;
        key++;

        if(!*key)
            key = key_start;
    }
}
