#include <iostream>
#include <cmath>
#define NL std::cout << '\n'
using namespace std;

void main()
{
	const int n = 10;
	int A[n] = { -2, 4, -1, 5, 7, -3, 2, 0, -6, 8 };
	cout << "Array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << A[i] << "]" << " ";
	}
	NL; NL;

	//Max element
	int max = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] > max) { max = A[i]; }
	}
	cout << "Max element: " << max << endl;
	NL;
	//Sum elements
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 8)
		{
			sum += A[i];
		}
	}
	cout << "Sum elements: " << sum << endl;
	NL;

	//Squeeze array
	int B[n];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(A[i]) < 3 || abs(A[i]) > 7)
		{
			B[j] = A[i];
			j++;
		}
	}
	for (int i = j; i < n; i++)
	{
		B[i] = 0;
	}
	cout << "Squeezed array: "; NL;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << B[i] << "]" << " ";
	}
	NL;
	system("pause"); 
}
