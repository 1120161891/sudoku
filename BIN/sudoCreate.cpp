#include "stdafx.h"
#include "sudoCreate.h"
#include "sudo.h"

extern int rowarray[9][9];
extern int colarray[9][9];
//extern int *matrixarray[1000000];
extern void print(int *matrix);

const int sudoCreate::numarray[9] = { 3,4,5,6,7,8,9,1,2 };


const int sudoCreate::map[81] = {
	1,2,3,4,5,6,7,8,9,
	4,5,6,7,8,9,1,2,3,
	7,8,9,1,2,3,4,5,6,
	2,1,4,3,6,5,8,9,7,
	3,6,5,8,9,7,2,1,4,
	8,9,7,2,1,4,3,6,5,
	5,3,1,6,4,2,9,7,8,
	6,4,2,9,7,8,5,3,1,
	9,7,8,5,3,1,6,4,2
};

sudoCreate::sudoCreate(int num,int **matrixarray)
{
	this->num = num;
	this->count = 0;
	this->matrixarray = matrixarray;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			this->matrix[i][j] = 0;
			this->line[i][j] = true;
			this->column[i][j] = true;
		}
}


void sudoCreate:: generateMatrix(int *array,int i,int n) {
	if (this->count == this->num) {
		return;
	}
	if (i == n) {
		getMatrix(array);
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			this->swap(array+i,array+j);
			generateMatrix(array,i+1,n);
			this->swap(array+i,array+j);
		}

	}
}


 void sudoCreate::swap(int *a ,int *b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}


void sudoCreate::getMatrix(int array[8])
{
	this->matrix[0][0] = 2;						
	for (int i = 1; i < 9; i++) {
		this->matrix[0][i] = array[i - 1];
	}
	
	for (int i = 1; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			this->matrix[i][j] = this->matrix[0][map[i * 9 + j]-1];
		}
	}
	
	for (int i1 = 0; i1 < 2; i1++) {
		switch (i1) {
		case 0:
		case 1:
			for (int j = 0; j < 9; j++) {
				this->swap(&(matrix[j][1]),&(matrix[j][2]));
			}
			break;
		default:
			break;
		}
		for (int i2 = 0; i2 < 6; i2++) {
			switch (i2) {
			case 1:
			case 3:
			case 5:
				for (int j = 0; j < 9; j++) {
					this->swap(&(matrix[j][3]),&(matrix[j][4]));
				}
				break;
			case 0:
			case 2:
			case 4:
				for (int j = 0; j < 9; j++) {
					this->swap(&(matrix[j][4]),&(matrix[j][5]));
				}
				break;
			default:
				break;
			}
			for (int i3 = 0; i3 < 6; i3++) {
				switch (i3) {
				case 1:
				case 3:
				case 5:
					for (int j = 0; j < 9; j++) {
						this->swap(&(matrix[j][6]), &(matrix[j][7]));
					}
					break;
				case 0:
				case 2:
				case 4:
					for (int j = 0; j < 9; j++) {
						this->swap(&(matrix[j][7]), &(matrix[j][8]));
					}
					break;

				default:
					break;
				}
				for (int i4 = 0; i4 < 2; i4++) {
					switch (i4) {
					case 0:
					case 1:
						for (int j = 0; j < 9; j++) {
							this->swap(&(matrix[1][j]), &(matrix[2][j]));
						}
						break;
					default:
						break;
					}
					for (int i5 = 0; i5 < 6; i5++) {
						switch (i5) {
						case 1:
						case 3:
						case 5:
							for (int j = 0; j < 9; j++) {
								this->swap(&(matrix[3][j]), &(matrix[4][j]));
							}
							break;
						case 0:
						case 2:
						case 4:
							for (int j = 0; j < 9; j++) {
								this->swap(&(matrix[4][j]), &(matrix[5][j]));
							}
							break;
	
						default:
							break;
						}
						/*将产生的矩阵存好*/
						int* newmatrix = (int *)malloc(81*sizeof(int));
						for (int i = 0; i < 9; i++)
							for (int j = 0; j < 9; j++)
								newmatrix[i*9+j] = this->matrix[i][j];
						matrixarray[count] =newmatrix;
						this->count++;

						if (this->count == this->num) {
							return ;
						}

					}
				}
			}
		}
	}
	return ;
}
sudoCreate::~sudoCreate()
{}


