inline int find_min(int arr[], int size) {  
    int min = arr[0]; // �����һ��Ԫ������С��  
    for (int i = 1; i < size; i++) {  
        if (arr[i] < min) {  
            min = arr[i]; // ����ҵ���С��Ԫ�أ��������Сֵ  
        }  
    }  
    return min;  
}
inline int GenerateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}