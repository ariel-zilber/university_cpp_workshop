
#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Activation.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[] = {{128, 1}, {64, 1}, {20, 1}, {10, 1}};

/**
 *  Represents the  mlp network as per the the ex description
 *  Made per section 4.4
 *  @author - Ariel Zilbershtein
 *  @CS login - arikzil
 *
 * */
class MlpNetwork
{

public:

// constructors:

    /**
     * ‫‪Accepts‬‬ ‫‪2‬‬ ‫‪arrays,‬‬ ‫‪size‬‬ ‫‪4‬‬ ‫‪each.‬‬
     * ‫‪one‬‬ ‫‪for‬‬ ‫‪weights‬‬ ‫‪and‬‬ ‫‪one‬‬ ‫‪for‬‬ ‫‪biases.‬‬
     * ‫‪constructs‬‬ ‫‪the‬‬ ‫‪network‬‬ ‫‪described‬‬ ‫‪(sec.‬‬ ‫‪3.1)
     * @param weights
     * @param bias
     */
    MlpNetwork(Matrix weights[], Matrix bias[]);

// methods:

    /**
     * ‫‪Applies‬‬ ‫‪the‬‬ ‫‪entire‬‬ ‫‪network‬‬ ‫‪on‬‬ ‫‪input‬‬
     * ‫‪returns‬‬ ‫‪digit‬‬ ‫‪struct‬‬
     * ‫‪digit‬‬ output= m(img)‬‬
     * @param img
     */
    Digit operator()(const Matrix &img);

private:
    Dense firstLayer;
    Dense secondLayer;
    Dense thirdLayer;
    Dense fourthLayer;

    /**
     * Returns the most likey digit output from an input vector as per section 2.2.1
     * @param mat
     *
     */
    Digit _mostLikelyDigit(Matrix mat);

};

#endif // MLPNETWORK_H
