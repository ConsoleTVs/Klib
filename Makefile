CC = gcc
CCFLAGS = -O3
STRING_PATH = src/string
VECTOR_PATH = src/vector
UTILS_PATH = src/utils

all: $(STRING_PATH)/string.a $(VECTOR_PATH)/vector.a $(UTILS_PATH)/utils.a
	$(CC) $(CCFLAGS) src/main.c -o main $^

.PHONY: string
string: $(STRING_PATH)/string.a

.PHONY: vector
vector: $(VECTOR_PATH)/vector.a

.PHONY: utils
vector: $(UTILS_PATH)/utils.a

$(STRING_PATH)/string.a: $(STRING_PATH)/string.o
	ar rcs $(STRING_PATH)/string.a $^
$(STRING_PATH)/string.c: $(STRING_PATH)/string.h
$(STRING_PATH)/string.o: $(STRING_PATH)/string.c $(STRING_PATH)/string.h
	$(CC) $(CCFLAGS) -c $< -o $(STRING_PATH)/string.o

$(VECTOR_PATH)/vector.a: $(VECTOR_PATH)/vector.o
	ar rcs $(VECTOR_PATH)/vector.a $^
$(VECTOR_PATH)/vector.c: $(VECTOR_PATH)/vector.h
$(VECTOR_PATH)/vector.o: $(VECTOR_PATH)/vector.c $(VECTOR_PATH)/vector.h
	$(CC) $(CCFLAGS) -c $< -o $(VECTOR_PATH)/vector.o

$(UTILS_PATH)/utils.a: $(UTILS_PATH)/utils.o
	ar rcs $(UTILS_PATH)/utils.a $^
$(UTILS_PATH)/utils.c: $(UTILS_PATH)/utils.h
$(UTILS_PATH)/utils.o: $(UTILS_PATH)/utils.c $(UTILS_PATH)/utils.h
	$(CC) $(CCFLAGS) -c $< -o $(UTILS_PATH)/utils.o
