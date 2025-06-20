#Insert in max heap

def insert_in_heap(orig_arr, n, value):
    i = n + 1 
    arr = orig_arr + [value]
    temp = 0

    while(i > 2):
        parent = int(i/2)

        if(arr[parent-1] < arr[i-1]):
            temp = arr[parent-1]
            arr[parent-1] = arr[i-1]
            arr[i-1] = temp

            i = parent 
        #to avoid infinite loop
        else:
            return arr
        
    return arr

        


input_arr = [70, 50, 40, 45, 35, 39, 16, 10, 9]
heap_size  = 9
heap  = insert_in_heap(input_arr, heap_size, 60)
print(heap)
new_heap  = insert_in_heap(heap, heap_size + 1, 5)
print(new_heap)
