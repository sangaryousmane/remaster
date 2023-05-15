#include <stdio.h>
#include <stdlib.h>

// https://www.freecodecamp.org/news/file-handling-in-c-how-to-open-close-and-write-to-files/

int write_to_file();

int workFile(){
    write_to_file();
    return EXIT_SUCCESS;

}

int write_to_file() {
    FILE *fptr;
    char chr;

    fptr = fopen("file.txt", "w");

    printf("ENTER DATA");
    while ((chr = getchar()) != EOF){
        putc(chr, fptr);
    }
    fclose(fptr);

    fptr = fopen("file.txt", "r");
    while ((chr = getc(fptr)) != EOF){
        printf("%c", chr);
    }
    fclose(fptr);

    // Processing of the file

//    fprintf(fptr, "%s", "Hello world");
    // End of processing


    return EXIT_SUCCESS;
}
