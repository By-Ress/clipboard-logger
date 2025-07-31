# === General configuration ===
INCLUDE_DIR = -Iinclude
SRC_DIR = src
MAIN_SRC = $(SRC_DIR)/main.c

# === Default variable ===
EXEC = clipboard_logger
CLIP_SRC =
FLAGS = -Wall -Wextra

# === OS detection (do make OS=...) ===
ifeq ($(OS),LINUX)
    CLIP_SRC = $(SRC_DIR)/clipboard_linux.c
endif

ifeq ($(OS),MAC)
    CLIP_SRC = $(SRC_DIR)/clipboard_mac.c
    FLAGS = -framework Foundation -framework AppKit
endif

ifeq ($(OS),WINDOWS)
    CLIP_SRC = $(SRC_DIR)/clipboard_windows.c
    EXEC = clipboard_logger.exe
endif

# === Principal Rules ===
all:
	@echo "Compiling for $(OS)..."
	@gcc $(MAIN_SRC) $(CLIP_SRC) $(INCLUDE_DIR) $(FLAGS) -o $(EXEC)
	@echo "Build done → $(EXEC)"

# === Clean ===
clean:
	@rm -f clipboard_logger clipboard_logger.exe
	@rm -rf out
	@echo "Cleaned."
