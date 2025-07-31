//
// Created by Baris Ortanca on 31/07/2025.
//


#include "clipboard.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* get_clipboard_text() {
    FILE* pipe = popen("xclip -selection clipboard -o", "r");
    if (!pipe) return NULL;

    char buffer[4096];
    size_t len = fread(buffer, 1, sizeof(buffer) - 1, pipe);
    buffer[len] = '\0';

    pclose(pipe);
    return strdup(buffer);
}