//
// Created by Marc Mars on 16/06/2020.
//

#include "Dense.h"
#include "Activation.h"

/**
 * @brief Constructor definition of dense class
 * @param w Array of weights
 * @param bias Array of bias
 * @param type Activation type for the activation func
 */
Dense::Dense(const Matrix& w, const Matrix& bias, ActivationType type) : _act(type)
{
    _weights = w;
    _bias = bias;
}
/**
 * @brief Get the weights of the class
 * @return The weights of the class
 */
Matrix Dense::getWeights() const
{
    return _weights;
}
/**
 * @brief Get the bias of the class
 * @return The bias of the class
 */
Matrix Dense::getBias() const
{
    return _bias;
}
/**
 * @brief Get the activation of the class
 * @return The activation of the class
 */
Activation Dense::getActivation() const
{
    return _act;
}
/**
 * @brief Overloading of the operator ()
 * @param input A matrix (ref)
 * @return A copy of a new matrix
 */
Matrix Dense::operator()(Matrix &input) const
{
    Matrix mat = (_weights * input) + _bias;
    mat = _act(mat);
    return mat;
}

