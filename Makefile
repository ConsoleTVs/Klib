CC = gcc
CCFLAGS = -O3
STRING_PATH = src/string
VECTOR_PATH = src/vector

all: $(STRING_PATH)/string.a $(VECTOR_PATH)/vector.a
	$(CC) $(CCFLAGS) src/main.c -o main $^

.PHONY: string
string: $(STRING_PATH)/string.a

.PHONY: vector
vector: $(VECTOR_PATH)/vector.a

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
