CC=gcc
OBJS= funcs.o datatypes.o menusearchfunc.o restaurant_login.o user_login.o try.o
EXECS= sastaswiggy

sastaswiggy: funcs.o datatypes.o menusearchfunc.o restaurant_login.o user_login.o try.o
	gcc funcs.o datatypes.o menusearchfunc.o restaurant_login.o user_login.o try.o -lm -o sastaswiggy

funcs.o: funcs.c all.h datatypes.c
	gcc -c funcs.c all.h datatypes.c num_checker.c

datatypes.o: datatypes.c all.h datatypes.c
	gcc -c datatypes.c all.h datatypes.c num_checker.c

menusearchfunc.o: menusearchfunc.c all.h datatypes.c
	gcc -c menusearchfunc.c all.h datatypes.c num_checker.c

restaurant_login.o: restaurant_login.c all.h datatypes.c
	gcc -c restaurant_login.c all.h datatypes.c num_checker.c

user_login.o: user_login.c all.h datatypes.c
	gcc -c user_login.c all.h datatypes.c  num_checker.c

user_try.o: try.c all.h datatypes.c
	gcc -c try.c -lm all.h datatypes.c num_checker.c

clean: 
	rm -f $(OBJS) $(EXECS)

