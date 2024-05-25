#include "Header.h"
  
extern void ParkCar(Car car);  
extern void UnparkCar(char *license_plate);  
extern int FindCarIndex(char *license_plate);  
extern int CalcFee(int stay_duration);  

void display_parking_lot() {  
    printf("停车场状态：\n");  
    for (int i = 0; i < parking_count; i++) {  
        printf("车牌号：%s，到达时间：%d\n", parking_lot[i].license_plate, parking_lot[i].arrival_time);  
    }  
    printf("\n");  
}

int main() {  
    // 示例操作：停车、离开和显示停车场状态  
    Car car1 = {"0000001", 0};  // 假设时间为0时到达  
    ParkCar(car1);  
    display_parking_lot();  
  
    Car car2 = {"0000002", 10};  // 假设时间为10时到达  
    ParkCar(car2);  
    display_parking_lot();  
  
    UnparkCar("0000001");  // 假设京A12345离开  
    display_parking_lot();  
  
    return 0;  
}