CC = gcc
CCFLAGS = -O3
STRING_PATH = src/string

all: $(STRING_PATH)/string.a
	$(CC) $(CCFLAGS) src/main.c -o main $^

.PHONY: string
string: $(STRING_PATH)/string.a
$(STRING_PATH)/string.a: $(STRING_PATH)/string.o
	ar rcs $(STRING_PATH)/string.a $^
$(STRING_PATH)/string.c: $(STRING_PATH)/string.h
$(STRING_PATH)/string.o: $(STRING_PATH)/string.c $(STRING_PATH)/string.h
	$(CC) $(CCFLAGS) -c $< -o $(STRING_PATH)/string.o
