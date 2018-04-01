CC            = g++
LFLAGS        = -m64
CFLAGS        = -m64 -pipe -O2 -W -D_REENTRANT $(DEFINES) -fPIC
LIBS          = -L/usr/lib/x86_64-linux-gnu/ -lm -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB
OBJECTS       = main.o
TARGET        = draw

INCPATH         = -I. -I/usr/include/x86_64-linux-gnu -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/lib/qt/mkspecs/linux-g++


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<  $(INCPATH)

$(TARGET):  $(OBJECTS)  
	$(CC) $(LFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean: 
	rm -f *.o $(TARGET)
