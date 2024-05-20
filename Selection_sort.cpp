
#include <iostream>
#include <vector>


void selectionSort(std::vector<int>& vec)
{
    int min;

    for (int i = 0; i < vec.size() - 1; ++i)
    {
        min = i;
        for (int j = i+1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }        
        }
        if (i != min)
        {
            std::swap(vec[min], vec[i]);
        }
    }
}



void printVector(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
}


int main()
{
    std::vector<int> vec{ 124, 13, -7, 0, -7, 4, 110, 178, 30, 1, 1, 49 };

    selectionSort(vec);
    printVector(vec);

    return 0;
}

