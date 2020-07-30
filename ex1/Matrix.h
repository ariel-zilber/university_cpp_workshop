#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

/**
 *  Represents the  matrix and vectors that are required for the program to run.
 *  The data is of float type
 *  Made per section 4.1
 *  @author - Ariel Zilbershtein
 *  @CS login - arikzil
 *
 * */
 class Matrix
{
private:
    float *matrixData;
    MatrixDims dims;
public:

    /**
     *Constructs Matrix rows × cols
     * Inits all elements to 0
     * @param rows
     * @param cols
      */
    Matrix(int rows, int cols);

    /**
     * Constructs Matrix 1 × 1
     * Inits all elements to 0
     *
     */
    Matrix();

    /**
     * Constructs a matrix form another matrix
     * @param m
     *
     */
    Matrix(const Matrix &m);

    /**
     * Destructor
     */
    ~Matrix();

    /**
     * Returns the number of rows
     * @return number of rows
     */
    int getRows();

    /**
     * Returns the number of cols
     * @return number of cols
     */
    int getCols();

    /**
       * Returns the number of rows
       * @return number of rows
     */
    int getRows() const;

    /**
     * Returns the number of cols
    * @return number of cols
    */
    int getCols() const;

    /**
     *
     * Transforms a matrix into a coloumn vector
     * Supports function calling concatenation
     * i.e.(1) Matrix m(5,4);... m.vectorize()
     * m.getCols() == 1
     * m.getRows() == 20
     * i.e.(2) Matrix m(5,4), b(20, 1); then
     * m.vectorize() + b should be a valid expression
     *
     */
    Matrix vectorize();

    /**
     *
     * Prints matrix elements, no return value.
     * prints space after each element (incl. last element in the row)
     * prints newline after each row (incl. last row)
     */
    void plainPrint();

    /**
    *
    * Prints matrix elements, no return value.
    * prints space after each element (incl. last element in the row)
    * prints newline after each row (incl. last row)
    */
    void plainPrint() const;

    /**
     * Assigment of matrix.
     * i.e Matrix a, b;
     *...
     *a = b;
     */
    Matrix &operator=(Matrix const &obj);


    /**
    * Matrix addition
    * Matrix a,b;->a+b;
    */
    Matrix operator+(Matrix const &obj) const;

    /**
    * Matrix addition
    * Matrix a,b;->a+b;
    *
    */
    Matrix operator+(Matrix const &obj);

    /**
    * Matrix addition
    * Matrix a,b;->a+=b;
    *
    */
    Matrix operator+=(Matrix const &obj);

    /**
     * Matrix multiplications
     * Matrix a,b;->a*b;
     *
     */
    Matrix operator*(Matrix const &obj);

    /**
    * Matrix multiplications
    * Matrix a,b;->a*b;
    *
    */
    Matrix operator*(Matrix const &obj) const;

    /**
    * Matrix multiplication by a scalar
    * Matrix a,Scalar b;->a*b;
    *
    */
    Matrix operator*(float scalar);

    /**
    * Matrix multiplication by a scalar
    * Matrix a,Scalar b;->a*b;
    *
    */
    Matrix operator*(float scalar) const;


    /**
    * Matrix multiplication by a scalar
    * Matrix a,Scalar b;->a*b;
    *
    */
    friend Matrix operator*(const float scalar, Matrix const &obj);


    /**
    * For i,j indices, Matrix m:
    * m(i,j) will return the i,j element in the matrix
    */
    float &operator()(const int i, const int j);

    /**
    * For i index, Matrix m:
    * m[i] will return the i element in the matrix
    */
    float &operator[](const int i);

    /**
    * For i,j indices, Matrix m:
    * m(i,j) will return the i,j element in the matrix
    */
    const float &operator()(const int i, const int j) const;

    /**
     * For i index, Matrix m:
     * m[i] will return the i element in the matrix
     */
    const float &operator[](const int i) const;


    /**
     *
     * Pretty export of matrix as per section 3.4
     *
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &c);

    /**
     *
     * Fills matrix elements
     * has to read input stream fully
     * otherwise,that's an error (dont trust the user to validate it).
     * ifstream is; Matrix m(rows,cols)
     * ...
     * is>>m
     **/
    friend std::istream &operator>>(std::istream &os, Matrix &c);

};


#endif //MATRIX_H
