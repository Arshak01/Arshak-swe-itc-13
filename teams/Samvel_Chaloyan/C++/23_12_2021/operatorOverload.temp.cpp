#include <iostream>

template <class T>

class Matric {
	private:
		T** mMatric;
		int mRow;
		int mColumn;
	public:
		Matric(int row, int column) {
			mRow = row;
			mColumn = column;
			T** matric = new T*[mRow];

			for (int i = 0; i < mRow; ++i) {
				matric[i] = new T[mColumn];
			}

			for(int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					mMatric[i][j] = i + j;
				}
			}
		}

		Matric(const Matric& m2) {
			mRow = m2.mRow;
			mColumn = m2.mColumn;
			mMatric = new T*[mRow];
			for (int i = 0; i < mRow; ++i) {
				mMatric[i] = new T[mColumn];
			}
			for (int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					mMatric[i][j] = m2.mMatric[i][j];
				}
			}
		}

		~Matric() {
			for (int i = 0; i < mRow; ++i) {
				delete[] mMatric[i];
			}
			delete[] mMatric;
		}

		Matric operator = (const Matric& m2) {
			Matric resultMatric(mRow, mColumn);
			for (int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					resultMatric.mMatric[i][j] = m2.mMatric[i][j];
				}
			}
			return resultMatric;
		}

		Matric operator + (const Matric& m2) {
			Matric resultMatric(mRow, mColumn);
			for (int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					resultMatric.mMatric[i][j] = mMatric[i][j] + m2.mMatric[i][j];
				}
			}
			return resultMatric;
		}

		Matric operator - (const Matric& m2) {
			Matric resultMatric(mRow, mColumn);
			for (int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					resultMatric.mMatric[i][j] = mMatric[i][j] - m2.mMatric[i][j];
				}
			}
			return resultMatric;
		}

		Matric operator * (const Matric& m2) {
			Matric resultMatric(mRow, mColumn);
			for (int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					resultMatric.mMatric[i][j] = mMatric[i][j] * m2.mMatric[i][j];
				}
			}
			return resultMatric;
		}

		Matric& operator += (const Matric& m2) {
			for (int i = 0; i < mRow; ++i) {
				for (int j = 0; j < mColumn; ++j) {
					this -> mMatric[i][j] += m2.mMatric[i][j];	
				}
			}
			return *this;
		}

		int getMatric(int row, int column) {
			return mMatric[mRow][mColumn];
		}
};

int main() {
	int row;
	int column;
	std::cout << "Enter matric size(row/column)\n";
	std::cin >> row >> column;
	
	Matric<int> m1(row, column);
	Matric<int> m2(row, column);
	Matric<int> resultMatric(row, column);
	
	std::cout << "First Matric\n";
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			std::cout << m1.getMatric(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Second Matric\n";
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			std::cout << m2.getMatric(i, j) << " ";
		}
		std::cout << std::endl;
	}	
	std::cout << std::endl;

	resultMatric = m1;
	std::cout << "Result Matric\n";
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			std::cout << resultMatric.getMatric(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
