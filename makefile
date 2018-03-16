OBJ = main.o sound.o
APPNAME = test.a
TAR = final.tar

$(APPNAME) : $(OBJ)	
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $<

#main.o : main.c
#	gcc -c main.c
#function.o : function.c
#	gcc -c function.c

clean :
	rm $(OBJ) $(APPNAME)

archive :
	tar cf $(TAR) *
