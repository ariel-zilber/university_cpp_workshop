#include "Dense.h"

// constructors:

/**
 *
 * Inits a new layer with given parameters.
 * note: ctor accepts 2 matrices and activation type
 * @param w
 * @param bias
 * @param activationType
 */
Dense::Dense(Matrix &w, Matrix &bias, ActivationType activationType) : weight(w), bias(bias),
        activation(activationType)
{
}


// methods:

/**
 * Returns the weights of this layer
 * forbids modification
 */
Matrix Dense::getWeights()
{
    return weight;
}

/**
 * Returns the bias of this layer
 * forbids modification
*/
Matrix Dense::getBias()
{
    return bias;
}

/**
 * Returns the activation function of this layer
 * forbids modification
 */
Activation Dense::getActivation()
{
    return activation;
}


/**
 * Applies the layer on input and returns output matrix
 * Layers operate as per section 3.1
 * Matrix& output = layer(input)
 */
Matrix Dense::operator()(const Matrix &input)
{
    Matrix mat = Matrix(input);
    mat = activation((weight * mat) + bias);
    return mat;
}
