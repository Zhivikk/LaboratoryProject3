#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <math.h>
using namespace std;
//If1.Дано ціле число. Якщо воно є додатним, то відняти від нього 8;
// інакше не змінювати його. Вивести отримане число.
void task_if1(void); // завдання 1 оголошення функції
// Дано координати точки на площині (x, y).
// Визначити, чи потрапляє точка в фігуру заданого кольору (або групу фігур)
// і вивести відповідне повідомлення.
void task_geom2(void);// завдання 2 оголошення функції
// Дано радіус r.
// Визначти площину та периметр двох фігур
void task_geom3(void);// завдання 3 оголошення функції
//Функції 2 Завдання:
bool defaultFunction(double x, double y, double r); // Функція 1
bool reversedFunction(double x, double y, double r); // Функція 2
bool negativeFunction(double x, double y, double r); // Функція 3
bool circleFunction(double x, double y, double r); // Функція належності до кола
int main() {
	int menu;
	cout << "Task number:";
	cin >> menu;
	switch (menu)
	{ // перемикання між завданнями
	case 1: task_if1(); break; // Завдання 1
	case 2: task_geom2(); break; // Завдання 2
	case 3: task_geom3(); break; // Завдання 3
	default: cout << "Wrong task! (Only 1,2,3)" << endl; //повідомлення про помилку
	}
	system("pause");
	return 0;

}


void task_if1(void)// завдання 1 реалізація
{
	//Декларація змінних
	signed int firstnumber, secondnumber;
	cout << "************* If 11 *****************" << endl;
	//Введення даних
	cout << "Type First Number:";
	cin >> firstnumber;
	cout << "Type Second Number:";
	cin >> secondnumber;
	//Знаходження чисел за формулою
	if (firstnumber != secondnumber) //Якщо числа різні, то привласнюємо меншому числу значення більшого
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
	else // Якщо числа рівні, то оба числа повинні дорівнювати нулю
	{
		firstnumber = 0;
		secondnumber = 0;
	}
	//Вивід даних
	cout << "First Number:" << firstnumber << endl; // Перше число
	cout << "Second Number:" << secondnumber << endl; // Друге число


}

	
void task_geom2(void)
{
	//Декларація змінних
	double X, Y, R;
	bool figure1 = false;
	bool figure2 = false;
	bool common = false;
	//Введення даних
	cout << "*************Task 2 *****************" << endl;
	cout << "Radius:" << endl;
	cin >> R;
	cout << "X:" << endl;
	cin >> X;
	cout << "Y:" << endl;
	cin >> Y;
	
	figure1 = circleFunction(X, Y, R) && defaultFunction(X, Y, R) && reversedFunction(X, Y, R); // Три вимоги знаходження точки на площі першої фігури
	figure2 = negativeFunction(X, Y, R) && (X > 0) && (Y < 0); // Дві вимоги знаходження точки на площі другої фігури
	common = figure1 || figure2; // Программа перевіряє, чи знаходиться на якійсь площі з цих двох фігур
	if (common)
	{
		cout << "Coordinates are on area!" << endl; // Точка знаходиться на площі
	}
	else
	{
		cout << "Coordinates are not on area!" << endl; // Точка не знаходиться на площі
	}
}

//Перелік Функцій
//Функція 1. y=x
bool defaultFunction(double x, double y, double r)
{
	double threshold;
	threshold = x;
	if (y > threshold) // Якщо координата вище прямої, то вимога виконується 
	{
		return(true);
	}
	else return(false); // Якщо координата нижче прямої, то вимога не виконується
}
//Функція 2. y = -x + sqrt(2)*r
bool reversedFunction(double x, double y, double r)
{
	double threshold;
	threshold = -x + sqrt(2) * r;
	if (y > threshold) // Якщо координата вище прямої, то вимога виконується 
	{
		return(true);
	}
	else return(false); // Якщо координата нижче прямої, то вимога не виконується
}
//Функція 3. y = x - sqrt(2)*r
bool negativeFunction(double x, double y, double r)
{
	double threshold;
	threshold = x - sqrt(2) * r; // Функція прямої
	if (y > threshold) // Якщо координата вище прямої, то вимога виконується
	{
		return(true);
	}
	else return(false); // Якщо координата нижче прямої, то вимога не виконується

}
//Функція 4. Коло.
bool circleFunction(double x, double y, double r)
{
	double distance, rcoord;
	rcoord = r / sqrt(2); // Координата радіусу
	distance = sqrt(pow(x - rcoord, 2) + pow(y - rcoord, 2)); // Формула дистанції даної точки до центра кола
	if (distance > r)
	{
		return(false); // Якщо дистанція від точки до центру кола менше радіусу, то точка знаходиться у колі.
	}
	else
	{
		return(true); // Якщо більше, то вона поза кола.
	}
}



void task_geom3(void)// завдання 3 реалізація
{
	//Декларація змінних
	double r, circleperimeter, figure_1perimeter,  triangleperimeter, circlesurface, trianglesurface, figure_2surface, figure_1surface, triangleside, innerTriangleSurface, figure_2perimeter;
	double brownSegmentSurface;
	//Введення даних змінних
	cout << "*************Geometry 33*****************" << endl;
	cout << "Type Radius:" << endl;
	cin >> r;

	//Знаходження периметру кола та його площи
	circleperimeter = 2 * M_PI * r;
	circlesurface = M_PI * pow(r, 2);

	//Знаходження периметру та площи верхньої фігури
	figure_1surface = circlesurface / 4;
	figure_1perimeter = (circleperimeter / 4) + r + r;

	//Знаходження площи опуклості нижньої фігури
	innerTriangleSurface = pow(r,2)/2;
	brownSegmentSurface = figure_1surface - innerTriangleSurface;

	//Знаходження однієї зі сторін та площи трикутника знизу
	triangleside = sqrt(2)*r;
	trianglesurface = pow(triangleside, 2) / 2;

	//Знаходження периметру та площи нижньої фігури
	figure_2perimeter = triangleside + r + r + (circleperimeter / 4);
	figure_2surface = trianglesurface - brownSegmentSurface;

	//Вивод даних
	cout << "Figures Area:" << figure_2surface + figure_1surface << endl;

	cout << "Figures Perimeter:" << figure_2perimeter + figure_1perimeter << endl;

}