#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAX_CARS 10  // ����ͣ����������ͣ��10����  
#define MAX_WAITING 5  // ����������������5�����ȴ�  
  
typedef struct {  
    char license_plate[10];  // ���ƺ�  
    int arrival_time;        // ����ʱ��  
} Car;  
  
Car parking_lot[MAX_CARS];  // ͣ�����ڵĳ���  
Car waiting_line[MAX_WAITING];  // ����ϵĵȴ�����  
int parking_count = 0;  // ͣ�����ڳ�����  
int waiting_count = 0;  // ����ϵȴ��ĳ�����  