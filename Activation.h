//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

// Insert Activation class here...
/**
 * @brief Class that represents the Activation proccess
 */
class Activation
{
private:
    ActivationType _type;
    
    /**
    * @brief Applies the Relu function on the matrix
    * @param mat The matrix input
    * @return A reference of the modified matrix
    */
    static Matrix& _reluOp(Matrix &mat);
    /**
    * @brief Applies the Softmax function on the matrix
    * @param mat The matrix input
    * @return A reference of the modified matrix
    */
    static Matrix& _softMaxOp(Matrix &mat);
public:
	/**
     * @brief Constructor declaration of the class
     * @param type Function type (Relu or Softmax)
     */
    explicit Activation(ActivationType type);
    /**
     * @brief Get the activation type
     * @return Return the activation type
     */
    ActivationType getActivationType() const;
    /**
     * @brief Operator overloaded of the class
     * @param input The matrix that will be transformed with the activation function
     * @return
     */
    Matrix operator()(Matrix& input) const;
};

#endif //ACTIVATION_H
