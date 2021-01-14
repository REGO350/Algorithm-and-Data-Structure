TARGET = buildheap
OBJS = main2.o array2.o heap2.o
CC = cc
CFLAGS = -Wall

.SUFFIXES: .c .o
${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} $^
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm -f *.o