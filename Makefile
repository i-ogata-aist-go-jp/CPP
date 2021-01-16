tso:	tso.c
	 g++ -S -std=c++2a tso.c
	 as -o tso.o tso.s
	 g++ -pthread -o tso tso.o
	 ./tso
ars:	ars.c
	 g++ -S -std=c++2a ars.c
	 as -o ars.o ars.s
	 g++ -pthread -o ars ars.o
	 ./ars
tmp:	tmp.c
	 g++ -S -std=c++2a tmp.c
	 as -o tmp.o tmp.s
	 g++ -pthread -o tmp tmp.o
	 ./tmp
