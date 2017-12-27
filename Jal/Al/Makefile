# Locate directories
class_d=bin
lib_d=lib
source_d=src
package_d=Chapter2_Sorting

# distinguish between windows and liunx; you can also distinguish by $OSTYPE : liunx-gnu or cygwin
ifneq ($(findstring :,$(JAVA_HOME)),)
	delimiter:=;
else
	delimiter:=:
endif

# Compilation stuff
JAVAC=javac
JFLAGS=-g -d $(class_d) -sourcepath $(source_d) -Xlint:all

# add lib method :$(lib_d)/log4j-1.2.12.jar
classpath:=$(class_d)$(delimiter)$(lib_d)/StdLib.jar

# If there's already a CLASSPATH, put it on the front
ifneq ($(CLASSPATH),)
	classpath:= $(CLASSPATH)$(delimiter)$(classpath)
endif

# Re-export the CLASSPATH.
export CLASSPATH:=$(classpath)

MATCH='.*\.java'

# Find all the source and convert them to class files
S_Alg = $(shell find $(source_d)/ -regex $(MATCH))
C_Alg = $(patsubst src/%.java, bin/%.class, $(S_Alg))

.SUFFIXES: .java .class
# .PHONY: default server client utils clean init all
.PHONY: default clean

default: classes

$(class_d)/%.class: $(source_d)/%.java
	@echo "JAVAC $<"
	@$(JAVAC) $(JFLAGS) $<

# classes: $(class_d) utils server client
classes: $(class_d) C_Alg

C_Alg: $(C_Alg)

$(class_d):
	mkdir $(class_d)

# Tests
tester:
	@$(JAVAC) $(JFLAGS) test/Tester.java

# Spike : some advanced syntax
ticket:
	@$(JAVAC) $(JFLAGS) spike/Ticket.java

clean:
	rm -rf $(class_d)/*
