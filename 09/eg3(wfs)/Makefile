TARGET = wfscan
OBJS = main3.o scanwfs.o queue.o tree.o parser.o
CC = cc
CFLAGS = -Wall

.SUFFIXES: .c .o

${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} $^
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm -f *.o