#include "MlpNetwork.h"

// constructors:

/**
 * ‫‪Accepts‬‬ ‫‪2‬‬ ‫‪arrays,‬‬ ‫‪size‬‬ ‫‪4‬‬ ‫‪each.‬‬
 * ‫‪one‬‬ ‫‪for‬‬ ‫‪weights‬‬ ‫‪and‬‬ ‫‪one‬‬ ‫‪for‬‬ ‫‪biases.‬‬
 * ‫‪constructs‬‬ ‫‪the‬‬ ‫‪network‬‬ ‫‪described‬‬ ‫‪(sec.‬‬ ‫‪3.1)
 * @param weights
 * @param bias
 */
MlpNetwork::MlpNetwork(Matrix *weights, Matrix *bias) : firstLayer(weights[0], bias[0], Relu),
        secondLayer(weights[1], bias[1], Relu), thirdLayer(weights[2], bias[2], Relu),
        fourthLayer(weights[3], bias[3], Softmax)
{

}

// methods:
/**
* ‫‪Applies‬‬ ‫‪the‬‬ ‫‪entire‬‬ ‫‪network‬‬ ‫‪on‬‬ ‫‪input‬‬
* ‫‪returns‬‬ ‫‪digit‬‬ ‫‪struct‬‬
* ‫‪digit‬‬ output= m(img)‬‬
* @param img
*/
Digit MlpNetwork::operator()(const Matrix &img)
{
    Matrix r1 = firstLayer(img);
    Matrix r2 = secondLayer(r1);
    Matrix r3 = thirdLayer(r2);
    Matrix r4 = fourthLayer(r3);


    return _mostLikelyDigit(r4);
}

/**
 * Returns the most likey digit output from an input vector as per section 2.2.1
 * @param mat
 *
 */
Digit MlpNetwork::_mostLikelyDigit(Matrix mat)
{
    unsigned int maxValueIndex = 0;
    float maxValue = 0;
    Digit digit;

    for (int i = 0; i < mat.getRows(); i++)
    {

        if (mat(i, 0) > maxValue)
        {

            maxValue = mat(i, 0);
            maxValueIndex = i;
        }
    }

    digit = {maxValueIndex, maxValue};

    return digit;
}


