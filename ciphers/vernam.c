#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char *str, const char *key);
void decrypt(char *str, const char *key);
void get_key(char *key, const int len);


void main() {
    char str[100], *ptr_str = str;
    char key[100], *ptr_key = key;

    printf("Write your text: ");
    scanf("%[^\n]%*c", str);

    printf("Write your key (blank to generate): ");
    scanf("%[^\n]%*c", key);

    if(strlen(key) == 0)
        get_key(ptr_key, rand() % strlen(str));


    printf("Plain Text: %s\n\n", str);

    // Encryption
    encrypt(ptr_str, ptr_key);
    printf("Encrypted: %s (%s)\n", str, key);

    //Decryyption
    decrypt(ptr_str, ptr_key);
    printf("Decrypted: %s\n", str, key);
}


void get_key(char *key, const int len) {
    for(int i = 0; i < len; i++, key++) {
        do {
            *key = rand() % 123;
        } while(!isprint(*key) && !isalpha(*key));
    }
}

void encrypt(char *str, const char *key) {
    char *key_begin = key;

    for(; *str; str++, key++) {
        *str ^= *key;

        if(!*key)
            key = key_begin;
    }
}

void decrypt(char *str, const char *key) {
    char *key_begin = key;

    for(;*str;str++, key++) {
        *str = *key ^ *str;
        
        if(!*key)
            key = key_begin;
    }
}
