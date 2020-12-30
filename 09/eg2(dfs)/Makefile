TARGET = dfscan
OBJS = main2.o tree2.o parser2.o stack.o scandfs.o
CC = cc
CFLAGS = -Wall

.SUFFIXES: .c .o

${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} $^
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm -f *.o