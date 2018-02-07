#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#

# This is the main compiler
CC := g++
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/libstdlib.so

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
# LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
LIB := -L lib
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -shared -o $(TARGET) $(LIB)";
	@$(CC) $^ -shared -o $(TARGET) $(LIB)
	@echo "cp $(TARGET) ../Al/lib/"
	@cp $(TARGET) ../Al/lib/
	@echo "cp ./include/* ../Al/include/"
	@cp ./include/* ../Al/include/
	@echo "sudo cp $(TARGET) /usr/lib/"
	@sudo cp $(TARGET) /usr/lib/

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(INC) -fPIC -c $< -o $@";
	@$(CC) $(CFLAGS) $(INC) -fPIC -c $< -o $@

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)";
	@$(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes : some advanced syntax
ticket:
	$(CC) $(CFLAGS) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) spike/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
