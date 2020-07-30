#include <cstring>
#include "Matrix.h"


// constructors:


/**
*Constructs Matrix rows × cols
* Inits all elements to 0
* @param rows
* @param cols
*/
Matrix::Matrix(int rows, int cols)
{
    // check the dimensions
    if (rows < 0 || cols < 0)
    {
        std::cerr << "ERROR: bad matrix dimentions were given" << std::endl;
        exit(1);
    }

    dims.rows = rows;
    dims.cols = cols;
    matrixData = new float[rows * cols]{};
}

/**
 * Constructs Matrix 1 × 1
 * Inits all elements to 0
 *
 */
Matrix::Matrix() : Matrix(1, 1)
{

}

/**
 * Constructs a matrix form another matrix
 * @param m
 *
 */

Matrix::Matrix(const Matrix &m) : dims{m.dims.rows, m.dims.cols}
{
    matrixData = new float[m.dims.rows * m.dims.cols]{};
    memcpy(matrixData, m.matrixData, m.dims.rows * m.dims.cols * sizeof(float));
}

/**
 * Destructor
 */
Matrix::~Matrix()
{
    delete[](matrixData);
}

// methods:

/**
 * Returns the number of rows
 * @return number of rows
 */
int Matrix::getRows()
{
    return dims.rows;
}

/**
 * Returns the number of rows
 * @return number of rows
 */
int Matrix::getRows() const
{
    return dims.rows;
}

/**
 * Returns the number of cols
 * @return number of cols
 */
int Matrix::getCols()
{
    return dims.cols;
}

/**
 * Returns the number of cols
 * @return number of cols
 */
int Matrix::getCols() const
{
    return dims.cols;
}

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
Matrix Matrix::vectorize()
{
    dims.rows = dims.cols * dims.rows;
    dims.cols = 1;

    Matrix matrix = Matrix(*this);

    return matrix;
}

/**
 *
 * Prints matrix elements, no return value.
 * prints space after each element (incl. last element in the row)
 * prints newline after each row (incl. last row)
 */
void Matrix::plainPrint()
{

    for (int i = 0; i < dims.rows; i++)
    {
        for (int j = 0; j < dims.cols; j++)
        {
            std::cout << operator()(i, j) << " ";
        }
        std::cout << std::endl;
    }
}


/**
 *
 * Prints matrix elements, no return value.
 * prints space after each element (incl. last element in the row)
 * prints newline after each row (incl. last row)
 */
void Matrix::plainPrint() const
{

    for (int i = 0; i < dims.rows; i++)
    {
        for (int j = 0; j < dims.cols; j++)
        {
            std::cout << matrixData[i * dims.cols + j] << " ";
        }

        std::cout << std::endl;
    }
}

/**
 * Assigment of matrix.
 * i.e Matrix a, b;
 *...
 *a = b;
 */
Matrix &Matrix::operator=(Matrix const &obj)
{

    if (&obj != this)
    {
        const int rows = obj.dims.rows;
        const int cols = obj.dims.cols;
        this->dims.rows = rows;
        this->dims.cols = cols;

        delete[] (matrixData);
        matrixData = new float[obj.dims.rows * obj.dims.cols];
        memcpy(matrixData, obj.matrixData, obj.dims.rows * obj.dims.cols * sizeof(float));

    }

    return *this;
}

/**
* Matrix addition
* Matrix a,b;->a+b;
*/
Matrix Matrix::operator+(Matrix const &obj)
{

    if ((dims.rows != obj.dims.rows) || (dims.cols != obj.dims.cols))
    {
        std::cerr << "ERROR: wrong matrix dimensions were given";
        exit(1);
    }

    int rows = dims.rows;
    int cols = dims.cols;

    Matrix mat = Matrix(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat.matrixData[i * dims.cols + j] = matrixData[i * dims.cols + j] +
                                                obj.matrixData[i * dims.cols + j];
        }
    }

    return mat;

}

/**
* Matrix addition
* Matrix a,b;->a+b;
*/
Matrix Matrix::operator+(Matrix const &obj) const
{

    // check the dimensions
    if ((dims.rows != obj.dims.rows) || (dims.cols != obj.dims.cols))
    {
        std::cerr << "ERROR: wrong matrix dimensions were given";
        exit(1);
    }

    int rows = dims.rows;
    int cols = dims.cols;

    Matrix mat = Matrix(rows, cols);

    // perform the addition action
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat.matrixData[i * dims.cols + j] = matrixData[i * dims.cols + j] +
                                                obj.matrixData[i * dims.cols + j];
        }
    }

    return mat;

}


/**
* Matrix addition
* Matrix a,b;->a+=b;
*
*/
Matrix Matrix::operator+=(Matrix const &obj)
{

    // check the dimensions:
    if ((dims.rows != obj.dims.rows) || (dims.cols != obj.dims.cols))
    {
        std::cerr << "ERROR: wrong matrix dimensions were given";
        exit(1);
    }

    int rows = dims.rows;
    int cols = dims.cols;

    //  perform the addition operation
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrixData[i * dims.cols + j] += obj.matrixData[i * dims.cols + j];
        }
    }

    return *this;

}

/**
 * Matrix multiplications
 * Matrix a,b;->a*b;
 *
 */
Matrix Matrix::operator*(Matrix const &obj)
{

    //  check the dimensions of the matrix
    if (dims.cols != obj.dims.rows)
    {
        std::cerr << "Error: the matrix dimentions are not the same" << std::endl;
        exit(1);
    }

    Matrix mat = Matrix(dims.rows, obj.dims.cols);

    // perform the multiplication action:
    for (int i = 0; i < dims.rows; i++)
    {
        for (int j = 0; j < obj.dims.cols; j++)
        {
            for (int k = 0; k < dims.cols; k++)
            {
                mat(i, j) += this->operator()(i, k) * obj(k, j);
            }
        }
    }

    return mat;
}

/**
* Matrix multiplication by a scalar
* Matrix a,Scalar b;->a*b;
*
*/
Matrix Matrix::operator*(const float scalar)
{

    // get the date for the
    Matrix mat = Matrix(*this);

    int rows = dims.rows;
    int cols = dims.cols;


    // perform scalar multiplication action:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat[i * dims.cols + j] = mat[i * dims.cols + j] * scalar;
        }
    }


    return mat;
}

/**
* Matrix multiplication by a scalar
* Matrix a,Scalar b;->a*b;
*
*/
Matrix Matrix::operator*(const float scalar) const
{

    // get the date for the
    Matrix mat = Matrix(*this);


    int rows = dims.rows;
    int cols = dims.cols;

    // perform scalar multiplication action:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat[i * dims.cols + j] = mat[i * dims.cols + j] * scalar;
        }
    }

    return mat;
}

/**
* Matrix multiplication by a scalar
* Matrix a,Scalar b;->a*b;
*
*/
Matrix operator*(const float scalar, Matrix const &obj)
{
    Matrix mat = Matrix(obj);
    return mat * scalar;
}

/**
 * Matrix multiplications
 * Matrix a,b;->a*b;
 *
 */
Matrix Matrix::operator*(Matrix const &obj) const
{

    // check the dimensions of the matrix
    if (dims.cols != obj.dims.rows)
    {
        std::cerr << "Error: the matrix dimentions are not the same" << std::endl;
        exit(1);
    }

    // perform the multiplication action
    Matrix mat = Matrix(dims.rows, obj.dims.cols);

    for (int i = 0; i < dims.rows; i++)
    {
        for (int j = 0; j < obj.dims.cols; j++)
        {
            for (int k = 0; k < dims.cols; k++)
            {
                mat(i, j) += matrixData[i * dims.cols + k] * obj(k, j);
            }
        }
    }

    return mat;
}

/**
* For i,j indices, Matrix m:
* m(i,j) will return the i,j element in the matrix
*/
float &Matrix::operator()(const int i, const int j)
{
    // check the input indices:

    if ((i * dims.cols + j) >= (dims.cols * dims.rows))
    {
        std::cerr << "ERROR: matrix dimensions were exceeded" << std::endl;
        exit(1);
    }

    if (i < 0 || j < 0)
    {
        std::cerr << "ERROR: invalid matrix dimensions were given" << std::endl;
        exit(1);
    }

    // return the appropriate cell
    return matrixData[i * dims.cols + j];
}

/**
* For i index, Matrix m:
* m[i] will return the i element in the matrix
*/
float &Matrix::operator[](const int i)
{

    if (i >= dims.rows * dims.cols)
    {
        std::cerr << "ERROR: matrix dimensions were exceeded" << std::endl;
        exit(1);
    }

    if (i < 0)
    {
        std::cerr << "ERROR: invalid matrix dimensions were given" << std::endl;
        exit(1);
    }

    return matrixData[i];
}

/**
* For i,j indices, Matrix m:
* m(i,j) will return the i,j element in the matrix
*/
const float &Matrix::operator()(const int i, const int j) const
{
    // check the indices:

    if ((i * dims.cols + j) >= (dims.cols * dims.rows))
    {
        std::cerr << "ERROR: matrix dimensions were exceeded" << std::endl;
        exit(1);
    }

    if (i < 0 || j < 0)
    {
        std::cerr << "ERROR: invalid matrix dimensions were given" << std::endl;
        exit(1);
    }

    return matrixData[i * dims.cols + j];
}

/**
 * For i index, Matrix m:
 * m[i] will return the i element in the matrix
 */
const float &Matrix::operator[](const int i) const
{

    // check the operator:

    if (i >= dims.rows * dims.cols)
    {
        std::cerr << "ERROR: matrix dimensions were exceeded" << std::endl;
        exit(1);
    }

    if (i < 0)
    {
        std::cerr << "ERROR: invalid matrix dimensions were given" << std::endl;
        exit(1);
    }

    return matrixData[i];
}

/**
 *
 * Pretty export of matrix as per section 3.4
 *
 */
std::ostream &operator<<(std::ostream &os, const Matrix &c)
{
    int rows = c.dims.rows;
    int cols = c.dims.cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (c(i, j) > 0.1f)
            {
                os << "**";
            }
            else
            {
                os << "  ";
            }
        }
        os << std::endl;
    }

    return os;
}

/**
 *
 * Fills matrix elements
 * has to read input stream fully
 * otherwise,that's an error (dont trust the user to validate it).
 * ifstream is; Matrix m(rows,cols)
 * ...
 * is>>m
 **/
std::istream &operator>>(std::istream &in, Matrix &c)
{

    Matrix temp = Matrix(c.dims.rows, c.dims.cols);
    in.read((char *) temp.matrixData, sizeof(float) * c.dims.rows * c.dims.cols);

    if (!in.fail())
    {
        memcpy(c.matrixData, temp.matrixData, temp.dims.rows * temp.dims.cols * sizeof(float));
    }

    return in;
};
