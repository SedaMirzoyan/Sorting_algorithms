def merge(arr, lb, mid, ub):
    i = lb 
    j = mid + 1
    size = (ub - lb + 1)
    new_arr = [0] * size
    k = 0

    while((i <= mid) and (j <= ub)):
        if(arr[i] <= arr[j]):
            new_arr[k]= arr[i]
            i += 1
        else:
            new_arr[k] = arr[j]
            j += 1
        k += 1

    if(j > ub):
        while(i <= mid):
            new_arr[k]= arr[i]
            i += 1 
            k += 1
    if(i > mid):
        while(j <= ub):
            new_arr[k]= arr[j]
            j += 1 
            k += 1

    for i in range(0, k):       
        arr[lb+i] = new_arr[i]

    return arr




def merge_sort(arr, lb, ub):
    if(lb < ub):
        mid = int((lb + ub)/2)
        merge_sort(arr, lb, mid)
        merge_sort(arr, mid + 1, ub)
        merge(arr, lb, mid, ub)
        


def main():
    input_arr = [7, 4, -2, 15, 27, 1, -3, 98, 0, 8]
    lb = 0
    ub = len(input_arr) - 1
    merge_sort(input_arr, lb, ub)
    print(input_arr)



if __name__=="__main__":
    main()