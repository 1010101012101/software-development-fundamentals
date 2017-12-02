/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 5
 * ShapesGood.h
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 1/12/2017
 */

#include "ShapesGood_15rws.h"

using namespace std;

/* ///////////////////// */
/* Shape Implementation */
/* /////////////////// */

/**
 * Constructor for Shape class.
 * @param len The length of the shape.
 * @param wid The width of the shape.
 * @param outline The outline color. *** change
 */
Shape::Shape(int len, int wid, string outlineColor) : length(len), width(wid), outlineColor(outlineColor) {}

/**
 * Default empty deconstructor of the Shape class.
 */
Shape::~Shape() = default;

/**
 * Getter for shape length attribute.
 * @return The length of the shape.
 */
int Shape::getLength() const { return length; }

/**
 * Getter for the shape width attribute.
 * @return The width of the shape.
 */
int Shape::getWidth() const { return width; }

/**
 * Getter for the shape color attribute.
 * @return The color of the shape.
 */
string Shape::getOutlineColor() const { return outlineColor; }

/* //////////////////////////// */
/* Filled Shape Implementation */
/* ////////////////////////// */

/**
 * Constructor for the FilledShape class.
 * @param color The fill color for the shape.
 */
FilledShape::FilledShape(string fillColor) : fillColor(fillColor) {}

/**
 * Default empty deconstructor of the FilledShape class.
 */
FilledShape::~FilledShape() = default;

/**
 * Fills a shape with the color.
 */
void FilledShape::fill() {
    cout << " With " + fillColor + " fill.";
}

/* ////////////////////////// */
/* Text Shape Implementation */
/* //////////////////////// */

/**
 * Constructor fo the text shape class.
 * @param text The text o be put in the shape.
 */
TextShape::TextShape(string text) : text(text) {}

/**
 * Default empty deconstructor of the TextShape class.
 */
TextShape::~TextShape() = default;

/**
 * Draws text.
 */
void TextShape::drawText() {
    cout << " Containing the text: \"" << text << "\".";
}

/* ////////////////////// */
/* Square Implementation */
/* //////////////////// */

/**
 * Constructor for the square class.
 * @param len The length of the square.
 * @param wid The width of the square.
 * @param color The color of the square.
 */
Square::Square(int len, int wid, string outlineColor) : Shape(len, wid, outlineColor) {}

/**
 * Square's drawing implementation.
 */
void Square::draw() {
    cout << "\nDrawing a " + getOutlineColor() + " square.";
}

/* //////////////////////////// */
/* Filled Square Implementation */
/* //////////////////////////// */

/**
 * Constructor for the FilledSquare class.
 * @param len The length of the filled square.
 * @param wid The width of the filled square.
 * @param outlineColor The outline color for the square.
 * @param fillColor The fill color for the square.
 */
FilledSquare::FilledSquare(int len, int wid, string outlineColor, string fillColor) : Square(len, wid, outlineColor), FilledShape(fillColor) {}

/**
 * Filled square drawing implemetation.
 */
void FilledSquare::draw() {
    Square::draw();
    FilledShape::fill();
}

/* ////////////////////////////////// */
/* Filled Text Square Implementation */
/* //////////////////////////////// */

/**
 * Constructor for the FilledTextSquare class.
 * @param len The length of the filled text square.
 * @param wid The width of the filled text square.
 * @param outlineColor The outline color of the filled text square.
 * @param fillColor The fill color of the filled text square.
 * @param text The text to be in the filled text square.
 */
FilledTextSquare::FilledTextSquare(int len, int wid, string outlineColor, string fillColor, string text) : FilledSquare(len, wid, outlineColor, fillColor), TextShape(text) {}

/**
 * Filled text square drawing implementation.
 */
void FilledTextSquare::draw() {
    FilledSquare::draw();
    TextShape::drawText();
}

/* ////////////////////// */
/* Circle Implementation */
/* //////////////////// */

/**
 * Constructor for the Circle class.
 * @param len The length of a circle.
 * @param wid The width of the circle.
 * @param outlineColor The outline color of the circle.
 */
Circle::Circle(int len, int wid, string outlineColor) : Shape(len, wid, outlineColor) {}

/**
 * Circle drawing implementation.
 */
void Circle::draw() {
    cout << "\nDrawing a " + getOutlineColor() + " circle.";
}

/* //////////////////////////// */
/* Filled Circle Implementation */
/* //////////////////////////// */

/**
 * Constructor of the FilledCircle class.
 * @param len The length of the circle.
 * @param wid The width of the circle.
 * @param outlineColor The outline color of the circle.
 * @param fillColor The fill color of the circle.
 */
FilledCircle::FilledCircle(int len, int wid, string outlineColor, string fillColor) : Circle(len, wid, outlineColor), FilledShape(fillColor) {}

/**
 * Filled circle drawing implementations.
 */
void FilledCircle::draw() {
    Circle::draw();
    FilledShape::fill();
}

/* ////////////////////// */
/* Arc Implementation */
/* //////////////////// */

/**
 * Constructor for the Arc class.
 * @param len The length of the arc.
 * @param wid The width of the arc.
 * @param outlineColor The outline color for the arc.
 */
Arc::Arc(int len, int wid, string outlineColor) : Shape(len, wid, outlineColor) {}

/**
 * Arc drawing implementation.
 */
void Arc::draw() {
    cout << "\nDrawing a " + getOutlineColor() + " arc.";
}

