
.SUFFIXES: .cxx .o .x .hxx .c .cpp
NAME1 = genSquare
NAME2 = distance
NAME3 = genRandomPerm
NAME4 = inversions

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x

CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) 


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS)

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3): 
	$(CO) -o $@ $(CXX3) $(FLAGS)

$(EXEC4): 
	$(CO) -o $@ $(CXX4) $(FLAGS)


.PHONY: distance
distance: all
	@echo "*The shortest distance*\n"
	@./$(EXEC1) 10000 > file.txt
	@./$(EXEC2) < file.txt

.PHONY: inversions
inversions: all
	@echo "*Number of inversions*\n"
	@./$(EXEC3) 10000 > file2.txt
	@./$(EXEC4) < file2.txt


.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.dat *.x *.txt core core* a.out; rm -rf ${LIB_DIR}
