TARGET = preheap
OBJS = main.o array.o heap.o
CC = cc
CFLAGS = -Wall

.SUFFIXES: .c .o
${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} $^
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm -f *.o