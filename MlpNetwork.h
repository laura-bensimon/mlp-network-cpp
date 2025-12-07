//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[] = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

// Insert MlpNetwork class here...

/**
 * @brief Class that represents an Mlp Network
 */
class MlpNetwork
{
private:
    Matrix *_weigths;
    Matrix *_biases;

public:
	/**
     * @brief Constructor declaration of the class
     * @param weights Array of weights
     * @param biases Array of biases
     */
    MlpNetwork(Matrix weights[], Matrix biases[]);
    /**
     * @brief Overloaded operator () of the class, that executes all the neural network in order 
     * to get the solution
     * @param input A matrix (28x28)
     * @return A digit (value and probability)
     */
    Digit operator()(Matrix& input) const;
};

#endif // MLPNETWORK_H
