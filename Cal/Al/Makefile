#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#

# This is the main compiler
CC := g++
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/runner

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -std=c++11 # -Wall
# LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
LIB := -L lib -l:libstdlib.so
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)";
	@$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(INC) -c $< -o $@";
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)";
	@$(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes : some advanced syntax
ticket:
# $(filter-out $(BUILDDIR)/main.o, $(OBJECTS))
	$(CC) $(CFLAGS)  spike/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
