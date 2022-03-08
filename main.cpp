#include <iostream>
using namespace std;
class Process
{
public:
    int ArrivalTime,WaitTime,BrustTime,ProcessNo,Priority,TR;
    bool flag;

    Process()
    {
        ArrivalTime=0;
        WaitTime=0;
        BrustTime=0;
        ProcessNo=0;
        Priority=0;
        TR=0;

        flag= false;
    }
    void init(int i);
    void Print();
};
void Process::init(int i)
{
    ArrivalTime=0;
    cout<<"Enter Priority of P["<<i<<"]:";
    cin>>Priority;
    cout<<"Enter BrustTime of P["<<i<<"]:";
    cin>>BrustTime;
    ProcessNo=i;
    flag= false;
}

Process Sort(Process P[],int N)
{
    int n=0;
    for(int i=0;i<N-1;i++)
    {
        n=i;
        for(int j=1;j<N;j++)
        {
            if(P[i].Priority>P[n].Priority)
            {
                int A1,A2,B1,B2,P1,P2,f1,f2,PR1,PR2;
                A1=P[i].ArrivalTime;
                B1=P[i].BrustTime;
                P1=P[i].ProcessNo;
                PR1=P[i].Priority;
                f1=P[i].flag;
                A2=P[n].ArrivalTime;
                B2=P[n].BrustTime;
                P2=P[n].ProcessNo;
                PR2=P[n].Priority;
                f2=P[n].flag;
                P[i].ArrivalTime=A2;
                P[i].BrustTime=B2;
                P[i].ProcessNo=P2;
                P[i].flag=f2;
                P[i].Priority=PR2;
                P[n].ArrivalTime=A1;
                P[n].BrustTime=B1;
                P[n].ProcessNo=P1;
                P[n].flag=f1;
                P[n].Priority=PR1;
            }
            n++;
        }
    }
    return *P;
}
Process Average(Process P[],int N) {

    float Maxtime = 0, TotalTime = 0, TurnTime = 0, Av = 0;
    for (int i = 0; i < N; i++) {
        if (Maxtime == 0) {
            for (int j = 0; j < N; ++j) {
                {
                    if (P[j].ArrivalTime == 0) {
                        if (j == 0) {
                            P[j].WaitTime = P[j].ArrivalTime;
                            P[j].TR=P[j].BrustTime;
                            Maxtime = Maxtime + P[j].BrustTime;
                            P[j].flag = true;

                        }
                    }
                }
            }
            if (Maxtime > 0) {
                for (int j = 0; j < N; ++j) {
                    if (P[j].ArrivalTime <= Maxtime && !P[j].flag) {
                        P[j].WaitTime = Maxtime - P[j].ArrivalTime;
                        Maxtime = Maxtime + P[j].BrustTime;
                        P[j].TR=P[j-1].TR+P[j].BrustTime;
                        P[j].flag = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        TotalTime=TotalTime+P[i].WaitTime;
    }
    TurnTime=(TotalTime+Maxtime)/N;
    Av=TotalTime/N;
    cout<<endl;
    cout<<endl;
    cout<<"Your Average Wait time is : "<<Av<<endl;
    cout<<"Your Turnaround Time is : "<<TurnTime<<endl;
    cout<<endl;
    cout<<endl;
    return *P;
}
void Process::Print()
{
    cout<<ProcessNo<<"                  "<<Priority<<"                     "<<BrustTime<<"                  "<<WaitTime<<"                 "<<TR<<endl;
}
int main() {
    int N;
    cout<<"Enter Number of Processes : ";
    cin>>N;
    Process P[N];
    for (int i = 0; i < N; ++i) {
        P[i].init(i);
    }
    Sort(P,N);
    Average(P,N);
    cout<<endl;
    cout<<"Process No"<<"         "<<"Priority"<<"           "<<"BrustTime"<<"            "<<"WaitingTime"<<"       "<<"TurnAround Time"<<endl;
    for (int i = 0; i < N; ++i) {
        P[i].Print();
    }
    return 0;
}