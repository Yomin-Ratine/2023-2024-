#include <stdio.h>
#pragma warning(disable:4996)
int window[4];
//客流量
int MaxCustomerFlow=0;
int MinCustomerFlow=0;

int TotalCustomers=0;
//等待时长
int TotalWaitTime=0;
int CurrentTime=0;
//服务时长
int TotalServiceTime=0;
int MaxServiceTime=0;
int MinServiceTime=0;

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
int ChooseArray(){
    int min=0;
    int ChooseWindow=0;
    if(window[0]==0&&window[1]==0&&window[2]==0&&window[3]==0){
        window[0]++;
    }else{
        min=find_min(window,4);
        window[min]++;
    }
    return min;
}
void CalcWaitTime(int windowIndex){
    int WaitTime=0;//这个地方要先计算当前队列前面的人操作的时间
    WaitTime+=Operate(CurrentTime,windowIndex);
    TotalWaitTime+=WaitTime;
}
int Operate(int CurrentTime,int WindowIndex){
    int Randnumber=GenerateRandomNumber(MaxServiceTime,MinServiceTime);
    TotalServiceTime+=Randnumber;
    TotalCustomers++;
    window[WindowIndex]--;
    return Randnumber;
}
double mabs(double n) {
    if (n >= 0.0) return n;
    else return -n;
}
int main(){
    TotalCustomers=0;//初始化客户总数
    TotalWaitTime=0;//初始化总等待时间

    int ArrivalRate=4;//每分钟到达的客户数
    printf("请输入银行营业的时间(分钟)：");
    scanf("%d",&TotalServiceTime);
    printf("客流量范围(位)(最小值-最大值)：");
    scanf("%d-%d",&MinServiceTime,&MaxServiceTime);
    printf("请输入每个客户服务时长范围(分钟)(最小值-最大值)：");
    scanf("%d-%d",&MinServiceTime,&MaxServiceTime);
    Start:
    while(CurrentTime<=TotalServiceTime){

        CalcWaitTime(ChooseArray());
        Operate(CurrentTime,ChooseArray());
    }
    double result=(double)(TotalWaitTime+TotalServiceTime)/TotalCustomers;
    printf("一天中客户在银行逗留的平均时间(分钟)：%lf",mabs(result));
    return 0;
}