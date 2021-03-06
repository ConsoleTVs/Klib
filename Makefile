CC = gcc
CCFLAGS = -O3 -std=c99 -Wall -Wextra
STRING_PATH = src/string
UTILS_PATH = src/utils

all: $(STRING_PATH)/string.a $(UTILS_PATH)/utils.a
	$(CC) $(CCFLAGS) src/main.c -o main $^

.PHONY: string
string: $(STRING_PATH)/string.a

.PHONY: utils
utils: $(UTILS_PATH)/utils.a

$(STRING_PATH)/string.a: $(STRING_PATH)/string.o
	ar rcs $(STRING_PATH)/string.a $^
$(STRING_PATH)/string.c: $(STRING_PATH)/string.h
$(STRING_PATH)/string.o: $(STRING_PATH)/string.c $(STRING_PATH)/string.h
	$(CC) $(CCFLAGS) -c $< -o $(STRING_PATH)/string.o

$(UTILS_PATH)/utils.a: $(UTILS_PATH)/utils.o
	ar rcs $(UTILS_PATH)/utils.a $^
$(UTILS_PATH)/utils.c: $(UTILS_PATH)/utils.h
$(UTILS_PATH)/utils.o: $(UTILS_PATH)/utils.c $(UTILS_PATH)/utils.h
	$(CC) $(CCFLAGS) -c $< -o $(UTILS_PATH)/utils.o
