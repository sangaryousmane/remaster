#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

pid_t check(pid_t pid) {
    return (pid > 0) ? 1 : 0;
}
int _putchar(int c){
    return write(1, &c, 1);
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

//extern char **environ;
char *_strcat(char *dest, const char *src);


void read_getline();

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    if (*lineptr == NULL) {
        *n = 128;
        *lineptr = (char *) malloc(*n * sizeof(char));
        if (*lineptr == NULL) {
            return -1;
        }
    }
    size_t i = 0;
    int c;
    while ((c = fgetc(stream)) != EOF) {
        if (i >= *n - 1) {
            *n *= 2;
            char *new_ptr = (char *) malloc(*n * sizeof(char));
            if (new_ptr == NULL) {
                return -1;
            }
            for (size_t j = 0; j < i; j++) {
                new_ptr[j] = (*lineptr)[j];
            }
            free(*lineptr);
            *lineptr = new_ptr;
        }
        (*lineptr)[i++] = c;
        if (c == '\n') {
            break;
        }
    }
    (*lineptr)[i] = '\0';
    return i == 0 && c == EOF ? -1 : i;
}

char *_strtok(char *str, const char *delim);

int main(int argc, char *argv[], char **envp) {

    int i = 0;
    while (envp[i] != NULL) {
        char *str = envp[i];
        while (*str != '\0') {
            _putchar(*str);
            str++;
        }
        _putchar('qn');
        i++;
    }
//    int i=0;
//    while (envp[i] !=NULL){
//        printf("%d: %s\n", i, envp[i]);
//        i++;
//    }
//    return 0;
}
//    char str[] = "This is a test string";
//    char *token;
//
//    token =_strtok(str, " ");
//    while (token != NULL) {
//        printf("%s\n", token);
//        token = _strtok(NULL, " ");
//    }


void read_getline() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = my_getline(&line, &len, stdin);
    if (nread != -1) {
        printf("Read %zu characters: %s", nread, line);
    }
    free(line);
}

int i_n(void) {
    if (isatty(STDIN_FILENO) == 1) {
        /*execute on interactive mode*/
    } else {
        /*execute on non-iteractive mode*/
    }
    return 0;
}

char *shorten_cmd(char *cmd) {
    char *cmd_path, *p_c, *pt, *fpath;
    int cl, dl;
    struct stat buf;

    cmd_path = getenv("PATH");

    if (cmd_path) {
        /* Duplicate the cmd_path string -> remember to free up memory for this because strdup allocates memory that needs to be freed*/
        p_c = strdup(cmd_path);
        /* Get length of the cmd that was passed */
        cl = strlen(cmd);

        /* Let's break down the cmd_path variable and get all the directories available*/
        pt = strtok(p_c, ":");

        while (pt != NULL) {
            /* Get the length of the directory*/
            dl = strlen(pt);
            /* allocate memory for storing the cmd name together with the directory name */
            fpath = malloc(cl + dl +
                           2); /* NB: we added 2 for the slash and null character we will introduce in the full cmd */
            /* to build the cmd_path for the cmd, let's copy the directory cmd_path and concatenate the cmd to it */
            strcpy(fpath, pt);
            strcat(fpath, "/");
            strcat(fpath, cmd);
            strcat(fpath, "\0");

            /* let's test if this file cmd_path actually exists and return it if it does, otherwise try the next directory */
            if (stat(fpath, &buf) == 0) {
                /* return value of 0 means success implying that the fpath is valid*/

                /* free up allocated memory before returning your fpath */
                free(p_c);

                return (fpath);
            } else {
                /* free up the fpath memory so we can check for another cmd_path*/
                free(fpath);
                pt = strtok(NULL, ":");

            }

        }

        /* if we don't get any fpath that exists for the cmd, we return NULL, but we need to free up memory for p_c */
        free(p_c);

        /* before we exit without luck, let's see if the cmd itself is a fpath that exists */
        if (stat(cmd, &buf) == 0) {
            return (cmd);
        }
        return (NULL);
    }
    return (NULL);
}

int getInt(char *argv[]) {
    char prompt[100];
//    fgets(input, sizeof(input), stdin);
    write(STDOUT_FILENO, "#c_isfun$ ", 11);
    argv[0] = prompt;
    fgets(prompt, sizeof(prompt), stdin);;
    int value = execve(argv[0], argv, NULL);

    if (value == -1) {
        perror("Error!");
    }
    printf("DONE.");
    return 0;
}

