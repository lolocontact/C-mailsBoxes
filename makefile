c=gcc
libs=-Wall -Wextra -lpthread

all: lib bal3_c bal3_s
	
bal3_s: bal3_s.c lib.h lib.o
	@$(c) -o bal3_s.o -c bal3_s.c $(libs)
	@$(c) -o bal3_s lib.o bal3_s.o $(libs)
	
bal3_c: lib.o lib.h bal3_c.c
	@$(c) -o bal3_c.o -c bal3_c.c $(libs)
	@$(c) -o bal3_c lib.o bal3_c.o $(libs)

lib : lib.c lib.h
	@$(c) -o lib.o -c lib.c $(libs)
	
clean :
	rm -f lib.o bal3_s.o bal3_c.o bal3_s bal3_c
