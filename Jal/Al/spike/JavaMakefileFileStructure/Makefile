# Locate directories
class_d=bin
lib_d=lib
source_d=src
package_d="com/irc"

# Compilation stuff
JAVAC=javac
JFLAGS=-g -d $(class_d) -sourcepath $(source_d) -Xlint:all

classpath:=$(class_d):$(lib_d)/log4j-1.2.17.jar

# If there's already a CLASSPATH, put it on the front
ifneq ($(CLASSPATH),)
	classpath:= $(CLASSPATH):$(classpath)
endif

# Re-export the CLASSPATH.
export CLASSPATH:=$(classpath)

MATCH='.*[^(_TEST)]\.java'

ifdef TEST
	ifeq ($(TEST), all)
		MATCH='.*_TEST\.java'
	else
		MATCH='.*\/$(TEST)\/.*_TEST\.java'
	endif
endif

# Find all the source and convert them to class files
S_SERVER= $(shell find $(source_d)/com/irc/server -regex $(MATCH))
C_SERVER= $(patsubst src/%.java, bin/%.class, $(S_SERVER))
S_CLIENT= $(shell find $(source_d)/com/irc/client -regex $(MATCH))
C_CLIENT= $(patsubst src/%.java, bin/%.class, $(S_CLIENT))
S_UTILS= $(shell find $(source_d)/com/irc/utils -regex $(MATCH))
C_UTILS= $(patsubst src/%.java, bin/%.class, $(S_UTILS))

.SUFFIXES: .java .class
.PHONY: default server client utils clean all

default: classes

$(class_d)/%.class: $(source_d)/%.java
	@echo "JAVAC $<"
	@$(JAVAC) $(JFLAGS) $<

# utils server client 
classes:$(class_d) utils server client

server: $(C_SERVER) utils
client: $(C_CLIENT) utils
utils: $(C_UTILS)

all: classes

$(class_d):
	mkdir $(class_d)

clean:
	rm -rf $(class_d)/*
