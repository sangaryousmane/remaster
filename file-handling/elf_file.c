#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    int code;
    int read_file, write_file;
    char *buf;
    if (!filename)
        return (0);
    code = open(filename, O_RDONLY);
    if (code < 0)
        return (0);
    buf = malloc(sizeof(char) * letters);
    if (!buf)
        return (0);
    read_file = read(code, buf, letters);
    if (read_file < 0)
    {
        free(buf);
        return (0);
    }
    buf[read_file] = '\0';
    close(code);
    write_file = write(STDOUT_FILENO, buf, read_file);
    if (write_file < 0)
    {
        free(buf);
        return (0);
    }
    free(buf);
    return (write_file);
}
