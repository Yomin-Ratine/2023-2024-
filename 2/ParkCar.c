#include "Header.h"
void ParkCar(Car car) {  
    if (parking_count < MAX_CARS) {  
        parking_lot[parking_count++] = car;  
    } else if (waiting_count < MAX_WAITING) {  
        waiting_line[waiting_count++] = car;  
        // 可以添加代码处理停车场有空位时，从等待队列中移车进入停车场的情况  
    } else {  
        printf("停车场和便道都已满，车辆无法停放。\n");  
    }  
}  

void UnparkCar(char *license_plate) {  
    int index = find_car_index(license_plate);  
    if (index != -1) {  
        for (int i = index; i < parking_count - 1; i++) {  
            parking_lot[i] = parking_lot[i + 1];  
        }  
        parking_count--;  
        // 可以添加代码处理便道上有等待车辆时，将第一辆车移入停车场的情况  
    } else {  
        printf("未找到指定车牌的车辆。\n");  
    }  
}
int FindCarIndex(char *license_plate) {  
    for (int i = 0; i < parking_count; i++) {  
        if (strcmp(parking_lot[i].license_plate, license_plate) == 0) {  
            return i;  
        }  
    }  
    return -1;  
}  
  
int CalcFee(int stay_duration) {  
    // 假设每单位时间费用为1，这里可以根据实际情况调整计费规则  
    return stay_duration;  
}