#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAX_CARS 10  // 假设停车场最多可以停放10辆车  
#define MAX_WAITING 5  // 假设便道上最多可以有5辆车等待  
  
typedef struct {  
    char license_plate[10];  // 车牌号  
    int arrival_time;        // 到达时间  
} Car;  
  
Car parking_lot[MAX_CARS];  // 停车场内的车辆  
Car waiting_line[MAX_WAITING];  // 便道上的等待车辆  
int parking_count = 0;  // 停车场内车辆数  
int waiting_count = 0;  // 便道上等待的车辆数  