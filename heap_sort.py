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
        


#delete from max heap
def delete_from_heap(arr, n):
    last_elem = arr[0]
    arr[0] = arr[n-1]
    arr[n-1] = last_elem

    arr.pop()

    i = 0
    while(i < n-1):
        left_child = (2*i+1)
        right_child = (2*i+2)
        largest = i
        
        if(left_child < len(arr) and (arr[left_child] > arr[largest])):
            largest = left_child
        if(right_child < len(arr) and (arr[right_child] > arr[i])):
            largest = left_child

        if (largest != i):
            print("in if")
            temp = arr[largest]
            arr[largest] = arr[i]
            arr[i] = temp
            i = largest
        else:
            break
        
    return arr



def heapify():
    pass


input_arr = [70, 50, 40, 45, 35, 39, 16, 10, 9]
heap_size  = 9
heap  = insert_in_heap(input_arr, heap_size, 60)
print(heap)
new_heap  = insert_in_heap(heap, heap_size + 1, 5)
print(new_heap)

test_arr = [30, 20, 7, 9, 15]
size = 5
del_heap = delete_from_heap(test_arr, size)
print(del_heap)