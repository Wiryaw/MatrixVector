#pragma once
#include <vector>
#include <math.h>

class Matrix
{
private:
	std::vector<std::vector<double> > matrix;
	unsigned rows;
	unsigned cols;
	unsigned total_size;

public:
	//Matrix
	Matrix(); //default
	Matrix(unsigned rows, unsigned cols); //Base
	Matrix(unsigned rows, unsigned cols, double initial); //Base w/ initial value
	Matrix(const Matrix& rhs); //Copy
	virtual ~Matrix(); //Destructor
	Matrix& operator=(const Matrix& rhs); // Overload 

	// Matrix to Matrix                                                                                                                                                                                              
	Matrix operator+(const Matrix& rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix operator-(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix operator*(const Matrix& rhs);
	Matrix& operator*=(const Matrix& rhs);
	Matrix elemult(const Matrix& rhs);
	Matrix& elemult2(const Matrix& rhs); // *=
	Matrix elediv(const Matrix& rhs);
	Matrix& elediv2(const Matrix& rhs); // /=

	// Matrix to vector
	std::vector<double> operator*(const std::vector<double>& rhs);
	std::vector<double> diag_vec();

	//scalar
	Matrix operator+(double);
	Matrix operator+=(double);
	Matrix operator-(double);
	Matrix operator-=(double);
	Matrix operator*(double);
	Matrix operator*=(double);
	Matrix operator/(double);
	Matrix operator/=(double);

	// Transformation Matrix
	Matrix& translate2d(double, double);
	Matrix& translate3d(double, double, double);
	Matrix& rotate2d(double);
	Matrix& rotate2danti(double);
	Matrix& rotate3dx(double);
	Matrix& rotate3dxanti(double);
	Matrix& rotate3dy(double);
	Matrix& rotate3dyanti(double);
	Matrix& rotate3dz(double);
	Matrix& rotate3dzanti(double);
	Matrix& scale2d(double, double);
	Matrix& scale3d(double, double, double);

	//Make
	Matrix& zero();
	Matrix& one();
	Matrix& diagonal();
	Matrix& fill(double);
	Matrix& hom(); //make homogenous

	//Vector
	double length();
	Matrix& normalize();
	double dot(const Matrix& rhs);
	double cross(const Matrix& rhs);

	//get individual values
	double& operator()(unsigned& row, unsigned& col);
	const double& operator()(const unsigned& row, const unsigned& col) const;

	//get rows and columns sizes
	unsigned get_rows() const;
	unsigned get_cols() const;
	
	//input individual value
	Matrix& input();

	//print values 
	Matrix& output();

	//checks
	void check_dimension(const Matrix& rhs);
	void check_rowscols(const Matrix& rhs);
	void check_2d();
	void check_3d();
	void check_vec();
	void check_2dvec();
	void check_3dvec();
};
