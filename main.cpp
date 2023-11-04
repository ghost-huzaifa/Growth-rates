#include <iostream>
#include <chrono>

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
/*void divideAndRule(const int array[], int size)
{*/



			

int main()
{
	
	int size = 1000;
	int array[size];
	for(int i = 0; i < size ; i++)
	{

		array[i] = rand() % size; 
	}
	const auto startNaive = std::chrono::high_resolution_clock::now();
	naiveFunction(array, size);
	const auto endNaive = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> naiveElapsed = endNaive - startNaive;
	std::cout << "Naive Function Elapsed Time: " << naiveElapsed.count() << " ms" << std::endl;
	const auto startImproved = std::chrono::high_resolution_clock::now();
	improvedFunction(array, size);
	const auto endImproved = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> improvedElapsed = endImproved - startImproved;
	std::cout << "Imrpoved Algorithm Elapsed Time: " << improvedElapsed.count() << " ms" << std::endl;
	return 0;
}

