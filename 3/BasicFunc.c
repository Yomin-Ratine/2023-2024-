inline int find_min(int arr[], int size) {  
    int min = arr[0]; // 假设第一个元素是最小的  
    for (int i = 1; i < size; i++) {  
        if (arr[i] < min) {  
            min = arr[i]; // 如果找到更小的元素，则更新最小值  
        }  
    }  
    return min;  
}
inline int GenerateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}