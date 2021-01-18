ARS = ars
CC = g++ 
OPTS = -std=c++2a
SRC = ars.c

$(ARS):	$(SRC)
	 $(CC) $(OPTS) -pthread -o $(ARS) $(SRC)

.PHONY: clean
clean:
	rm $(ARS)
