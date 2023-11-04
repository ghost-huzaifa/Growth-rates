#include <iostream>
#include <chrono>

int maxOfThree(int first, int second, int third);
void naiveFunction(const int array[], const int sizeOfArray)
{
	//Implementation of Naive Program
	int maxSum = 0;
	for(int i= 0; i < sizeOfArray; i++)
	{
		for(int j = i; j < sizeOfArray ; j++)
		{
			int sumOfCurrent = 0;
			for(int k = i; k <= j; k++)
			{
				sumOfCurrent += array[k];
			}
			if(sumOfCurrent > maxSum)
				maxSum = sumOfCurrent;
		}
	}
	std::cout << "Maximum Subsequent Sum of the given data: " << maxSum << std::endl;
}
void improvedFunction(const int array[], int size)
{
	//Implementation of the Improved Function
	int maxSum = 0;
	for(int i = 0; i < size; i++)
	{
		int sumOfCurrent = 0;
		for(int j = i; j < size; j++)
		{
			sumOfCurrent += array[j];
			if(sumOfCurrent > maxSum)
				maxSum = sumOfCurrent;
		}
	}
	std::cout << "Maximum Subsequent Sum of the given data by Improved Algorithm: " << maxSum << std::endl;
}
int divideAndRule(const int array[], int left, int right)
{
	int mid;
	if(left == right)
		return array[left];
	else 
		mid = (left + right) / 2;
	int maxLeft = divideAndRule(array, left, mid);
	int maxRight = divideAndRule(array, mid + 1, right);

	int maxLeftBorder = 0;
	int leftBorder = 0;
	for(int i = mid; i >= left; i--)
	{
		leftBorder += array[i];
		if(leftBorder > maxLeftBorder)
			maxLeftBorder = leftBorder;
	}
	
	int maxRightBorder = 0;
	int rightBorder = 0;
	for(int i = right; i >= mid + 1; i--)
	{
		rightBorder += array[i];
		if(rightBorder > maxRightBorder)
			maxRightBorder = rightBorder;
	}
	
	 return maxOfThree(maxLeft, maxRight, maxRightBorder + maxLeftBorder);
}
int maxOfThree(int first, int second, int third)
{
	if(first >= second && first >= third)
		return first;
	else if(second >= first && second >= third)
		return second;
	else
		return third;
}

int main()
{
	
	int size = 200;
	std::cout << "For N = " << size << std::endl;
	int array[size];
	for(int i = 0; i < size ; i++)
	{

		array[i] = rand() % size; 
	}
	//Starting and Ending Time of the Naive Algorithm using high_resolution_clock class from chrono library
	const auto startNaive = std::chrono::high_resolution_clock::now();
	naiveFunction(array, size);
	const auto endNaive = std::chrono::high_resolution_clock::now();
	//Calculating the Elapsed Time using duration class from chrono and converting the time into milliseconds
	std::chrono::duration<double, std::milli> naiveElapsed = endNaive - startNaive;
	std::cout << "Naive Function Elapsed Time: " << naiveElapsed.count() << " ms" << std::endl;
	const auto startImproved = std::chrono::high_resolution_clock::now();
	improvedFunction(array, size);
	const auto endImproved = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> improvedElapsed = endImproved - startImproved;
	std::cout << "Imrpoved Algorithm Elapsed Time: " << improvedElapsed.count() << " ms" << std::endl;
	const auto startBinary = std::chrono::high_resolution_clock::now();
	int binaryResult = divideAndRule(array, 0, size - 1);
	const auto endBinary = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> binaryElapsed = endBinary - startBinary;
	 std::cout << "Maximum Subsequent Sum for the given data by Divide and Conquer Algorithm: " << binaryResult << std::endl;
	std::cout << "Divide and Conquer Elapsed Time: " << binaryElapsed.count() << " ms" << std::endl;

	return 0;
}

