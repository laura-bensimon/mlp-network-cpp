// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#define DEFAULT_ROW 1
#define DEFAULT_COL 1

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

// Insert Matrix class here...
/**
 * @brief Class that represents a matrix
 */
class Matrix
{
private:
    int _rows{};
    int _cols{};
    float *_arrData{};
public:
    // Constructors
    /**
     * @brief Constructor declaration of the matrix that takes number of rows and cols. Note that
     * the matrix is initialized with 0's only
     * @param rows The number of rows
     * @param cols The number of cols
     */
    Matrix(int rows, int cols);
    /**
     * @brief Default constructor of the matrix that return a 1x1 matrix initialized with 0
     */
    Matrix() : Matrix(DEFAULT_ROW, DEFAULT_COL){}
    /**
     * @brief Copy constructor of the matrix
     * @param other Matrix to copy
     */
    Matrix(const Matrix& other);
    // Destructor
    /**
     * @brief Destructor of the matrix that deletes all the elemnts
     */
    ~Matrix();

    // Getters
    /**
     * @brief Get the number of rows
     * @return The number of rows
     */
    int getRows() const { return _rows; };
    /**
     * @brief Get the number of cols
     * @return The number of cols
     */
    int getCols() const { return _cols; };

    // Vectorize
    /**
     * @brief Vectorize the current instance of the matrix
     * @return A vectorized matrix (as defined in the exercise)
     */
    Matrix& vectorize();

    // Plain Print
    /**
     * @brief Print the matrix as asked in the exercise
     */
    void plainPrint() const;

    // Operators
    /**
     * @brief Overloaded operator= that assigns the matrix passed to the current instance
     * @param rhs The matrix passed
     * @return A reference of the newly assigned matrix
     */
    Matrix& operator=(const Matrix& rhs);
    /**
     * @brief Overloaded operator* of the class
     * @param lhs The lhs matrix
     * @param rhs The rhs matrix
     * @return A copy of the product of both matrix passed
     */
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    /**
     * @brief Overloaded operator* of the class
     * @param lhs The lhs matrix
     * @param scalar The rhs matrix
     * @return A copy of the product of the scalar(to the right of the matrix) and matrix
     */
    friend Matrix operator*(const Matrix& lhs, const float& scalar);
    /**
     * @brief Overloaded operator* of the class
     * @param scalar The lhs matrix
     * @param rhs The rhs matrix
     * @return A copy of the product of the scalar(to the left of the matrix) and matrix
     */
    friend Matrix operator*(const float& scalar, const Matrix& rhs);
    /**
     * @brief Overloaded operator+ of the class
     * @param lhs The lhs matrix
     * @param rhs The rhs matrix
     * @return A copy of the sum of of both matrix passed
     */
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    /**
     * @brief Overloaded operator+= of the class
     * @param rhs The matrix to add
     * @return A referenced of the current instance matrix, to which we added the rhs matrix
     */
    Matrix& operator+=(const Matrix& rhs);
    /**
     * @brief Overloaded operator() of the class
     * @param row Index row
     * @param col Index col
     * @return The element at the index (row,col)
     */
    float& operator()(int row, int col) const;
    /**
     * @brief Overloaded operator[] of the class
     * @param coord The index to get
     * @return The element at the index coord
     */
    float& operator[](int coord) const;
    /**
     * @brief Overloaded operator<< of the class
     * @param os The file to read
     * @param mat The matrix that we'll print
     * @return A reference to the ostream file
     */
    friend std::ostream& operator<<(std::ostream &os, const Matrix& mat);
    /**
     * @brief Overloaded operator>>of the class
     * @param s The file to read
     * @param mat The matrix that will get the elements in the file s
     * @return A reference to the istream file
     */
    friend std::istream& operator>>(std::istream& s, const Matrix& mat);

};

#endif //MATRIX_H
