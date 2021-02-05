
//Registration N0:2018-CS-111:          Insertion Sort
#include<iostream> 
#include<fstream>
#include<string>
#include<chrono>			// for time funcitions

using namespace std;
void Insertion_sort(long int array[], int startIndex, long int endIndex);

void RandomArray(long int array[], int size)
{
	srand(time(0));			//to always make new numbers 
	for (long int i = 0; i < size; i++)
		array[i] = rand();
}

bool SaveSortedArray(long int array[], long int size)
{
	ofstream file;
	file.open("SortedInsertionSort.txt");
	if (file.is_open())
	{
		for (long int i = 0; i < size; i++)
			file << array[i] << endl;
		return 1;
	}
	else
		return 0;
}



int main()
{
	const long int arraySize = 300;
	long int array[arraySize];
	RandomArray(array, arraySize);

	cout << "Performing Insertion Sort on " << arraySize << " elements\n"<<endl<<endl;
		
	Insertion_sort(array, 0, (arraySize - 1));
	
	cout << "Saving the sorted array to the file\n";

	if (SaveSortedArray(array, arraySize))
		cout << "File has been saved successfully  at running program directory with name SortedInsertionSort.txt"<<endl<<endl;
	else
		cout << "File has not been saved successfully"<<endl<<endl;

	system("pause");
	return 0;

}


void Insertion_sort(long int array[], int startIndex, long int endIndex)
{
	int arrSize = endIndex + 1;
	for (int j = startIndex + 1; j < arrSize; j++)
	{
		int currentValue = array[j];
		int i = j - 1;
		while (i >= 0 and array[i] > currentValue)
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = currentValue;
	}
}
