#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#include <time.h>  

#define MAX_CARS 10 // ����ͣ���������ͣ��10����  

// �����ṹ��  
typedef struct {
    int id;         // ����ID  
    int arrival;    // ����ʱ��  
    int duration;   // ͣ��ʱ��  
} Car;

// ͣ�����ṹ��  
typedef struct {
    Car cars[MAX_CARS]; // ͣ�����ڵĳ���  
    int top;            // ͣ�����ڵ�ǰ��������  
    Car waitingQueue[MAX_CARS]; // �ȴ�����  
    int waitingTop;           // �ȴ������еĳ�������  
} ParkingLot;

// ��ʼ��ͣ����  
void initParkingLot(ParkingLot* lot) {
    lot->top = 0;
    lot->waitingTop = 0;
}

// ��������  
void carArrives(ParkingLot* lot, int id) {
    if (lot->top < MAX_CARS) {
        // ͣ����δ����ֱ��ͣ��  
        Car newCar = { id, time(NULL), 0 }; // ʹ�õ�ǰʱ����Ϊ����ʱ��  
        lot->cars[lot->top++] = newCar;
        printf("Car %d arrived and parked at position %d.\n", id, lot->top);
    }
    else {
        // ͣ��������������ȴ�����  
        Car newCar = { id, time(NULL), 0 };
        lot->waitingQueue[lot->waitingTop++] = newCar;
        printf("Car %d arrived and is waiting in queue.\n", id);
    }
}

// �����뿪  
void carLeaves(ParkingLot* lot, int id) {
    int pos = -1;
    for (int i = 0; i < lot->top; i++) {
        if (lot->cars[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        // ����ͣ��ʱ��  
        lot->cars[pos].duration = time(NULL) - lot->cars[pos].arrival;
        printf("Car %d left after %d seconds and paid for its stay.\n", id, lot->cars[pos].duration);

        // ������ĳ���ǰ�ƶ�  
        for (int i = pos; i < lot->top - 1; i++) {
            lot->cars[i] = lot->cars[i + 1];
        }
        lot->top--;

        // ����еȴ��ĳ��������õȴ����еĵ�һ��������ͣ����  
        if (lot->waitingTop > 0) {
            Car waitingCar = lot->waitingQueue[0];
            lot->cars[lot->top++] = waitingCar;
            printf("Car %d from the waiting queue entered the lot.\n", waitingCar.id);
            lot->waitingTop--;
        }
    }
    else {
        printf("Car %d not found in the lot.\n", id);
    }
}

int main() {
    srand(time(NULL)); // ��ʼ�������������  

    ParkingLot lot;
    initParkingLot(&lot);

    // ģ�⳵��������뿪  
    for (int i = 1; i <= 2 * MAX_CARS; i++) {
        carArrives(&lot, i);

        // ���ѡ��һ�����뿪  
        if (rand() % 2 == 0 && lot.top > 0) {
            int leaveCarId = rand() % lot.top + 1; // �����뿪�ĳ���ID��1����ǰtop֮��  
            carLeaves(&lot, leaveCarId);
        }
    }

    return 0;
}