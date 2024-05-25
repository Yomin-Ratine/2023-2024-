#include "Header.h"
void ParkCar(Car car) {  
    if (parking_count < MAX_CARS) {  
        parking_lot[parking_count++] = car;  
    } else if (waiting_count < MAX_WAITING) {  
        waiting_line[waiting_count++] = car;  
        // ������Ӵ��봦��ͣ�����п�λʱ���ӵȴ��������Ƴ�����ͣ���������  
    } else {  
        printf("ͣ�����ͱ���������������޷�ͣ�š�\n");  
    }  
}  

void UnparkCar(char *license_plate) {  
    int index = find_car_index(license_plate);  
    if (index != -1) {  
        for (int i = index; i < parking_count - 1; i++) {  
            parking_lot[i] = parking_lot[i + 1];  
        }  
        parking_count--;  
        // ������Ӵ��봦�������еȴ�����ʱ������һ��������ͣ���������  
    } else {  
        printf("δ�ҵ�ָ�����Ƶĳ�����\n");  
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
    // ����ÿ��λʱ�����Ϊ1��������Ը���ʵ����������Ʒѹ���  
    return stay_duration;  
}