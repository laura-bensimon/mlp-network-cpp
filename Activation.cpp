//
// Created by Marc Mars on 15/06/2020.
//

#include "Activation.h"
#include <cmath>

/**
* @brief Constructor definition of the class
* @param type Function type (Relu or Softmax)
*/
Activation::Activation(ActivationType type)
{
    _type = type;
}

/**
* @brief Get the activation type
* @return Return the activation type
*/
ActivationType Activation::getActivationType() const
{
    return _type;
}

/**
* @brief Applies the Relu function on the matrix
* @param mat The matrix input
* @return A reference of the modified matrix
*/
Matrix &Activation::_reluOp(Matrix &mat)
{
    for (int i = 0; i < mat.getCols() * mat.getRows(); i++)
    {
        if (mat[i] >= 0)
        {
            continue;
        }
        else
        {
            mat[i] = 0;
        }
    }
    return mat;
}
/**
* @brief Applies the Softmax function on the matrix
* @param mat The matrix input
* @return A reference of the modified matrix
*/
Matrix &Activation::_softMaxOp(Matrix &mat)
{

    float sum = 0;
    for (int i = 0; i < mat.getRows() * mat.getCols() ; i++)
    {
        mat[i] = std::exp(mat[i]);
    }
    for (int j = 0; j < mat.getRows() * mat.getCols() ; j++)
    {
        sum += mat[j];
    }
    mat = (1 / sum) * mat;
    return mat;
}


/**
* @brief Operator overloaded of the class
* @param input The matrix that will be transformed with the activation function
* @return The matrix with the transformations
*/
Matrix Activation::operator()(Matrix &input) const
{
    Matrix mat = input;
    Matrix &refMat = mat;
    switch (_type)
    {
        case Relu:
            mat = _reluOp(refMat);
            break;
        case Softmax:
            mat = _softMaxOp(refMat);
            break;
    }
    return mat;
}

