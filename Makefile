CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/nameless

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g
LIB := -L/usr/lib/x86_64-linux-gnu -lSDL -lSDLmain -lSDL_image -lSDL_mixer -lSDL_ttf
INC := -I include -I/usr/include/SDL

$(TARGET): $(OBJECTS)
	mkdir -p bin/res
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)
	@echo " Copying assets..."
	cp assets/* bin/res/ -r

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

run:
	cd bin
	./nameless

.PHONY: clean
