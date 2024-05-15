
#include <iostream>
#include <vector>


void insertionSort(std::vector<int>& vec)
{
    int j = 0;
    int tmp;

    for (int i = 1; i < vec.size(); ++i)
    {
        tmp = vec[i];
        j = i - 1;

        while (j >= 0 && tmp < vec[j])
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = tmp;
    }
}


void printVector(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
}


int main()
{
    std::vector<int> vec{ 12, -5, 43, 10, -11, 61, -2, 0, -11 };
    
    insertionSort(vec);
    printVector(vec);

    return 0;
}

