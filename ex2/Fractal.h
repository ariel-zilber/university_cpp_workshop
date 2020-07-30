#ifndef EX2_CPP_FRACTAL_H
#define EX2_CPP_FRACTAL_H

#include <cmath>
#include <iostream>
#include <vector>
#include <string>

/**
* @def TYPE_SIERPINSKI_CARPET 1
* @brief Represents a Sierpinski carpet fractal type
*/
#define TYPE_SIERPINSKI_CARPET 1

/**
* @def TYPE_SIERPINSKI_TRIANGLE 2
* @brief Represents a Sierpinski triangle fractal type
*/
#define TYPE_SIERPINSKI_TRIANGLE 2

/**
* @def TYPE_VICSEK_FRACTAL 3
* @brief Represents a vicsek fractal type
*/
#define TYPE_VICSEK_FRACTAL 3


/**
* A general Fractal type represented as a boolean matrix
*
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class Fractal
{
public:

    // Constructors:

    /**
     *  Creates a new Fractal with n construction steps and
     *  the matrix creation is of dimention: dimention*dimention
     * @param dimention
     * @param steps The total numbre of steps in the fractal creation
     */
    Fractal(int dim, int steps);


    /**
     * Destructor
     */
    virtual  ~Fractal() = default;

    // Methods:

    /**
     * Getter to the the fractal matrix data(represented as bool vector)
     * @return  The Fractal Matrix data
     */
    std::vector<bool> getFractalMatrix();

protected:

    // Methods:
    /**
     * Initalize the Fractal data structure
     */
    void initFractalData();

    // Data members:
    std::vector<bool> fractalMatrix;
    const int baseFractalMatrixDimention;
    const int step;


private:
    // Methods:

    /**
       * Recursive helper method for the construction of the fractal data.
       * Divide the matrix into baseFractalMatrixDimentionxbaseFractalMatrixDimention sections
       * and recurse on the approiate section
       * @param step The step in the fractal build
       * @param x The x-cordinate on the Fractal matrix
       * @param y The y-cordinate on the Fractal matrix
       */
    virtual void _initFractalDataRec(int step, int x, int y) = 0;

};

/**
* A Class representing a  Sierpinski Carpet  Fractal type
*
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class SierpinskiCarpet : public Fractal
{
public:

    // Constructors:


    /**
     * Create a new Sierpinski Carpet Fractal
     * @param steps  The total number of steps in the creation of the fractal(per section 4.1)
     */
    explicit SierpinskiCarpet(int steps);

    ~SierpinskiCarpet() override;

private:
    // Methods:


    /**
   * Recursive helper method for the construction of the fractal data.
   * Divide the the fractal matrix to 3x3 grid and on the  following sections:
   * {(1,1),(1,2),(1,3),(2,1),(2,3),(3,1),(3,2),(3,3)}
   * @param step The step of the Fractal
   * @param x The x-cordinate on the Fractal matrix
   * @param y The y-cordinate on the Fractal matrix
   */
    void _initFractalDataRec(int step, int x, int y) override;


};

/**
* A Class representing a  Sierpinski Triangle  Fractal type
*
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class SierpinskiTriangle : public Fractal
{
public:

    // Constructors:

    /**
    * Create a new Sierpinski Triangle  Fractal
    * @param steps  The number of steps in the triangle  creation (per section 4.2)
    */
    explicit SierpinskiTriangle(int steps);

    ~SierpinskiTriangle() override;

private:

    /**
  * Recursive helper method for the construction of the fractal data.
  * Divide the the fractal matrix to 2x2 grid and on the  following sections:
  * {(1,1),(1,2),(2,1)}
  * @param step The step in the build of the Fractal
  * @param x The x-cordinate on the Fractal matrix
  * @param y The y-cordinate on the Fractal matrix
  */
    void _initFractalDataRec(int step, int x, int y) override;

};

/**
* A Class representing a  Vicsek Fractal type
*
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class Vicsek : public Fractal
{
public:
    // Constructors:

    /**
    * Create a new Vicsek Fractal
    * @param steps The number of step in the build of the Fractal
    **/
    explicit Vicsek(int steps);

    ~Vicsek() override;

private:
    // Methods:

    /**
    * Recursive helper method for the construction of the fractal data.
    * Divide the the fractal matrix to 3x3 grid and on the  following sections:
    * {(1,1),(1,3),(2,2),(3,1),(3,3)}
    * @param step The dimention of the Fractal
    * @param x The x-cordinate on the Fractal matrix
    * @param y The y-cordinate on the Fractal matrix
    */
    void _initFractalDataRec(int step, int x, int y) override;

};

/**
* A factory class for Fractals
*
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class FractalFactory
{
public:

    // Constructors:
    FractalFactory() = default;

    // Methods:

    /**
     * Create a new fractal type
     * @param type  the type of fractal to create(defined in the exe. description)
     * @param steps
     * @return A new fractal per the type gicen
     */
    static Fractal *createFractal(int type, int steps);
};


#endif //EX2_CPP_FRACTAL_H
