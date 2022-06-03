
OBJS = geometry.o geometryTest.o

CFLAGS = -g -Wall -std=c99

HDRS = geometry.h


geo.out: $(OBJS)

	gcc -o geo.out $(OBJS) -g

	
%.o: %.c $(HDRS)

	cc $(CFLAGS) -c $*.c