#include "Activation.h"
// constructors:

/**
 * Accepts activation type (Relu/Softmax) and defines this instance’s activation accordingly
 * @param type
 * */
Activation::Activation(const ActivationType type) : myType(type)
{

}

/**
 * Returns this activation’s type(  Relu/Softmax)
 */
ActivationType Activation::getActivationType()
{
    return myType;
}

/**
 * float operator()(const int i,const  int j);
 * Applies activation function on input.(Does not change input)
 * Matrix output = act(input)
 *
 * @param input
 **/
Matrix Activation::operator()(const Matrix &matrix)
{

    switch (myType)
    {
        case Relu:
            return _reluAction(matrix);
        case Softmax:
            return _softmaxAction(matrix);
    }

    return matrix;
}

/**
 * float operator()(const int i,const  int j);
 * Applies activation function on input.(Does not change input)
 * Matrix output = act(input)
 *
 * @param input
 **/
Matrix Activation::operator()(const Matrix &matrix) const
{

    switch (myType)
    {
        case Relu:
            return _reluAction(matrix);
        case Softmax:
            return _softmaxAction(matrix);
    }

    return matrix;
}

/**
 * Perform the relu action on a given matrix
 * @param mat
 * */
Matrix Activation::_reluAction(const Matrix &mat)
{

    Matrix activatedMat = Matrix(mat);
    int matRows = mat.getRows();
    int matCols = mat.getCols();

    // performs the relu action
    for (int i = 0; i < matRows; i++)
    {
        for (int j = 0; j < matCols; j++)
        {
            if (activatedMat(i, j) < 0)
            {
                activatedMat(i, j) = 0;
            }
        }
    }

    return activatedMat;
}

/**
 * Perform the relu action on a given matrix
 * @param mat
 * */
Matrix Activation::_reluAction(const Matrix &mat) const
{

    Matrix activatedMat = Matrix(mat);

    int matRows = mat.getRows();
    int matCols = mat.getCols();

    // performs the relu action
    for (int i = 0; i < matRows; i++)
    {
        for (int j = 0; j < matCols; j++)
        {
            if (activatedMat(i, j) < 0)
            {
                activatedMat(i, j) = 0;
            }

        }
    }

    return activatedMat;

}

/**
* Perform the relu action on a given matrix
* @param mat
 * */
Matrix Activation::_softmaxAction(const Matrix &mat)
{
    Matrix activatedMat = Matrix(mat);
    int matRows = activatedMat.getRows();
    int matCols = activatedMat.getCols();
    float sum = 0;


    // perform the softmax action:

    // 1. get the exponent of every cell in the vector
    for (int i = 0; i < matRows; i++)
    {
        for (int j = 0; j < matCols; j++)
        {
            activatedMat(i, j) = std::exp(activatedMat(i, j));
            sum += activatedMat(i, j);
        }
    }

    // 2. normalize the vector
    for (int i = 0; i < matRows; i++)
    {
        for (int j = 0; j < matCols; j++)
        {
            activatedMat(i, j) = (activatedMat(i, j) / sum);
        }
    }

    return activatedMat;
}

/**
* Perform the relu action on a given matrix
* @param mat
 * */
Matrix Activation::_softmaxAction(const Matrix &mat) const
{
    Matrix activatedMat = Matrix(mat);
    int matRows = activatedMat.getRows();
    int matCols = activatedMat.getCols();
    float sum = 0;

    // perform the softmax action:

    // 1. get the exponent of every cell in the vector
    for (int i = 0; i < matRows; i++)
    {
        for (int j = 0; j < matCols; j++)
        {
            activatedMat(i, j) = std::exp(activatedMat(i, j));
            sum += activatedMat(i, j);
        }
    }

    // 2. normalize the vector
    for (int i = 0; i < matRows; i++)
    {
        for (int j = 0; j < matCols; j++)
        {
            activatedMat(i, j) = (activatedMat(i, j) / sum);
        }
    }

    return activatedMat;
}

