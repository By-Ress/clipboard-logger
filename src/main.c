//
// Created by Baris Ortanca on 31/07/2025.
//

#include "clipboard.h"
#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


int main() {
    struct stat st = {0};
    if (stat("out", &st) == -1) {
        mkdir("out", 0700);
    }

    FILE* file = fopen("out/history_clipboard.txt", "w");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    char* data = get_clipboard_text();
    if (data) {
        fprintf(file, "%s\n", data);
        fflush(file);
    }

    while (1) {
        sleep(1);

        char* new_data = get_clipboard_text();
        if (new_data && strcmp(new_data, data) != 0) {
            fprintf(file, "%s\n", new_data);
            fflush(file);
            free(data);
            data = new_data;
        } else {
            free(new_data);
        }
    }

    fclose(file);
    free(data);
    return 0;

}