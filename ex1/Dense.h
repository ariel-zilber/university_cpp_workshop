#ifndef EX1_DENSE_H
#define EX1_DENSE_H

#include "Activation.h"
#include "Matrix.h"

/**
 *  Represents a layer in the neural network.
 * It will be used to define and activate the action of all the layers in the neural network
 * Made per section 4.3
 *  @author - Ariel Zilbershtein
 *  @CS login - arikzil
 *
 * */
class Dense
{
public:

    // constructors:

    /**
     *
     * Inits a new layer with given parameters.
     * note: ctor accepts 2 matrices and activation type
     * @param w
     * @param bias
     * @param activationType
     */
    Dense(Matrix &w, Matrix &bias, ActivationType activationType);

// methods:

    /**
     * Returns the weights of this layer
     * forbids modification
     * **/
    Matrix getWeights();

    /**
     * Returns the bias of this layer
     * forbids modification
     * **/
    Matrix getBias();

    /**
     * Returns the activation function of this layer
     * forbids modification
     * **/
    Activation getActivation();

    /**
     * Applies the layer on input and returns output matrix
     * Layers operate as per section 3.1
     * Matrix& output = layer(input)
     * */
    Matrix operator()(const Matrix &input);


private:
    const Matrix weight;
    const Matrix bias;
    const Activation activation;

};

#endif //EX1_DENSE_H
