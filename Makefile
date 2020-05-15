COMPILER_ARGS = -lm
OBJDIR = bin

#Target : Dependency
#\tCommand to build the target

$(OBJDIR)/arcsin.o : arcsin.c 
	gcc arcsin.c $(COMPILER_ARGS) -o $(OBJDIR)/arcsin.o
