CXX=g++
LFLAGS        = -m64
CXXFLAGS      = -m64 -O2 -W -Wsign-compare $(DEFINES) -fPIC -std=c++11
BASEINCPATH   = /usr/include/x86_64-linux-gnu
INCPATH       = -I. -I$(BASEINCPATH) -I/usr/lib/qt/mkspecs/linux-g++ -I$(BASEINCPATH)/qt5 -I$(BASEINCPATH)/qt5/QtCore -I$(BASEINCPATH)/qt5/QtWidgets
LIBS          = -L/usr/lib/x86_64-linux-gnu -lm -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -D_REENTRANT
OBJECTS       = main.o
TARGET        = draw

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) $(INCPATH)

$(TARGET):  $(OBJECTS)  
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean

clean: 
	rm -f *.o $(TARGET)

