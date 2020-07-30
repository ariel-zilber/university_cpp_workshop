#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"
#include "cmath"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};


/**
 * Represents the activation action on a given matix input as per section 4.2
 *
 *  @author - Ariel Zilbershtein
 *  @CS login - arikzil
 *
 * */
 class Activation
{
public:

    //constructors:

    /**
     * Accepts activation type (Relu/Softmax) and defines this instance’s activation accordingly
     * @param type
     * */
    Activation(const ActivationType type);

    //methods:

    /**
     * Returns this activation’s type(  Relu/Softmax)
     */
    ActivationType getActivationType();

    /**
     * float operator()(const int i,const  int j);
     * Applies activation function on input.(Does not change input)
     * Matrix output = act(input)
     *
     * @param input
     **/
    Matrix operator()(const Matrix &input);

    /**
    * float operator()(const int i,const  int j);
    * Applies activation function on input.(Does not change input)
    * Matrix output = act(input)
     * @param input
    **/
    Matrix operator()(const Matrix &input) const;


private:
    ActivationType myType;

    //methods:

    //Perform the relu action on a given matrix
    Matrix _reluAction(const Matrix &mat);

    //Perform the relu action on a given matrix
    Matrix _softmaxAction(const Matrix &mat);

    // Perform the relu action on a given matrix
    Matrix _reluAction(const Matrix &mat) const;

    // Perform the relu action on a given matrix
    Matrix _softmaxAction(const Matrix &mat) const;

};

#endif //ACTIVATION_H
