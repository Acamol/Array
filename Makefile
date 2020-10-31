TARGET = array_main

SRC_DIR = src
HEADS_DIR = include
SRCS = $(wildcard $(SRC_DIR)/*.c)
HEADS = $(wildcard $(HEADS_DIR)/*.h)
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

INCLUDES = -I$(HEADS_DIR)/
CFLAGS = -std=c99 -Wall -pedantic-errors $(INCLUDES) -MMD 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

.PHONY: test
test: $(TARGET)
	@./$(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)