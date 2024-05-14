#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <iostream>
#include <map>
#include "Vector.h"


template <typename T>
T findMax(const Vector<T>& arr, int n)
{
    T max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    std::cout << "max = " << max << std::endl;
    return max;
}

template <>
int findMax<int>(const Vector<int>& arr, int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    std::cout << "max = " << max << std::endl;
    return max;
}



template <typename T>
void countingSortVec(const T&  arr, int n)
{
    int max = findMax<int>(arr, n);
    int count = 0;
    int index = 0;
    std::map<int, int> elem_count;
    std::map<int, int> elem_index_val;

    int* counter_arr = new int[max+1];
    int* output_arr = new int[n];

    for (int i = 0; i <= max; i++)
    {
        counter_arr[i] = 0;
        elem_count.insert(std::pair<int, int>(i, 0));
    }

    //element's count
    for (int i = 0; i < n; i++)
    {
        elem_count[arr[i]]++;
    }

    for (auto it = elem_count.begin(); it != elem_count.end(); ++it)
    {
        std::cout << "\nmap   " << it->first << " " << it->second;
        counter_arr[it->first] = it->second;
    }

    std::cout << "\ncumultaive count\n";
    for (int i = 1; i <= max; i++)
    {
        counter_arr[i] = counter_arr[i-1] + counter_arr[i];
        std::cout << "counter_arr[" << i << "] = " << counter_arr[i] << " ";
    }

    //final step
    int elem;
    for (int i = 0; i < n; i++)
    {
        elem = arr[i];
            counter_arr[elem] = counter_arr[elem] - 1;
            output_arr[counter_arr[elem]] = elem;  
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "\noutput_arr[" << i << "] = " << output_arr[i] << " ";
    }

    delete[] counter_arr;
    delete[] output_arr;
}


#endif //COUNTING_SORT_H