#include <stdio>
#include <math>
#include <QPainter>
#include <QtGui/QGuiApplication>
#include <QtCore/QDir>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>

/*! \mainpage DrawBetter - Always Draw Better
 *
 * \section intro_sec About
 *
 * This is a doxygen documentation of software DrawBetter.
 */

using namespace std;

/*!
* This class will be used to interact with the 'QPainter' and 'Qt Canvas 3D' library to
* provide the user a drawing pad for input of required 2D projections or 3D model.
*/
class drawingPad {
	public:

	/**
	* this method creates a drawing pad utilizing the graphics user iterface APIs
	* of Qt libraries.
	*/
	void drawingpad(){

	}

	protected:

	/**
	* this method manipulates the 2D projections explicitly
	*/
	void 2Dmanipulation() {

	}

	/**
	* this method manipulates the 3D model explicitly
	*/
	void 3Dmanipulation() {

	}


};


/*!
* This class deals with all the input-output (from files). Needless to say that
* the object of this class will have a direct relation with drawing pad.
*/
class io {

};

/*!
* This is the main class. 'DrawBetter' is the name of the software.
*/

class drawBetter {

	protected:
	/**
	* Algorithm implementation for converting given 2D projections
	* into a 3D model.
	*/
	void algorithm2Dto3D(){

	}


	/**
	* Algorithm implementation for converting given 3D model 
	* into a 2D projection on the given plane.
	*/
	void algorithm3Dto2D(){

	}
};