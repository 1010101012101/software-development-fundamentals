/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 5
 * ShapesGood.h
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 1/12/2017
 */

#include <string>
#include <iostream>

using namespace std;

/* ////////////// */
/* Parent Classes */
/* ////////////// */

/**
 * Shape implementation, acts as a parent to many shapes.
 */
class Shape {
    public:
        Shape(int, int, string);
        virtual ~Shape();
        int getLength() const;
        int getWidth() const;
        string getOutlineColor() const;
        virtual void draw() = 0;
    private:
        string outlineColor;
        int length, width;
};

/**
 * FilledShape implementation, acts as a parent to many filled shape.
 */
class FilledShape {
    public:
        explicit FilledShape(string);
        virtual ~FilledShape();
        void fill();
    private:
        string fillColor;
};

/**
 * TextShape implementation, acts as parent to many text shapes.
 */
class TextShape {
    public:
        explicit TextShape(string);
        virtual ~TextShape();
        void drawText();
    private:
        string text;
};

/* ///////////////////// */
/* Custom Implementation */
/* ///////////////////// */

/**
 * Square implementation.
 * Subclass of Shape.
 */
class Square : public Shape {
    public:
        Square(int, int, string);
        void draw();
};

/**
 * FilledSquare implementation.
 * Subclass of Square and FilledShape.
 */
class FilledSquare : public Square, public FilledShape {
    public:
        FilledSquare(int, int, string, string);
        void draw();
};

/**
 * FilledTextSquare implementation.
 * Subclass of FilledSquare and TextShape.
 */
class FilledTextSquare : public FilledSquare, public TextShape {
    public:
        FilledTextSquare(int, int, string, string, string);
        void draw();
};

/**
 * Circle implementation.
 * Subclass of Shape.
 */
class Circle : public Shape {
    public:
        Circle (int, int, string);
        void draw();
};

/**
 * FilledCircle implementation.
 * Subclass of Circle and FilledShape.
 */
class FilledCircle : public Circle, public FilledShape {
    public:
        FilledCircle(int, int, string, string);
        void draw();
};

/**
 * Arc implementation.
 * Subclass of Shape.
 */
class Arc : public Shape {
    public:
        Arc(int, int, string);
        void draw();
};


