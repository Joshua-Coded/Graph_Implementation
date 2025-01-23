CC = gcc
CFLAGS = -Wall -Wextra -I./include
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/bfs.c $(SRC_DIR)/main.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = bfs_traversal

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
