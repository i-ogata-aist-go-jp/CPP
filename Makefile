CC = g++ 
OPTS = -O2 -std=c++2a
ARS = ars
SRC = ars.c

$(ARS):	$(SRC)
	 $(CC) $(OPTS) -pthread -o $(ARS) $(SRC)

ordering : ordering.c
	 $(CC) -c -S -masm=intel ordering.c

.PHONY: clean
clean:
	rm $(ARS) reorder
