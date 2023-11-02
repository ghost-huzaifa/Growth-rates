#include <iostream>
#include <chrono>

void naiveFunction(const int* array[], const int sizeOfArray)
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
int main()
{
	int array[10000];
	for(int i = 0; i < 10000 ; i++)
	{

		array[i] = rand() % 1000; 
	}
	return 0;
}

