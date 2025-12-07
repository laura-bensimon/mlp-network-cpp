//
// Created by Marc Mars on 16/06/2020.
//

#include "MlpNetwork.h"

/**
* @brief Constructor definition of the class
* @param weights Array of weights
* @param biases Array of biases
*/
MlpNetwork::MlpNetwork(Matrix weights[], Matrix biases[])
{
    _weigths = weights;
    _biases = biases;
}

/**
 * @brief Find the max probability and value of the final layer of the neural network
 * @param mat The final matrix (final layer with 10 elements)
 * @return The digit
 */
Digit findVal(const Matrix& mat)
{
    Digit final;
    float max = 0;
    for (int i = 0; i < (mat.getCols() * mat.getRows()); i++)
    {
        if (mat[i] > max)
        {
            max = mat[i];
            final.value = i;
        }
    }
    final.probability = max;
    return final;
}
/**
 * @brief Operator () overloaded of the class. Execute all the network
 * @param input Initial matrix
 * @return The digit (max probability and value of the final layer)
 */
Digit MlpNetwork::operator()(Matrix &input) const
{
    Matrix mat = input;
    ActivationType act_type[4] = {Relu, Relu, Relu, Softmax};
    for (int i = 0; i < MLP_SIZE; i++)
    {
        Dense d = Dense(_weigths[i], _biases[i], act_type[i]);
        mat = d(mat);
    }
    Digit fin = findVal(mat);
    return fin;
}



