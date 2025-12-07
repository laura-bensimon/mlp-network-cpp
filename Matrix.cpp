//
// Created by Marc Mars on 15/06/2020.
//

#include "Matrix.h"
#include <iostream>

#define ERROR 1
#define ROWS_COLS_ERR "Error: Rows and cols size should be positive integers!"
#define MULTIPLICATION_ERR "Error: Number of column of first matrix differs from number of row"
#define ADDITION_ERR "Error: Both matrixes don't have the same size of rows and cols"
#define INDEX_ERR "Error: Index out of range"
#define FILE_ERR "Error: File couldn't be totally read"

/**
* @brief Constructor declaration of the matrix that takes number of rows and cols. Note that
* the matrix is initialized with 0's only
* @param rows The number of rows
* @param cols The number of cols
*/
Matrix::Matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        std::cerr << ROWS_COLS_ERR << std::endl;
        exit(ERROR);
    }
    _rows = rows;
    _cols = cols;
    _arrData = new float[_rows*_cols]();
}

/**
* @brief Overloaded operator= that assigns the matrix passed to the current instance
* @param rhs The matrix passed
* @return A reference of the newly assigned matrix
*/
Matrix& Matrix::operator=(const Matrix &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    delete [] _arrData;
    _cols = rhs._cols;
    _rows = rhs._rows;
    _arrData = new float[_rows * _cols]();

    for (int i = 0; i < _rows * _cols; i++)
    {
        _arrData[i] = rhs._arrData[i];
    }

    return *this;
}

/**
* @brief Destructor of the matrix that deletes all the elemnts
*/
Matrix::~Matrix()
{
    delete [] _arrData;
}

Matrix::Matrix(const Matrix& other)
{
    this->operator=(other);
}
/**
* @brief Vectorize the current instance of the matrix
* @return A vectorized matrix (as defined in the exercise)
*/
Matrix& Matrix::vectorize()
{
    _rows = _rows * _cols;
    _cols = 1;
    return *this;
}
/**
* @brief Print the matrix as asked in the exercise
*/
void Matrix::plainPrint() const
{
    for (int i = 0; i < _rows ; i++)
    {
        for (int j = 0; j <  _cols ; j++)
        {
            std::cout << _arrData[i * _cols + j] << " ";
        }
        std::cout << std::endl;
    }
}
/**
* @brief Overloaded operator* of the class
* @param lhs The lhs matrix
* @param rhs The rhs matrix
* @return A copy of the product of both matrix passed
*/
Matrix operator*(const Matrix &lhs, const Matrix &rhs)
{
     if (lhs._cols != rhs._rows)
     {
         std::cerr << MULTIPLICATION_ERR << std::endl;
         exit(ERROR);
     }
     Matrix mat = Matrix(lhs._rows, rhs._cols);
     for (int i = 0 ; i < lhs._rows ; i++)
     {
         for (int j = 0 ; j < rhs._cols ; j++)
         {
             for (int k = 0; k < lhs._cols ; k++)
             {
                 mat._arrData[i * mat._cols + j] += lhs[i * lhs._cols + k] *
                         rhs[k * rhs._cols + j];
             }
         }
     }
     return mat;
}
/**
* @brief Overloaded operator* of the class
* @param lhs The lhs matrix
* @param scalar The rhs matrix
* @return A copy of the product of the scalar(to the right of the matrix) and matrix
*/
Matrix operator*(const Matrix &lhs, const float &scalar)
{
    Matrix mat = Matrix(lhs);
    for (int i = 0; i < lhs._rows * lhs._cols ; i++)
    {
        mat._arrData[i] = lhs._arrData[i] * (float)scalar;
    }
    return mat;
}
/**
* @brief Overloaded operator* of the class
* @param scalar The lhs matrix
* @param rhs The rhs matrix
* @return A copy of the product of the scalar(to the left of the matrix) and matrix
*/
Matrix operator*(const float&scalar, const Matrix &rhs)
{
    Matrix mat = Matrix(rhs);
    for (int i = 0; i < rhs._rows * rhs._cols ; i++)
    {
        mat._arrData[i] = rhs._arrData[i] * scalar;
    }
    return mat;
}
/**
* @brief Overloaded operator+ of the class
* @param lhs The lhs matrix
* @param rhs The rhs matrix
* @return A copy of the sum of of both matrix passed
*/
Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs._cols != rhs._cols || rhs._rows != lhs._rows)
    {
        std::cerr << ADDITION_ERR << std::endl;
        exit(ERROR);
    }
    Matrix mat = Matrix(lhs._rows, lhs._cols);
    for (int i = 0; i < lhs._rows * lhs._cols ; i++)
    {
        mat._arrData[i] = lhs._arrData[i] + rhs._arrData[i];
    }
    return mat;
}

/**
* @brief Overloaded operator+= of the class
* @param rhs The matrix to add
* @return A referenced of the current instance matrix, to which we added the rhs matrix
*/
Matrix &Matrix::operator+=(const Matrix &rhs)
{
    if (_cols != rhs._cols || _rows != rhs._rows)
    {
        std::cerr << ADDITION_ERR << std::endl;
        exit(ERROR);
    }
    for (int i = 0; i < _rows * _cols; i++)
    {
        _arrData[i] += rhs._arrData[i];
    }
    return *this;
}
/**
* @brief Overloaded operator() of the class
* @param row Index row
* @param col Index col
* @return The element at the index (row,col)
*/
float& Matrix::operator()(int row, int col) const
{
    if (row < 0 || col < 0 || row >= _rows || col >= _cols)
    {
        std::cerr << INDEX_ERR << std::endl;
        exit(ERROR);
    }
    return _arrData[row * _cols + col];
}
/**
* @brief Overloaded operator[] of the class
* @param coord The index to get
* @return The element at the index coord
*/
float &Matrix::operator[](int coord) const
{
    if (coord >= (_rows * _cols) || coord < 0)
    {
        std::cerr << INDEX_ERR << std::endl;
        exit(ERROR);
    }
    return _arrData[coord];
}
/**
* @brief Overloaded operator<< of the class
* @param os The file to read
* @param mat The matrix that we'll print
* @return A reference to the ostream file
*/
std::ostream &operator<<(std::ostream &os, const Matrix &mat)
{
    for (int i = 0; i < mat._rows; i++)
    {
        for (int j = 0; j < mat._cols; j++)
        {
            if (mat._arrData[i * mat._cols + j] <= 0.1f)
            {
                os << "  ";
            }
            else
            {
                os << "**";
            }
        }
        os << std::endl;
    }
    return os;
}
/**
* @brief Overloaded operator>>of the class
* @param s The file to read
* @param mat The matrix that will get the elements in the file s
* @return A reference to the istream file
*/
std::istream &operator>>(std::istream &s, const Matrix &mat)
{
    s.read((char*)mat._arrData, sizeof(float) * mat._rows * mat._cols);
    if (!s || s.peek() != EOF)
    {
        std::cerr << FILE_ERR << std::endl;

        exit(ERROR);
    }
    return s;
}
