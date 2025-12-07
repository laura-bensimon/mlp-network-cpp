//
// Created by Marc Mars on 16/06/2020.
//
#include "Matrix.h"
#include "Activation.h"
#ifndef MLP_DENSE_H
#define MLP_DENSE_H

/**
 * @brief Class that represents the dense part of the exercise, the neural network
 */
class Dense
{
private:

    Matrix _weights;
    Matrix _bias;
    Activation _act;
public:
    /**
     * @brief Constructor declaration of dense class
     * @param w Array of weights
     * @param bias Array of bias
     * @param type Activation type for the activation func
     */
    Dense(const Matrix& w, const Matrix& bias, ActivationType type);
    /**
     * @brief Get the weights of the class
     * @return The weights of the class
     */
     Matrix getWeights() const;
    /**
     * @brief Get the bias of the class
     * @return The bias of the class
     */
     Matrix getBias() const;
    /**
     * @brief Get the activation of the class
     * @return The activation of the class
     */
     Activation getActivation() const;

    /**
     * @brief Overloading of the operator ()
     * @param input A matrix (ref)
     * @return A copy of a new matrix
     */
    Matrix operator()(Matrix& input) const;

};

#endif //MLP_DENSE_H