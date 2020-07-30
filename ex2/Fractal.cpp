#include "Fractal.h"

/**
 *  Creates a new Fractal with n construction steps and
 *  the matrix creation is of dimention: dimention*dimention
 * @param dim
 * @param steps The total numbre of steps in the fractal creation
 */
Fractal::Fractal(int dim, int steps) : baseFractalMatrixDimention(dim), step(steps)
{


}

/**
 * Getter to the the fractal matrix data(represented as bool vector)
 * @return  The Fractal Matrix data
 */
std::vector<bool> Fractal::getFractalMatrix()
{

    return fractalMatrix;
}

/**
 * Initalize the Fractal data structure
 */
void Fractal::initFractalData()
{

    int size = (int) pow(baseFractalMatrixDimention, step);
    fractalMatrix = std::vector<bool>(size * size);
    this->_initFractalDataRec(step, size, size);
}

/**
* Create a new Sierpinski Carpet Fractal
* @param steps  The total number of steps in the creation of the fractal(per section 4.1)
*/
SierpinskiCarpet::SierpinskiCarpet(int steps) : Fractal(3, steps)
{

    initFractalData();
}

/**
* Recursive helper method for the construction of the fractal data.
* Divide the the fractal matrix to 3x3 grid and on the  following sections:
* {(1,1),(1,2),(1,3),(2,1),(2,3),(3,1),(3,2),(3,3)}
* @param step The step of the Fractal
* @param x The x-cordinate on the Fractal matrix
* @param y The y-cordinate on the Fractal matrix
*/
void SierpinskiCarpet::_initFractalDataRec(int step, int x, int y)
{

    // base case:
    if (step == 0)
    {
        fractalMatrix.at(sqrt(fractalMatrix.size()) * (y - 1) + (x - 1)) = true;
        return;
    }

    // how row dimention of the next square matrix
    int dist = (int) pow(3, step - 1);

    // recurse into the bottom-right corner:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x, y);

    // recurse into the bottom-middle corner:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x - dist, y);

    // recurse into the bottom-left corner:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x - 2 * dist, y);

    // recurse into the right cordinate in the middle row:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x, y - dist);

    // recurse into the left cordinate in the middle row:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x - 2 * dist, y - dist);

    // recurse into the left-upper corner:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x, y - 2 * dist);

    // recurse into the left-middle corner:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x - dist, y - 2 * dist);

    // recurse into the right-upper corner:
    SierpinskiCarpet::_initFractalDataRec(step - 1, x - 2 * dist, y - 2 * dist);
}

SierpinskiCarpet::~SierpinskiCarpet() = default;

/**
* Create a new Sierpinski Triangle  Fractal
* @param steps The number of steps in the triangle  creation (per section 4.2)
*/
SierpinskiTriangle::SierpinskiTriangle(int steps) : Fractal(2, steps)
{

    initFractalData();
}

/**
* Recursive helper method for the construction of the fractal data.
* Divide the the fractal matrix to 2x2 grid and on the  following sections:
* {(1,1),(1,2),(2,1)}
* @param step The step in the build of the Fractal
* @param x The x-cordinate on the Fractal matrix
* @param y The y-cordinate on the Fractal matrix
*/
void SierpinskiTriangle::_initFractalDataRec(int step, int x, int y)
{

    // base case
    if (step == 0)
    {
        fractalMatrix.at(sqrt(fractalMatrix.size()) * (y - 1) + (x - 1)) = true;
        return;
    }

    // how row dimention of the next square matrix
    int dist = (int) pow(2, step - 1);

    // recurse into the left-upper corner:
    SierpinskiTriangle::_initFractalDataRec(step - 1, x - dist, y - dist);

    // recurse into the upper right corner:
    SierpinskiTriangle::_initFractalDataRec(step - 1, x, y - dist);

    // recurse into the  bottom left corner:
    SierpinskiTriangle::_initFractalDataRec(step - 1, x - dist, y);
}

SierpinskiTriangle::~SierpinskiTriangle() = default;

/**
* Create a new Vicsek Fractal
* @param steps The number of step in the build of the Fractal
**/
Vicsek::Vicsek(int step) : Fractal(3, step)
{
    initFractalData();
}

/**
  * Recursive helper method for the construction of the fractal data.
  * Divide the the fractal matrix to 3x3 grid and on the  following sections:
  * {(1,1),(1,3),(2,2),(3,1),(3,3)}
  * @param step The dimention of the Fractal
  * @param x The x-cordinate on the Fractal matrix
  * @param y The y-cordinate on the Fractal matrix
  */
void Vicsek::_initFractalDataRec(int step, int x, int y)
{

    // base case
    if (step == 0)
    {
        fractalMatrix.at(sqrt(fractalMatrix.size()) * (y - 1) + (x - 1)) = true;
        return;
    }

    // how row dimention of the next square matrix
    int dist = (int) pow(3, step - 1);

    // recurse into the bottom right-most square:
    Vicsek::_initFractalDataRec(step - 1, x, y);

    // recurse into the bottom left-most square:
    Vicsek::_initFractalDataRec(step - 1, x - 2 * dist, y);

    // recurse into the middle-most square:
    Vicsek::_initFractalDataRec(step - 1, x - dist, y - dist);

    // recurse into the the upper right-most corner:
    Vicsek::_initFractalDataRec(step - 1, x, y - 2 * dist);

    // recurse into the the leftmost-upper corner:
    Vicsek::_initFractalDataRec(step - 1, x - 2 * dist, y - 2 * dist);

}

Vicsek::~Vicsek() = default;

/**
* Create a new fractal type
* @param type  the type of fractal to create(defined in the exe. description)
* @param steps
* @return A new fractal per the type gicen
*/
Fractal *FractalFactory::createFractal(int type, int steps)
{

    if (type == TYPE_SIERPINSKI_CARPET)
    {
        return new class SierpinskiCarpet(steps);
    }
    else if (type == TYPE_SIERPINSKI_TRIANGLE)
    {
        return new class SierpinskiTriangle(steps);
    }
    else if (type == TYPE_VICSEK_FRACTAL)
    {
        return new class Vicsek(steps);
    }
    else
    {
        return nullptr;
    }
}

