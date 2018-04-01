CC            = g++
LFLAGS        = -m64
CFLAGS        = -m64 -pipe -O2 -W -D_REENTRANT $(DEFINES) -fPIC
LIBS          = -L/usr/lib/x86_64-linux-gnu -lm -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB
OBJECTS       = main.o
TARGET        = deCAD

INCPATH         = -I. -I/usr/include/x86_64-linux-gnu -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/lib/qt/mkspecs/linux-g++


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<  $(INCPATH)

$(TARGET):  $(OBJECTS)  
	$(CC) $(LFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean: 
	rm -f *.o $(TARGET)


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
