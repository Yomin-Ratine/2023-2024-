#include <stdio.h>
#pragma warning(disable:4996)
int window[4];
//������
int MaxCustomerFlow=0;
int MinCustomerFlow=0;

int TotalCustomers=0;
//�ȴ�ʱ��
int TotalWaitTime=0;
int CurrentTime=0;
//����ʱ��
int TotalServiceTime=0;
int MaxServiceTime=0;
int MinServiceTime=0;

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
    int WaitTime=0;//����ط�Ҫ�ȼ��㵱ǰ����ǰ����˲�����ʱ��
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
    TotalCustomers=0;//��ʼ���ͻ�����
    TotalWaitTime=0;//��ʼ���ܵȴ�ʱ��

    int ArrivalRate=4;//ÿ���ӵ���Ŀͻ���
    printf("����������Ӫҵ��ʱ��(����)��");
    scanf("%d",&TotalServiceTime);
    printf("��������Χ(λ)(��Сֵ-���ֵ)��");
    scanf("%d-%d",&MinServiceTime,&MaxServiceTime);
    printf("������ÿ���ͻ�����ʱ����Χ(����)(��Сֵ-���ֵ)��");
    scanf("%d-%d",&MinServiceTime,&MaxServiceTime);
    Start:
    while(CurrentTime<=TotalServiceTime){

        CalcWaitTime(ChooseArray());
        Operate(CurrentTime,ChooseArray());
    }
    double result=(double)(TotalWaitTime+TotalServiceTime)/TotalCustomers;
    printf("һ���пͻ������ж�����ƽ��ʱ��(����)��%lf",mabs(result));
    return 0;
}