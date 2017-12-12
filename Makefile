.PHONY:all clean
BIN=hello
all:$(BIN)

%.o:%.c
	gcc -Wall -c $< -o $@

clean:
	rm -f *.o $(BIN)
