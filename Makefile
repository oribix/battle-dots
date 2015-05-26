SRC = ./src/
OUT = ./bin/

all: bdots
	
bdots: bin
	gcc $(SRC)bdots.c -o $(OUT)bdots

bin:
	mkdir -p ./bin

clean:
	rm -rf bin/
