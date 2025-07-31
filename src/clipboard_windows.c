//
// Created by Baris Ortanca on 31/07/2025.
//

#include "clipboard.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

char* get_clipboard_text() {
    if (!OpenClipboard(NULL)) return NULL;

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == NULL) {
        CloseClipboard();
        return NULL;
    }

    char* clipboardData = (char*)GlobalLock(hData);
    if (!clipboardData) {
        CloseClipboard();
        return NULL;
    }

    char* result = strdup(clipboardData);

    GlobalUnlock(hData);
    CloseClipboard();

    return result;
}
