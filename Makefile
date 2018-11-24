# define compiler
CC	= gcc

#define compiler flags
CFLAGS	= -Wall -ggdb

# specify directories
VPATH = polynomial/calculations:polynomial/creation:polynomial:polynomial/visualization

.PHONY: clean mainProgramClean calculationsClean creationClean visualizationClean all

# default target - make everything
all: testMain
	./$<

# rule for main application
# compiles and starts the application
testMain: testMain.o calculations.o visualization.o creation.o
	${CC} ${CFLAGS} -o $@ $^

mainProgram: mainProgram.o calculations.o visualization.o creation.o
	${CC} ${CFLAGS} -o $@ $^

testMain.o: testMain.c testMain.h
	${CC} ${CFLAGS} -o $@ -c $<

mainProgram.o: mainProgram.c mainProgram.h
	${CC} ${CFLAGS} -o $@ -c $<

polynomial/calculations/calculations.o: calculations.c calculations.h
	${CC} ${CFLAGS} -o $@ -c $< 

polynomial/visualization/visualization.o: visualization.c visualization.h
	${CC} ${CFLAGS} -o $@ -c $< 

polynomial/creation/creation.o: creation.c creation.h
	${CC} ${CFLAGS} -o $@ -c $< 


	
# rule for cleaning up main application
# removes all executables and object files
clean:	mainProgramClean testMainClean calculationsClean creationClean visualizationClean
	

testMainClean:
	-rm testMain *.o

mainProgramClean:
	-rm mainProgram *.o

calculationsClean:
	cd polynomial/calculations
	-rm polynomial/calculations/*.o

creationClean:
	cd polynomial/creation
	-rm polynomial/creation/*.o

visualizationClean:
	cd polynomial/visualization
	-rm polynomial/visualization/*.o
