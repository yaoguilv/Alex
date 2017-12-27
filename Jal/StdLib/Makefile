# Locate directories
class_d=bin
lib_d=lib
source_d=src
package_d=StdLib
TARGET := $(lib_d)/StdLib.jar

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
classpath:=$(class_d)

# If there's already a CLASSPATH, put it on the front
ifneq ($(CLASSPATH),)
	classpath:= $(CLASSPATH)$(delimiter)$(classpath)
endif

# Re-export the CLASSPATH.
export CLASSPATH:=$(classpath)

# MATCH='.*[^(_TEST)]\.java'
MATCH='.*\.java'

# Find all the source and convert them to class files
S_StdLib = $(shell find $(source_d)/StdLib/ -regex $(MATCH))
C_StdLib = $(patsubst src/%.java, bin/%.class, $(S_StdLib))

.SUFFIXES: .java .class

# .PHONY: default server client utils clean init all
.PHONY: default clean

default: $(TARGET)

$(class_d)/%.class: $(source_d)/%.java
	@echo "JAVAC $<"
	@$(JAVAC) $(JFLAGS) $<

$(TARGET): classes
	@echo "jar cvf $(TARGET) -C $(class_d) $(package_d)/"
	@jar cvf $(TARGET) -C $(class_d) $(package_d)/

classes: $(class_d) $(package_d)

$(package_d): $(C_StdLib)

$(class_d):
	mkdir $(class_d)

# Tests
tester:
	@$(JAVAC) -d bin -classpath "$(class_d)$(delimiter)$(TARGET)" test/Tester.java

clean:
	rm -rf $(class_d)/*
