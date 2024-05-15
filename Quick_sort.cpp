
#include <iostream>
#include <vector>

int partition(std::vector<int>& vec, int lower_bound, int upper_bound)
{
    int start = lower_bound;
    int end = upper_bound;
    int pivot = vec[lower_bound];
    int loc = 0;

    while (start < end)
    {
        while (start <= upper_bound && vec[start] <= pivot)
        {
            start++;
        }

        while (end >= lower_bound && vec[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            std::swap(vec[start], vec[end]);
        }
    };
    loc = end;

    std::swap(vec[lower_bound], vec[loc]);

    return loc;
}

void quickSort(std::vector<int>& vec, int lower_bound, int upper_bound)
{
    int loc;
    if (lower_bound < upper_bound)
    {
        loc = partition(vec, lower_bound, upper_bound);
        quickSort(vec, lower_bound, loc - 1);
        quickSort(vec, loc + 1, upper_bound);
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
    std::vector<int> vec{ 7, 6, -10, 5, 9, -45, 2, 1, 15, 7, -10, -10, -34 };

    quickSort(vec, 0, vec.size()-1);
    printVector(vec);

    return 0;
}
