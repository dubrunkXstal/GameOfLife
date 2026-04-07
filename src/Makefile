CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
LDFLAGS = -lm -lncurses

BUILD_DIR = ../build
TARGET = $(BUILD_DIR)/Game

SRCS = game_of_life.c cell.c grid.c keyboard_capture.c rendering.c


all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all

.PHONY: all clean rebuild