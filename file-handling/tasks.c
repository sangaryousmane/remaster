#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

ssize_t read_text_file(const char *filename, size_t letters){
    int code;
    char *buffer;
    ssize_t read_file, write_file;

    if (!filename){
        return 0;
    }

    code= open(filename, O_RDONLY);
    buffer= malloc(sizeof(char) * (letters));


    if(code == -1 || !buffer){
        return 0;
    }

    read_file = read(code, buffer, letters);
    write_file= write(1, buffer, read_file);

    close(code);
    free(buffer);
    return write_file;
}

int create_file(const char *filename, char *text_content){

    int code;

    if (!filename){
        return (-1);
    }
    code = open(filename, O_WRONLY | O_TRUNC, 600);

    if (code == -1){
        write(code, "fails", sizeof("fails"));
        return (-1);
    }
    write(code, text_content, sizeof(text_content));
    close(code);
    return code;

}
//int create_file(const char *filename, char *text_content) {
//    int file_handler, t, length = 0;
//    if (!filename)
//        return (-1);
//    file_handler = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
//    if (file_handler < 0)
//        return (-1);
//    if (text_content) {
//        for (int i = 0; *(text_content + i); i++)
//            length++;
//        t = write(file_handler, text_content, length);
//        if (t != length) {
//            close(file_handler);
//            return (-1);
//        }
//    }
//    close(file_handler);
//    return (1);
//}


int append_text_to_file(const char *filename, char *text_content)
{
    int file_d, code, sz = 0;

    if (!filename)
        return (-1);

    file_d = open(filename, O_WRONLY | O_APPEND);
    if (file_d < 0)
        return (-1);

    if (text_content)
    {
        while (text_content[sz])
            sz++;
        code = write(file_d, text_content, sz);
        if (code != sz)
            return (-1);
    }

    close(file_d);

    return (1);
}

