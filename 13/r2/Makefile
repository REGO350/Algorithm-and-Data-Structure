TARGET = heapsortT
OBJS = main3T.o array3.o heap3.o data.o clock.o
CC = cc
CFLAGS = -Wall

.SUFFIXES: .c .o

${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} $^

.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f *.o
