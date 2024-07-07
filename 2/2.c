#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#include <time.h>  

#define MAX_CARS 10 // 假设停车场最多能停放10辆车  

// 汽车结构体  
typedef struct {
    int id;         // 车辆ID  
    int arrival;    // 到达时间  
    int duration;   // 停留时间  
} Car;

// 停车场结构体  
typedef struct {
    Car cars[MAX_CARS]; // 停车场内的车辆  
    int top;            // 停车场内当前车辆数量  
    Car waitingQueue[MAX_CARS]; // 等待队列  
    int waitingTop;           // 等待队列中的车辆数量  
} ParkingLot;

// 初始化停车场  
void initParkingLot(ParkingLot* lot) {
    lot->top = 0;
    lot->waitingTop = 0;
}

// 车辆到达  
void carArrives(ParkingLot* lot, int id) {
    if (lot->top < MAX_CARS) {
        // 停车场未满，直接停车  
        Car newCar = { id, time(NULL), 0 }; // 使用当前时间作为到达时间  
        lot->cars[lot->top++] = newCar;
        printf("Car %d arrived and parked at position %d.\n", id, lot->top);
    }
    else {
        // 停车场已满，进入等待队列  
        Car newCar = { id, time(NULL), 0 };
        lot->waitingQueue[lot->waitingTop++] = newCar;
        printf("Car %d arrived and is waiting in queue.\n", id);
    }
}

// 车辆离开  
void carLeaves(ParkingLot* lot, int id) {
    int pos = -1;
    for (int i = 0; i < lot->top; i++) {
        if (lot->cars[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        // 计算停留时间  
        lot->cars[pos].duration = time(NULL) - lot->cars[pos].arrival;
        printf("Car %d left after %d seconds and paid for its stay.\n", id, lot->cars[pos].duration);

        // 将后面的车向前移动  
        for (int i = pos; i < lot->top - 1; i++) {
            lot->cars[i] = lot->cars[i + 1];
        }
        lot->top--;

        // 如果有等待的车辆，则让等待队列的第一辆车进入停车场  
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
    srand(time(NULL)); // 初始化随机数生成器  

    ParkingLot lot;
    initParkingLot(&lot);

    // 模拟车辆到达和离开  
    for (int i = 1; i <= 2 * MAX_CARS; i++) {
        carArrives(&lot, i);

        // 随机选择一辆车离开  
        if (rand() % 2 == 0 && lot.top > 0) {
            int leaveCarId = rand() % lot.top + 1; // 假设离开的车辆ID在1到当前top之间  
            carLeaves(&lot, leaveCarId);
        }
    }

    return 0;
}