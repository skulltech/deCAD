CC            = /usr/bin/g++
LFLAGS        = -m64
CFLAGS        = -m64 -O2 -Wsign-compare -W $(DEFINES) -fPIC -std=c++11
LIBS          = -L/usr/lib/x86_64-linux-gnu -lm -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -D_REENTRANT
HEADERS       = $(shell find $(SRCPATH) -type f -name '*.h')
SOURCES       = $(shell find $(SRCPATH) -type f -name '*.cpp')
OBJECTS       = $(patsubst $(SRCPATH)/%.cpp, $(BINPATH)/%.o, $(SOURCES))
TARGET        = deCAD
BASEINCPATH   = /usr/include/x86_64-linux-gnu
INCPATH       = -I. -I$(BASEINCPATH) -I/usr/lib/qt/mkspecs/linux-g++ -I$(BASEINCPATH)/qt5 -I$(BASEINCPATH)/qt5/QtCore -I$(BASEINCPATH)/qt5/QtWidgets
SRCPATH       = ./src
BINPATH       = ./bin


$(BINPATH)/%.o: $(SRCPATH)/%.cpp
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< -o $@ $(INCPATH)

$(TARGET): $(OBJECTS)  
	$(CC) $(LFLAGS) -o $(BINPATH)/$@ $^ $(LIBS)


# .PHONY: bin clean

all: bin $(TARGET)

bin:
	mkdir $(BINPATH)

clean: 
	rm -rf $(BINPATH)



# CC          = /usr/bin/g++
# MOC         = moc-qt5
# CFLAGS      = -Wall -pedantic -std=c++0x -D_REENTRANT \
#                             -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
# TARGET        = yarott
# INCPATH         = -I. -I/usr/include -I/usr/include/qt -I/usr/include/qt/QtGui \
#                             -I/usr/include/qt/QtCore -I/usr/lib/qt/mkspecs/linux-g++
# LDFLAGS     = -L/usr/lib -lsqlite3 -lQt5Gui -lQt5Core -lGL -lpthread
# SRCPATH         = ./src
# BINPATH         = ./bin

# DEFINES         = $(shell find $(SRCPATH) -type f -name '*.h')
# SOURCES         = $(shell find $(SRCPATH) -type f -name '*.cpp')
# OBJECTS         := $(patsubst $(SRCPATH)/%.cpp, $(BINPATH)/%.o, $(SOURCES))
# MOC_SOURCES := $(patsubst $(SRCPATH)/%.cpp, $(SRCPATH)/moc_%.cpp, $(SOURCES))
# MOC_OBJECTS := $(patsubst $(BINPATH)/%.o, $(BINPATH)/moc_%.o, $(OBJECTS))

# SOURCES += $(MOC_SOURCES)
# OBJECTS += $(MOC_OBJECTS)

# all: bin $(TARGET)

# $(TARGET): $(OBJECTS)
#     $(CC) $(CFLAGS) -o $(BINPATH)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(INCPATH)

# $(BINPATH)/%.o: $(SRCPATH)/%.cpp
#     @mkdir -p "$(@D)"
#     $(CC) $(CFLAGS) -c $< -o $@

# $(SRCPATH)/moc_%.cpp: $(SRCPATH)/%.h
#     $(MOC) $(DEFINES) $(INCPATH) $< -o $@

# # Generate cc from h via Qt's Meta Object Compiler
# # $(SRCPATH)/%.moc.cc: $(SRCPATH)/%.h
# #   $(MOC) $(INCPATH) $< -o $@

# # Create bin folder
# bin:
#     mkdir $(BINPATH)

# # Remove bin folder
# clean:
#     rm -r $(BINPATH)
