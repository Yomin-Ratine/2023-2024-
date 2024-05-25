#include "Header.h"
  
extern void ParkCar(Car car);  
extern void UnparkCar(char *license_plate);  
extern int FindCarIndex(char *license_plate);  
extern int CalcFee(int stay_duration);  

void display_parking_lot() {  
    printf("ͣ����״̬��\n");  
    for (int i = 0; i < parking_count; i++) {  
        printf("���ƺţ�%s������ʱ�䣺%d\n", parking_lot[i].license_plate, parking_lot[i].arrival_time);  
    }  
    printf("\n");  
}

int main() {  
    // ʾ��������ͣ�����뿪����ʾͣ����״̬  
    Car car1 = {"0000001", 0};  // ����ʱ��Ϊ0ʱ����  
    ParkCar(car1);  
    display_parking_lot();  
  
    Car car2 = {"0000002", 10};  // ����ʱ��Ϊ10ʱ����  
    ParkCar(car2);  
    display_parking_lot();  
  
    UnparkCar("0000001");  // ���辩A12345�뿪  
    display_parking_lot();  
  
    return 0;  
}