# Clipboard History Logger in C

## Project Overview

This project logs the clipboard content on Linux, macOS, and Windows by periodically checking the clipboard and saving
changes to a text file. The implementation is in C with platform-specific modules.

---

## File Structure

/include\
└── clipboard.h # Common clipboard interface\
/src\
├── clipboard_linux.c # Linux implementation (xclip)\
├── clipboard_mac.c # macOS implementation (pbpaste)\
├── clipboard_windows.c # Windows implementation (Win32 API)\
└── main.c # OS-agnostic main program\
## Build script with OS selection


---

## Core Function

```c
char* get_clipboard_text();
Returns a dynamically allocated string with current clipboard contents

Each platform has its own implementation:

Linux: Uses xclip -selection clipboard -o

macOS: Uses pbpaste

Windows: Uses Windows Clipboard API
```
## Main.c Logic
Opens (or creates) out/history_clipboard.txt file

Retrieves clipboard text with get_clipboard_text()

Compares it with the last saved clipboard content

If new content, appends it to the file and flushes output

Runs in an infinite loop with a sleep delay (e.g., 5 seconds)

Frees dynamically allocated strings properly


## Building
Use the provided Makefile with the OS variable to compile for your platform:

```bash
Copier
Modifier
make OS=LINUX
make OS=MAC
make OS=WINDOWS
```

## Important Notes
Make sure the out directory exists before running (e.g., mkdir out)

Include <stdlib.h> in your C files for malloc/free

Use FILE* pointers correctly (FILE* file = fopen(...))

Test on the target OS or using virtual machines

Consider handling signals like SIGINT for clean termination

## Next Steps
Finalize and test clipboard implementations for each OS

Enhance error handling and buffer management

Publish project on GitHub with documentation

Optionally add a CLI or GUI frontend for easier use