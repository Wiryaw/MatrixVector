#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix Matrix1(1,1);
	Matrix Matrix2(1,1);
	unsigned row = 0, col = 0;
	unsigned choice = 0;
	char boolchoice = 'y';
	double scalar = 0;
	double fill = 0;
	double x = 0;
	double y = 0;
	double z = 0;
	bool exit = true;
	bool _continue = true;


	while (exit) {
		cout << "please enter 1st matrix/vector\n" << endl;
		cout << "enter number of row (if vector, input 1) : " << endl;
		cin >> row;
		cout << "enter number of column : " << endl;
		cin >> col;
		Matrix temp(row, col);
		Matrix1 = temp;
		temp.~Matrix();
		
		for (unsigned i = 0; i < row; i++) {
			for (unsigned j = 0; j < col; j++) {
				cout << "enter values of  [" << i << "][" << j << "]" << endl;
				cin >> Matrix1(i, j);
			}
		}
		for (unsigned i = 0; i < Matrix1.get_rows(); i++) {
			cout << "{    ";
			for (unsigned j = 0; j < Matrix1.get_cols(); j++) {
				cout << Matrix1(i, j) << "    ";
			}
			cout << "}" << endl;
		}
		while (_continue) {
			cout <<
				"Choose calculation:\n\n"

				" Element to Element ( Component to Component)\n"
				"	1. Addition\n"
				"	2. Subtraction\n"
				"	3. Multiplication\n"
				"	4. Division\n\n"

				"	5. Sum of product multipication\n\n"

				" Scalar\n"
				"	6. Addition\n"
				"	7. Subtraction\n"
				"	8. Multiplication\n"
				"	9. Division\n"

				" Vector only operation\n\n"

				"  Singular operation\n"
				"	10. Normalize\n"
				"	11. Length\n"

				"  Vector to Vector\n"
				"	12. Dot\n"
				"	13. Cross\n\n"

				" Miscellaneous operations\n\n"

				"	14. Make all value 0\n"
				"	15. Make all value 1\n"
				"	16. Make all diagonal value 1\n"
				"	17. Fill all value with given number\n\n"

				" Transformation Matrix\n\n"

				"	18. 2D Translation\n"
				"	19. 3D Translation\n"
				"	20. 2D Scaling\n"
				"	21. 3D Scaling\n"
				"	22. 2D Clockwise Rotation \n"
				"	23. 2D Anti-Clockwise Rotation \n"
				"	24. 3D x axis Clockwise Rotation \n"
				"	25. 3D x axis Anti-Clockwise Rotation \n"
				"	26. 3D y axis Clockwise Rotation \n"
				"	27. 3D y axis Anti-Clockwise Rotation \n"
				"	28. 3D z axis Clockwise Rotation \n"
				"	29. 3D z axis Anti-Clockwise Rotation \n";

			cin >> choice;

			switch (choice) {

			case 1:
				Matrix2.input();
				Matrix1 += Matrix2;
				if(Matrix1.get_rows() == Matrix2.get_rows() && Matrix1.get_cols() == Matrix2.get_cols()){
					cout << " The sum is : \n";
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "dimension not same";
					break;
				}
			case 2:
				Matrix2.input();
				Matrix1 -= Matrix2;
				if (Matrix1.get_rows() == Matrix2.get_rows() && Matrix1.get_cols() == Matrix2.get_cols()) {
					cout << " The sum is : \n";
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "dimension not same";
					break;
				}
			case 3:
				Matrix2.input();
				Matrix1.elemult2(Matrix2);
				if (Matrix1.get_rows() == Matrix2.get_rows() && Matrix1.get_cols() == Matrix2.get_cols()) {
					cout << " The sum is : \n";
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "dimension not same";
					break;
				}
			case 4:
				Matrix2.input();
				Matrix1.elediv2(Matrix2);
				if (Matrix1.get_rows() == Matrix2.get_rows() && Matrix1.get_cols() == Matrix2.get_cols()) {
					cout << " The sum is : \n";
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "dimension not same";
					break;
				}
			case 5:
				Matrix2.input();
				Matrix1  *= Matrix2;
				if (Matrix1.get_rows() == Matrix2.get_cols()) {
					cout << " The sum is : \n";
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "1st row and 2nd column not same";
					break;
				}
			case 6:
				cout << "Input scalar value :\n";
				cin >> scalar;
				Matrix1 += scalar;

					cout << " The sum is : \n";
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
			case 7:
				cout << "Input scalar value :\n";
				cin >> scalar;
				Matrix1 -= scalar;

				cout << " The sum is : \n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 8:
				cout << "Input scalar value :\n";
				cin >> scalar;
				Matrix1 *= scalar;

				cout << " The sum is : \n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 9:
				cout << "Input scalar value :\n";
				cin >> scalar;
				Matrix1 /= scalar;

				cout << " The sum is : \n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 10:
				if (Matrix1.get_rows() == 1 && Matrix1.get_cols() == 2 || Matrix1.get_cols() == 3) {
					cout << "The length of the vector is : " << Matrix1.length() << endl;

					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "is not vector, cant calculate";
					break;
				}
			case 11:
				if (Matrix1.get_rows() == 1 && Matrix1.get_cols() == 2 || Matrix1.get_cols() == 3) {
					cout << "The normalized vector is : " << endl;
					Matrix1.normalize();
					Matrix1.output();

					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "is not vector, cant calculate";
					break;
				}
			case 12:
				if (Matrix1.get_rows() == 1 && Matrix1.get_cols() == 2 || Matrix1.get_cols() == 3) {
					Matrix2.input();
					if (Matrix2.get_rows() == 1 && Matrix2.get_cols() == 2 || Matrix1.get_cols() == 3) {
						cout << "The dot product of the vector is : " << Matrix1.dot(Matrix2) << endl;

						cout << "Do you want to continue calculation?(y/n)\n";
						cin >> boolchoice;
						if (boolchoice == 'y') {
							_continue = true;
						}
						else if (boolchoice == 'n') {
							_continue = false;
						}
						else {
							cout << "invalid response, default will continue calculation";
						}
						break;
					}
					else {
						cout << "is not vector, cant calculate";
						break;
					}
				}
				else {
					cout << "is not vector, cant calculate";
					break;
				}
			case 13:
				if (Matrix1.get_rows() == 1 && Matrix1.get_cols() ==  3) {
					Matrix2.input();
					if (Matrix2.get_rows() == 1 && Matrix2.get_cols() == 2 || Matrix1.get_cols() == 3) {
						cout << "The cross product of the vector is : " << Matrix1.cross(Matrix2) << endl;

						cout << "Do you want to continue calculation?(y/n)\n";
						cin >> boolchoice;
						if (boolchoice == 'y') {
							_continue = true;
						}
						else if (boolchoice == 'n') {
							_continue = false;
						}
						else {
							cout << "invalid response, default will continue calculation";
						}
						break;
					}
					else {
						cout << "is not 3d vector, cant calculate";
						break;
					}
				}
				else {
					cout << "is not 3d vector, cant calculate";
					break;
				}
			case 14:
				Matrix1.zero();
				cout << "\n\n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 15:
				Matrix1.one();
				cout << "\n\n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 16:
				Matrix1.diagonal();
				cout << "\n\n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 17:
				cout << "Input value : ";
				cin >> fill;
				Matrix1.fill(fill);
				cout << "\n\n";
				Matrix1.output();
				cout << "Do you want to continue calculation?(y/n)\n";
				cin >> boolchoice;
				if (boolchoice == 'y') {
					_continue = true;
				}
				else if (boolchoice == 'n') {
					_continue = false;
				}
				else {
					cout << "invalid response, default will continue calculation";
				}
				break;
			case 18:
				if (Matrix1.get_rows() == 2 && Matrix1.get_cols() == 2) {
					cout << "input x : ";
					cin >> x;
					cout << "input y : ";
					cin >> y;
					Matrix1.translate2d(x, y);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 2d" << endl;
					break;
				}
			case 19:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input x : ";
					cin >> x;
					cout << "input y : ";
					cin >> y;
					cout << "input z : ";
					Matrix1.translate3d(x, y, z);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 20:
				if (Matrix1.get_rows() == 2 && Matrix1.get_cols() == 2) {
					cout << "input x : ";
					cin >> x;
					cout << "input y : ";
					cin >> y;
					Matrix1.scale2d(x, y);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 2d" << endl;
					break;
				}
			case 21:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input x : ";
					cin >> x;
					cout << "input y : ";
					cin >> y;
					cout << "input z : ";
					Matrix1.scale3d(x, y, z);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 22:
				if (Matrix1.get_rows() == 2 && Matrix1.get_cols() == 2) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate2d( x );
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 2d" << endl;
					break;
				}
			case 23:
				if (Matrix1.get_rows() == 2 && Matrix1.get_cols() == 2) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate2danti(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 2d" << endl;
					break;
				}
			case 24:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate3dx(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 25:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate3dxanti(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 26:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate3dy(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 27:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate3dyanti(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 28:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate3dz(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			case 29:
				if (Matrix1.get_rows() == 3 && Matrix1.get_cols() == 3) {
					cout << "input degree : ";
					cin >> x;
					Matrix1.rotate3dzanti(x);
					Matrix1.output();
					cout << "Do you want to continue calculation?(y/n)\n";
					cin >> boolchoice;
					if (boolchoice == 'y') {
						_continue = true;
					}
					else if (boolchoice == 'n') {
						_continue = false;
					}
					else {
						cout << "invalid response, default will continue calculation";
					}
					break;
				}
				else {
					cout << "Matrix is not 3d" << endl;
					break;
				}
			default:
				cout << "invalid response, please pick another number\n\n" << endl;
				break;
			}
		
		}
		boolchoice = true;
		cout << "Do you want to do another calculation?(y/n)\n";
		cin >> boolchoice;
		if (boolchoice == 'y') {
			exit = true;
		}
		else  if (boolchoice == 'n') {
			exit = false;
		}
		else {
			cout << "invalid response, default will start a new calculation";
		}

				
	}
	return 0;
}