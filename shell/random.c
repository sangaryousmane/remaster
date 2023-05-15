#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int delimiter() {
    char sentence[] = "The quick brown fox  jumps over the lazy dog.";
    char *token;

    size_t size = sizeof(sentence);
    token = malloc(sizeof(char) * size);
    if(token) {
        token = strtok(sentence, " ");
    }

    while (token){
        printf("%s\n", token);
        token= strtok(NULL, " ");
    }
    return (0);
}

int getInput(){
    char buffer[512];
    size_t length = 0;


    printf("Enter input: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("Line read (%zd bytes) %s ",length, buffer);
//    perror("error!");
    return 0;
}

void print_calendar(int year) {

    int month, day;
    struct tm timeinfo = {0};
    char buffer[80];

    for (month = 1; month <= 12; month++) {
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = 1;
        mktime(&timeinfo);

        strftime(buffer, 80, "%B %Y", &timeinfo);
        printf("%s\n", buffer);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for (day = 1; day <= 31; day++) {
            timeinfo.tm_mday = day;
            mktime(&timeinfo);

            if (timeinfo.tm_mon + 1 != month) {
                break;
            }

            strftime(buffer, 80, "%d", &timeinfo);
            printf("%3s ", buffer);

            if (day % 7 == 0) {
                printf("\n");
            }
        }

        printf("\n");
    }
}

int _strlen(const char *str){
    int i = 0, length = 0;
    for (; str[i] !='\0'; i++){
        length++;
    }
    return length;
}

char *_strcpy(char *dest, const char* src){

//    char *temp = dest;
    int i = 0;

    for (; src[i] !='\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int _isalpha(int c){
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ? 1 : 0;
}

int is_delimiter(char chr, char *str){
    int i = 0;

    for (; str[i] != '\0'; i++){
        if (str[i] == chr){
            return 1;
        }
    }
    return 0;
}

int _isdigit(int c){
    return c >= 48 && c <= 57;
}
int custom_atoi(const char *str){
    int i = 0;
    int result = 0;
    int sign = 1;

    if (str[0] == '-'){
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++){
        if (_isdigit(str[i])){
            result = result * 10 + (str[i] - 48);
        } else{
            break;
        }
    }
    return sign * result;
}

char *_strcat(char *dest, const char *src){
    char *temp = dest + _strlen(dest);

    while (*src != '\0'){
        *temp++ = *src++;
    }
    *temp='\0';
    return dest;
}

