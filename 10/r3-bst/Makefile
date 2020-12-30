TARGET = searchBST
OBJS = main3.o search2.o tree.o parser.o
CC = cc
CFLAGS = -Wall

.SUFFIXES: .c .o

${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} $^
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm -f *.o