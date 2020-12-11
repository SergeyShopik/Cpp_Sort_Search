#include<iostream>
#include<ctime>
void initArrayAuto(int[], size_t);
void printArray(int[], size_t);
int binSearch(int[], size_t, int);
void insertSort(int[], size_t);
void staticVar()
{
	static int i;
	i++;
	std::cout << i << std::endl;
}
void autoVar()
{
	int i = 1;
	i++;
	std::cout << i << std::endl;
}
void _1_0to1000nums(int i = 5, int j = 7, int q = 10);
int searchMin(int[], size_t, size_t);
void _2_chooseSort(int[], size_t);
int newBinSearch(int[], size_t, int);
void _3_newInsertSort(int[], size_t);
int _4_leftRightSort(int[], size_t);
int findArithMean(int[], size_t);
int findElClosestToArithMean(int[], size_t);
int _5_leftRightArithMeanSort(int[], size_t);
void _6_lastDigitSort(int[], size_t);

int main()
{
	const size_t size = 10;
	int A[size];
	srand(time(0));
	// 1. Create function with default parameters taking three integers and prints all numbers between 0 and 1000 which are multiples of the parameters.
	_1_0to1000nums();

	// 2. Create function which gets min array element. Use selection sort.
	initArrayAuto(A, size);
	printArray(A, size);
	std::cout << std::endl;
	_2_chooseSort(A, size);
	printArray(A, size);

	// 3. Create function which performs binary search of a new element placement in a sorted array
	// and returns the new element insertion place.
	_3_newInsertSort(A, size);

	// 4. Function gets min array element. All elements by its left side are sorted in decreasing order, right side - increasing order.
	// Returns min element index.
	_4_leftRightSort(A, size);
	printArray(A, size);
	std::cout << "Min element index is: " << _4_leftRightSort(A, size) << std::endl;

	// 5. Function gets array element which has minimal difference with arithmetic mean of all array elements
	// and sorts all elements by its left side in increasing order, right side - decreasing order.
	// Returns element's index.
	std::cout << "Mean is: " << findArithMean(A, size) << std::endl;
	std::cout << "Index is: " << findElClosestToArithMean(A, size) << std::endl;

	_5_leftRightArithMeanSort(A, size);
	printArray(A, size);

	// 6. Function sorts array by element's last digit increasing order.
	_6_lastDigitSort(A, size);
	printArray(A, size);
	system("pause");
	return 0;
}
void initArrayAuto(int array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 50;
	}
}
void printArray(int array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
int binSearch(int arr[], size_t size, int key)
{
	int left = 0, right = size, middle;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (arr[middle] > key)
			right = middle;
		else if (arr[middle] < key)
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}
void insertSort(int arr[], size_t size)
{
	int temp, j;
	for (size_t i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
void _1_0to1000nums(int i, int j, int q)
{
	for (size_t o = 0; o < 1000; o++)
	{
		if (o % i == 0 && o % j == 0 && o % q == 0)
			std::cout << o << std::endl;
	}
}
int searchMin(int A[], size_t size, size_t kolMin)
{
	int index = kolMin;
	int min = A[kolMin];
	for (size_t i = kolMin + 1; i < size; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
			index = i;
		}
	}
	return index;
}
void _2_chooseSort(int A[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		int index = searchMin(A, size, i);
		int temp = A[i];
		A[i] = A[index];
		A[index] = temp;
	}
}
int newBinSearch(int arr[], size_t size, int key)
{
	int left = 0, right = size, middle;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (arr[middle] > key)
			right = middle;
		else left = middle + 1;
	}
	return left;
}
void _3_newInsertSort(int arr[], size_t size)
{
	int temp;
	for (size_t i = 1; i < size; i++)
	{
		temp = arr[i];
		int pos = newBinSearch(arr, i, temp);
		int j;
		for (j = i - 1; j >= pos; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
int _4_leftRightSort(int A[], size_t size)
{
	int minElIndex = searchMin(A, size, 0);
	for (size_t i = 1; i < minElIndex; i++)
	{
		int temp = A[i];
		int j;
		for (j = i - 1; j >= 0 && temp > A[j]; j--)
		{
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
	for ( int i = minElIndex + 1; i < size; i++)
	{
		int temp = A[i];
		int j;
		for (j = i - 1; j >= 0 && temp < A[j]; j--)
		{
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
	return minElIndex;
}
int findArithMean(int A[], size_t size)
{
	int sum = 0;
	int div = size;
	for (size_t i = 0; i < size; i++)
	{
		sum += A[i];
	}
	//return sum / size;
	return sum / div;
}
int findElClosestToArithMean(int A[], size_t size)
{
	int arithMean = findArithMean(A, size);
	int index = 0;
	int closest = A[0];
	for (size_t i = 1; i < size; i++)
	{
		if (abs(arithMean - A[i]) < abs(arithMean - closest))
		{
			closest = A[i];
			index = i;
		}
	}
	return index;
}
int _5_leftRightArithMeanSort(int A[], size_t size)
{
	int index = findElClosestToArithMean(A, size);
	for (size_t i = 1; i < index; i++)
	{
		int temp = A[i];
		int j;
		for (j = i - 1; j >= 0 && temp > A[j]; j--)
		{
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
	for (int i = index + 2; i < size; i++)
	{
		int temp = A[i];
		int j;
		for (j = i - 1; j >= 0 && temp < A[j]; j--)
		{
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
	return index;
}
void _6_lastDigitSort(int arr[], size_t size)
{
	int temp, j;
	for (size_t i = 1; i < size; i++)
	{
		temp = arr[i];
		int tempDigit = arr[i] % 10;
		for (j = i - 1; j >= 0 && tempDigit < arr[j] % 10; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}