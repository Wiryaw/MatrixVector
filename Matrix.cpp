#include "Matrix.h"
#include <iostream>

#define PI 3.14159265

//default constructor
Matrix::Matrix(){
    matrix[0][0] = 0;
    rows = 1;
    cols = 1;
    total_size = 1;
}

//parameter constructor
// w/o initial value
Matrix::Matrix(unsigned _rows, unsigned _cols) {
    rows = _rows;
    cols = _cols;
    total_size = rows * cols;
    matrix.resize(_rows);
    for (unsigned i = 0; i < matrix.size(); i++) {
        matrix[i].resize(_cols, 0.0);
    }
}
// w/ initial value
Matrix::Matrix(unsigned _rows, unsigned _cols, double initial) {
    rows = _rows;
    cols = _cols;
    total_size = rows * cols;
    matrix.resize(_rows);
    for (unsigned i = 0; i < matrix.size(); i++) {
        matrix[i].resize(_cols, initial);
    }
}
//copy constructor
Matrix::Matrix(const Matrix& rhs) {
    matrix = rhs.matrix;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
    total_size = rhs.total_size;

}

//assignment constructor
Matrix& Matrix::operator=(const Matrix & rhs) {
    matrix.resize(rhs.rows);
    for (unsigned i = 0; i < matrix.size(); i++) {
        matrix[i].resize(rhs.cols, 0.0);
    }
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    for (unsigned i = 0; i < rhs.rows; i++) {
        for (unsigned j = 0; j < rhs.cols; j++) {
                matrix[i][j] = rhs.matrix[i][j];
            }
        }
    return *this;
    }

//destructor
Matrix::~Matrix() {};

//Matrix to Matrix

//addition
Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] + rhs.matrix[i][j];
        }
    }

    return result;
}
Matrix& Matrix::operator+=(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] += rhs.matrix[i][j];
        }
    }

    return *this;
}

//subtraction
Matrix Matrix::operator-(const Matrix& rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
        }
    }

    return result;
}
Matrix& Matrix::operator-=(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] -= rhs.matrix[i][j];
        }
    }

    return *this;
}

//multiplication
Matrix Matrix::elemult(const Matrix& rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] * rhs.matrix[i][j];
        }
    }
    
    return result;
}
Matrix& Matrix::elemult2(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] *= rhs.matrix[i][j];
        }
    }

    return *this;
}


//division
Matrix Matrix::elediv(const Matrix& rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] / rhs.matrix[i][j];
        }
    }

    return result;
}
Matrix& Matrix::elediv2(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] /= rhs.matrix[i][j];
        }
    }

    return *this;
}

//sum of product multiplication
Matrix Matrix::operator*(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = this->cols;
    Matrix result(rows, cols);
   
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            for (unsigned k = 0; k < rows; k++) {
                result(i, j) += this->matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }

    return result;
}
Matrix& Matrix::operator*=(const Matrix& rhs) {
    Matrix result = *this * rhs;
    this->rows = rhs.get_rows();
    *this = result;

    return *this;
}

//scalar

//scalar addition
Matrix Matrix::operator+(double rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] + rhs;
        }
    }

    return result;
}

Matrix Matrix::operator+=(double rhs) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] += rhs;
        }
    }
    return *this;
}
//scalar subtraction
Matrix Matrix::operator-(double rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] - rhs;
        }
    }

    return result;
}

Matrix Matrix::operator-=(double rhs) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] -= rhs;
        }
    }
    return *this;
}
//scalar multiplication
Matrix Matrix::operator*(double rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] * rhs;
        }
    }

    return result;
}

Matrix Matrix::operator*=(double rhs) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] *= rhs;
        }
    }
    return *this;
}

//scalar division
Matrix Matrix::operator/(double rhs) {
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] / rhs;
        }
    }

    return result;
}

Matrix Matrix::operator/=(double rhs) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->matrix[i][j] /= rhs;
        }
    }
    return *this;
}

////Make
//zero
Matrix& Matrix::zero() {
    unsigned rows = this->rows;
    unsigned cols = this->cols;
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = 0;
        }
    }
    *this = result;
    return *this;
}

//one
Matrix& Matrix::one() {
    unsigned rows = this->rows;
    unsigned cols = this->cols;
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = 1;
        }
    }
    *this = result;
    return *this;
}

//diagonal one
Matrix& Matrix::diagonal() {
    unsigned rows = this->rows;
    unsigned cols = this->cols;
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            if (i == j) {
                result(i, j) = 1;
            }
        }
    }
    *this = result;
    return *this;
}

//fill
Matrix& Matrix::fill(double fill) {
    unsigned rows = this->rows;
    unsigned cols = this->cols;
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = fill;
        }
    }
    *this = result;
    return *this;
}


//make matrix homogenous
 Matrix& Matrix::hom() {
     Matrix hom(rows + 1, cols + 1);
     hom.diagonal();
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            hom(i, j) = (*this).matrix[i][j];
        }
    }
    
     (*this) = hom;
     return *this;
 }

////matrix transformation
//2d

//translation
Matrix& Matrix::translate2d(double x, double y) {
    Matrix translate(rows + 1, cols + 1);
    Matrix result(rows, cols);
    translate.diagonal();
    for (unsigned i = 0; i < rows + 1; i++) {
        for (unsigned j = 0; j < cols + 1; j++) {
            if (j == 2 && i == 0) {
                translate(i, j) = x;
            }
            if (j == 2 && i == 1) {
                translate(i, j) = y;
            }
        }
    }
    result = (*this).hom() * translate;
    (*this) = result;
    return *this;
}

//scale
Matrix& Matrix::scale2d(double x, double y) {
    Matrix scale(rows + 1, cols + 1);
    Matrix result(rows, cols);
    scale.diagonal();
    for (unsigned i = 0; i < rows + 1; i++) {
        for (unsigned j = 0; j < cols + 1; j++) {
            if (j == 1 && i == 1) {
                scale(i, j) = x;
            }
            if (j == 2 && i == 2) {
                scale(i, j) = y;
            }
        }
    }
    result = (*this).hom() * scale;
    (*this) = result;
    return *this;
}

//rotate clockwise
Matrix& Matrix::rotate2d(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.matrix[0][0] = cos(degree * PI / 180);
    rotate.matrix[0][1] = -sin(degree * PI / 180);
    rotate.matrix[1][0] = sin(degree * PI / 180);
    rotate.matrix[1][1] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}

//rotate anti-clockwise
Matrix& Matrix::rotate2danti(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.matrix[0][0] = cos(degree * PI / 180);
    rotate.matrix[0][1] = sin(degree * PI / 180);
    rotate.matrix[1][0] = -sin(degree * PI / 180);
    rotate.matrix[1][1] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}

//3d
//translation
Matrix& Matrix::translate3d(double x, double y, double z) {
    Matrix translate(rows + 1, cols + 1);
    Matrix result(rows, cols);
    translate.diagonal();
    for (unsigned i = 0; i < rows + 1; i++) {
        for (unsigned j = 0; j < cols + 1; j++) {
            if (j == 3 && i == 0) {
                translate(i, j) = x;
            }
            if (j == 3 && i == 1) {
                translate(i, j) = y;
            }
            if (j == 3 && i == 2) {
                translate(i, j) = z;
            }
        }
    }
    result = (*this).hom() * translate;
    (*this) = result;
    return *this;
}

//scale
Matrix& Matrix::scale3d(double x, double y, double z) {
    Matrix scale(rows + 1, cols + 1);
    Matrix result(rows, cols);
    scale.diagonal();
    for (unsigned i = 0; i < rows + 1; i++) {
        for (unsigned j = 0; j < cols + 1; j++) {
            if (j == 1 && i == 1) {
                scale(i, j) = x;
            }
            if (j == 2 && i == 2) {
                scale(i, j) = y;
            }
            if (j == 3 && i == 3) {
                scale(i, j) = z;
            }
        }
    }
    result = (*this).hom() * scale;
    (*this) = result;
    return *this;
}

//rotate x
Matrix& Matrix::rotate3dx(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.diagonal();
    rotate.matrix[0][0] = cos(degree * PI / 180);
    rotate.matrix[0][1] = -sin(degree * PI / 180);
    rotate.matrix[1][0] = sin(degree * PI / 180);
    rotate.matrix[1][1] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}

//rotate x anti-clockwise
Matrix& Matrix::rotate3dxanti(double degree) {
Matrix rotate(rows, cols);
Matrix result(rows, cols);
rotate.diagonal();
rotate.matrix[0][0] = cos(degree * PI / 180);
rotate.matrix[0][1] = sin(degree * PI / 180);
rotate.matrix[1][0] = -sin(degree * PI / 180);
rotate.matrix[1][1] = cos(degree * PI / 180);
rotate.hom();
result = (*this).hom() * rotate;
(*this) = result;
return *this;
}

//rotate y
Matrix& Matrix::rotate3dy(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.diagonal();
    rotate.matrix[1][1] = cos(degree * PI / 180);
    rotate.matrix[1][2] = -sin(degree * PI / 180);
    rotate.matrix[2][1] = sin(degree * PI / 180);
    rotate.matrix[2][2] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}

//rotate y anti-clockwise
Matrix& Matrix::rotate3dyanti(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.diagonal();
    rotate.matrix[1][1] = cos(degree * PI / 180);
    rotate.matrix[1][2] = sin(degree * PI / 180);
    rotate.matrix[2][1] = -sin(degree * PI / 180);
    rotate.matrix[2][2] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}

//rotate z

Matrix& Matrix::rotate3dz(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.diagonal();
    rotate.matrix[0][0] = cos(degree * PI / 180);
    rotate.matrix[2][0] = -sin(degree * PI / 180);
    rotate.matrix[2][0] = sin(degree * PI / 180);
    rotate.matrix[2][2] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}

//rotate z anti-clockwise
Matrix& Matrix::rotate3dzanti(double degree) {
    Matrix rotate(rows, cols);
    Matrix result(rows, cols);
    rotate.diagonal();
    rotate.matrix[0][0] = cos(degree * PI / 180);
    rotate.matrix[2][0] = sin(degree * PI / 180);
    rotate.matrix[2][0] = -sin(degree * PI / 180);
    rotate.matrix[2][2] = cos(degree * PI / 180);
    rotate.hom();
    result = (*this).hom() * rotate;
    (*this) = result;
    return *this;
}


//vector only calculations
//length
double Matrix::length() {
    double length = 0;

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            length += this->matrix[i][j] * this->matrix[i][j];
        }
    }

    length = sqrt(length);
    return length;
}

//normalize
Matrix& Matrix::normalize() {
    double length = (*this).length();
    Matrix result(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] / length;
        }
    }

    (*this) = result;
    return (*this);
}

//dot
double Matrix::dot(const Matrix& rhs) {
    double result = 0;

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result += this->matrix[i][j] * rhs.matrix[i][j];
        }
    }
    return result;
}

//cross
double Matrix::cross(const Matrix& rhs) {
    double result = 0;

    result += 
        (this->matrix[0][1] * rhs.matrix[0][2]) - (this->matrix[0][2] * rhs.matrix[0][1]) +
        (this->matrix[0][2] * rhs.matrix[0][0]) - (this->matrix[0][0] * rhs.matrix[0][2]) +
        (this->matrix[0][0] * rhs.matrix[0][1]) - (this->matrix[0][1] * rhs.matrix[0][0]);

    return result;
}

//access the individual values                                                                                                                                            
double& Matrix::operator()(unsigned& row, unsigned& col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->matrix[row][col];
}
//const
const double& Matrix::operator()(const unsigned& row, const unsigned& col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->matrix[row][col];
}

//get row size                                                                                                                                    
unsigned Matrix::get_rows() const {
    return this->rows;
}

//get column size                                                                                                                                  
unsigned Matrix::get_cols() const {
    return this->cols;
}

//input individual value
Matrix& Matrix::input() {
    unsigned row = 0, col = 0;
    std::cout << "please enter 2nd matrix/vector\n" << std::endl;
    std::cout << "enter number of row (if vector, input 1) : " << std::endl;
    std::cin >> row;
    std::cout << "enter number of column : " << std::endl;
    std::cin >> col;
    Matrix temp(row, col);
    (*this) = temp;
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            std::cout << "enter values of  [" << i << "][" << j << "]" << std::endl;
            std::cin >> (*this)(i, j);
        }
    }
    for (unsigned i = 0; i < (*this).get_rows(); i++) {
        std::cout << "{    ";
        for (unsigned j = 0; j < (*this).get_cols(); j++) {
            std::cout << (*this)(i, j) << "    ";
        }
        std::cout << "}" << std::endl;
    }

    return *this;
}

//output values
Matrix& Matrix::output() {
    for (unsigned i = 0; i < (*this).get_rows(); i++) {
        std::cout << "{    ";
        for (unsigned j = 0; j < (*this).get_cols(); j++) {
            std::cout << (*this)(i, j) << "    ";
        }
        std::cout << "}\n" << std::endl;
    }

    return *this;
}

//check if dimension same
void Matrix::check_dimension(const Matrix& rhs) {
    unsigned row1 = this->rows;
    unsigned col1 = this->cols;
    unsigned row2 = rhs.get_rows();
    unsigned col2 = rhs.get_cols();
    while (row1 != row2 || col1 != col2) {
        std::cout << "Error:dimension not same" << std::endl;

        break;
    }
}

//check 1stmatrix/vector columns and 2nd matrix/vector rows
void Matrix::check_rowscols(const Matrix& rhs) {
    unsigned col1 = this->cols;
    unsigned row2 = rhs.get_rows();
    while (col1 != row2) {
        std::cout << "Error:dimension not same" << std::endl;

        continue;
    }
}

//check if 2d
void Matrix::check_2d() {
    if (rows != 2 || cols!= 2){
        std::cout << "Error: Not 2d Matrix" << std::endl;
    }
}

//check if 3d
void Matrix::check_3d() {
    if (rows != 3 || cols != 3) {
        std::cout << "Error: Not 3d Matrix" << std::endl;
    }
}

//check if vector
void Matrix::check_vec() {
    if (rows != 1) {
        std::cout << "Error: Not Vector" << std::endl;
    }
}

//check if 2d vector
void Matrix::check_2dvec() {
    if (rows != 1 || cols != 2) {
        std::cout << "Error: Not 2d Vector" << std::endl;
    }
}

//check if 3d vector
void Matrix::check_3dvec() {
    if (rows != 1 || cols != 3) {
        std::cout << "Error: Not 3d Vector" << std::endl;
    }
}