# simple_vm Makefile
# 

CC					= gcc
CXX					= g++
CPPFLAGS				= -fdiagnostics-show-location=every-line \
					-std=c++11 -Wall -Werror -pedantic \
					-Wfatal-errors -g -iquote include/
LD					= $(CXX)
LDFLAGS				= 
STRIP				= strip --strip-unneeded
RM					= rm
CTAGS				= ctags -R

# project directories
SRCDIR				= src
INCDIR				= include
OBJDIR				= build

# files, deduced by make every time it is run
SRCS				= ${wildcard $(SRCDIR)/*.cpp}
HDRS				= ${wildcard $(INCDIR)/*.hpp}
OBJS				= ${patsubst src/%.cpp,build/%.o,$(SRCS)}
EXE					= simple_vm


build/%.o: src/%.cpp
				$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(EXE)

$(EXE): $(OBJS)
				$(LD) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)
				$(CTAGS) $(SRCS) $(HDRS)

# all object files in OBJDIR are purged along with executable
clean:
				$(RM) -f $(EXE) ${wildcard $(OBJDIR)/*.o}

dist: $(EXE)
				$(STRIP) $(EXE)

