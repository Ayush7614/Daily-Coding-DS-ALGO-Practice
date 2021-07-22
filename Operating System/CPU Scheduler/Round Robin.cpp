// TO RUN: g++ -o CPU-Scheduling CPU-Scheduling.cpp && ./CPU-Scheduling
//Test Case:
//RoundRobin 2 get_array A 3 0 B 4 7 C 9 0 D 0 2 E 7 6 exit calculate show exit


#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>


class Process
{
    public:
        char processID;
        float brustTime;
        float arrivalTime;
        float got_cpu_at;
        float completion_time;
        float waiting_time;
        float turn_around_time;
        float response_time;
        Process(char PID = '\0', float BT = 0, float AT = 0) 
        {
            processID = PID;
            brustTime = BT;
            arrivalTime = AT;
            got_cpu_at = completion_time = waiting_time  = turn_around_time = response_time = -1;
        }
};


//This Function is used to sort the vector arr
bool comparison(const Process &i, const Process &j)
{
    return (i.arrivalTime < j.arrivalTime)? true:false;
}

class Scheduler
{
    protected:
        std::vector<Process> arr;
        std::vector<Process> sort()
        {
            std::vector<Process> Queue;
            std::vector<Process> vec = arr;
            std::sort(vec.begin(), vec.end(), comparison);
            for(int i=0; i<vec.size(); i++)
                Queue.push_back(vec[i]);
            return Queue;
        }
    public:
        void get_array();
        void show();
        virtual void calculate() = 0;
        virtual void printGantChart() = 0;
};

class RoundRobin : public Scheduler
{
    private:
        std::vector<Process> GantChart;
        std::queue<Process> Arrivals;
        int TimeQuantum;
    public:
        void calculate();
        RoundRobin(int TQ = 2){TimeQuantum = TQ;}
        void printGantChart()
        {
            for(int i=0; i<GantChart.size(); i++)
                std::cout<<GantChart[i].processID<<" ";
            std::cout<<"\n";
        }
};

int main()
{
    char command[20];
    Scheduler *Sc;
    int TQ;
    while(1)
    {
        std::cout<<"command: ";
        std::cin>>command;
        if(!strcmp(command, "exit"))
            break;
        else if(!strcmp(command, "RoundRobin"))
        {
            std::cout<<"Time Quantum (ms): ";
            std::cin>>TQ;
            Sc = new RoundRobin(TQ);
        }
        else if(!strcmp(command, "get_array"))
            Sc->get_array();
        else if(!strcmp(command, "show"))
            Sc->show();
        else if(!strcmp(command, "calculate"))
            Sc->calculate();
        else if(!strcmp(command, "GantChart"))
            Sc->printGantChart();
    }
    return 0;
}

void Scheduler::get_array()
{
    char PID;
    int BT, AT;
    std::string str;
    std::cout<<"Type exit to quit entering\n";
    std::cout<<"PID BT AT\n";
    while(1)
    {
        std::cin>>str;
        if(str == "exit")
            break;
        PID = str[0];
        std::cin>>BT>>AT;
        arr.push_back(*(new Process(PID, BT, AT)));
    }
}

void Scheduler::show()
{
    std::cout<<"PID"<<std::setw(4)<<std::right
             <<"BT"<<std::setw(5)<<std::right
             <<"AT"<<std::setw(5)<<std::right
             <<"CT"<<std::setw(5)<<std::right
             <<"WT"<<std::setw(5)<<std::right
             <<"TAT"<<std::setw(5)<<std::right
             <<"RT\n";
    for(int i=0; i<arr.size(); i++)
    {
        std::cout<<arr[i].processID<<std::setw(5)<<std::right
                <<arr[i].brustTime<<std::setw(5)<<std::right
                <<arr[i].arrivalTime<<std::setw(5)<<std::right
                <<arr[i].completion_time<<std::setw(5)<<std::right
                <<arr[i].waiting_time<<std::setw(5)<<std::right
                <<arr[i].turn_around_time<<std::setw(5)<<std::right
                <<arr[i].response_time<<"\n";
    }
}

void RoundRobin::calculate()
{
    int time = -1;
    std::vector<Process> ready_queue = sort();
    std::vector<Process> new_bt = arr;
    bool done = false;
    Process *front = NULL;
    while(!done)
    {
        done = true;
        time++;
        while(ready_queue.size() > 0 && ready_queue[0].arrivalTime <= time)
        { 
            Arrivals.push(ready_queue[0]);
            ready_queue.erase(ready_queue.begin());
        }
        if(front) Arrivals.push(*front);
        front = NULL;
        if(!Arrivals.empty())//Arrivals.front() != NULL
        {
            if(Arrivals.front().brustTime > TimeQuantum)
            {
                front = &Arrivals.front();
                GantChart.push_back(*front);
                front->brustTime -= TimeQuantum;
                //in case Process faces cpu for 1st time
                if(front->got_cpu_at == -1) front->got_cpu_at = time;
                for(int i=0; i<arr.size(); i++)
                    if(Arrivals.front().processID == arr[i].processID)
                    {
                        new_bt[i].brustTime -= TimeQuantum;
                        break;
                    }
                time += TimeQuantum;
                Arrivals.pop();
            }
            else
            {
                GantChart.push_back(Arrivals.front());
                time += Arrivals.front().brustTime;
                Arrivals.front().brustTime = 0;
                for(int i=0; i<arr.size(); i++)
                    if(Arrivals.front().processID == arr[i].processID)
                    {
                        front = &arr[i];
                        new_bt[i].brustTime = 0;
                        break;
                    }
                front->completion_time = time;
                front->got_cpu_at = Arrivals.front().got_cpu_at;
                Arrivals.pop();
                front = NULL;
            }
            time--;
        }
        for(int i=0; i<new_bt.size(); i++)
            if(new_bt[i].brustTime > 0)
            {
                done = false;
                break;
            }
    }
    for(int i=0; i<arr.size(); i++)
    {
        arr[i].waiting_time = arr[i].completion_time - arr[i].brustTime - arr[i].arrivalTime;
        arr[i].turn_around_time = arr[i].waiting_time + arr[i].brustTime;
        arr[i].response_time = arr[i].got_cpu_at - arr[i].arrivalTime;
    }
}