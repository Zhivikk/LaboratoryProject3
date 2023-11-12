#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <math.h>
using namespace std;
//If1.���� ���� �����. ���� ���� � ��������, �� ������ �� ����� 8;
// ������ �� �������� ����. ������� �������� �����.
void task_if1(void); // �������� 1 ���������� �������
// ���� ���������� ����� �� ������ (x, y).
// ���������, �� ��������� ����� � ������ �������� ������� (��� ����� �����)
// � ������� �������� �����������.
void task_geom2(void);// �������� 2 ���������� �������
// ���� ����� r.
// �������� ������� �� �������� ���� �����
void task_geom3(void);// �������� 3 ���������� �������
//������� 2 ��������:
bool defaultFunction(double x, double y, double r); // ������� 1
bool reversedFunction(double x, double y, double r); // ������� 2
bool negativeFunction(double x, double y, double r); // ������� 3
bool circleFunction(double x, double y, double r); // ������� ��������� �� ����
int main() {
	int menu;
	cout << "Task number:";
	cin >> menu;
	switch (menu)
	{ // ����������� �� ����������
	case 1: task_if1(); break; // �������� 1
	case 2: task_geom2(); break; // �������� 2
	case 3: task_geom3(); break; // �������� 3
	default: cout << "Wrong task! (Only 1,2,3)" << endl; //����������� ��� �������
	}
	system("pause");
	return 0;

}


void task_if1(void)// �������� 1 ���������
{
	//���������� ������
	signed int firstnumber, secondnumber;
	cout << "************* If 11 *****************" << endl;
	//�������� �����
	cout << "Type First Number:";
	cin >> firstnumber;
	cout << "Type Second Number:";
	cin >> secondnumber;
	//����������� ����� �� ��������
	if (firstnumber != secondnumber) //���� ����� ���, �� ������������ ������� ����� �������� �������
	{
		if (firstnumber > secondnumber)
		{
			secondnumber = firstnumber;
		}
		else
		{
			firstnumber = secondnumber;
		}
	}
	else // ���� ����� ���, �� ��� ����� ������ ���������� ����
	{
		firstnumber = 0;
		secondnumber = 0;
	}
	//���� �����
	cout << "First Number:" << firstnumber << endl; // ����� �����
	cout << "Second Number:" << secondnumber << endl; // ����� �����


}

	
void task_geom2(void)
{
	//���������� ������
	double X, Y, R;
	bool figure1 = false;
	bool figure2 = false;
	bool common = false;
	//�������� �����
	cout << "*************Task 2 *****************" << endl;
	cout << "Radius:" << endl;
	cin >> R;
	cout << "X:" << endl;
	cin >> X;
	cout << "Y:" << endl;
	cin >> Y;
	
	figure1 = circleFunction(X, Y, R) && defaultFunction(X, Y, R) && reversedFunction(X, Y, R); // ��� ������ ����������� ����� �� ����� ����� ������
	figure2 = negativeFunction(X, Y, R) && (X > 0) && (Y < 0); // �� ������ ����������� ����� �� ����� ����� ������
	common = figure1 || figure2; // ��������� ��������, �� ����������� �� ����� ����� � ��� ���� �����
	if (common)
	{
		cout << "Coordinates are on area!" << endl; // ����� ����������� �� �����
	}
	else
	{
		cout << "Coordinates are not on area!" << endl; // ����� �� ����������� �� �����
	}
}

//������ �������
//������� 1. y=x
bool defaultFunction(double x, double y, double r)
{
	double threshold;
	threshold = x;
	if (y > threshold) // ���� ���������� ���� �����, �� ������ ���������� 
	{
		return(true);
	}
	else return(false); // ���� ���������� ����� �����, �� ������ �� ����������
}
//������� 2. y = -x + sqrt(2)*r
bool reversedFunction(double x, double y, double r)
{
	double threshold;
	threshold = -x + sqrt(2) * r;
	if (y > threshold) // ���� ���������� ���� �����, �� ������ ���������� 
	{
		return(true);
	}
	else return(false); // ���� ���������� ����� �����, �� ������ �� ����������
}
//������� 3. y = x - sqrt(2)*r
bool negativeFunction(double x, double y, double r)
{
	double threshold;
	threshold = x - sqrt(2) * r; // ������� �����
	if (y > threshold) // ���� ���������� ���� �����, �� ������ ����������
	{
		return(true);
	}
	else return(false); // ���� ���������� ����� �����, �� ������ �� ����������

}
//������� 4. ����.
bool circleFunction(double x, double y, double r)
{
	double distance, rcoord;
	rcoord = r / sqrt(2); // ���������� ������
	distance = sqrt(pow(x - rcoord, 2) + pow(y - rcoord, 2)); // ������� ��������� ���� ����� �� ������ ����
	if (distance > r)
	{
		return(false); // ���� ��������� �� ����� �� ������ ���� ����� ������, �� ����� ����������� � ���.
	}
	else
	{
		return(true); // ���� �����, �� ���� ���� ����.
	}
}



void task_geom3(void)// �������� 3 ���������
{
	//���������� ������
	double r, circleperimeter, figure_1perimeter,  triangleperimeter, circlesurface, trianglesurface, figure_2surface, figure_1surface, triangleside, innerTriangleSurface, figure_2perimeter;
	double brownSegmentSurface;
	//�������� ����� ������
	cout << "*************Geometry 33*****************" << endl;
	cout << "Type Radius:" << endl;
	cin >> r;

	//����������� ��������� ���� �� ���� �����
	circleperimeter = 2 * M_PI * r;
	circlesurface = M_PI * pow(r, 2);

	//����������� ��������� �� ����� ������� ������
	figure_1surface = circlesurface / 4;
	figure_1perimeter = (circleperimeter / 4) + r + r;

	//����������� ����� �������� ������ ������
	innerTriangleSurface = pow(r,2)/2;
	brownSegmentSurface = figure_1surface - innerTriangleSurface;

	//����������� ���� � ����� �� ����� ���������� �����
	triangleside = sqrt(2)*r;
	trianglesurface = pow(triangleside, 2) / 2;

	//����������� ��������� �� ����� ������ ������
	figure_2perimeter = triangleside + r + r + (circleperimeter / 4);
	figure_2surface = trianglesurface - brownSegmentSurface;

	//����� �����
	cout << "Figures Area:" << figure_2surface + figure_1surface << endl;

	cout << "Figures Perimeter:" << figure_2perimeter + figure_1perimeter << endl;

}