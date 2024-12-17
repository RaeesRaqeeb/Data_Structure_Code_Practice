#include<iostream>
#include<vector>
#include<string>


using namespace std;

//CLass for each task as node

class Task
{
    public:
            int Task_periority;
            string task_name;
        
        Task(int task, string name)
        {
            Task_periority=task;
            task_name=name;
        }




};


class Periority_queue
{
    public:
            vector<Task> All_tasks;
            int size;

           
            // Periority_queue(int size)
            // {
            //     this->size= size;
            // }

        
//Using max heap
    void heapify_up(int index)
    {
        if(index<=0)return;

        int parent=(index-1)/2;

        if(All_tasks[parent].Task_periority<All_tasks[index].Task_periority)
        {
            swap(All_tasks[index],All_tasks[parent]);
            heapify_up(parent);
        }
    }

    void heapify_down(int index)
    {
        int largest= index;
        int left=index*2+1;
        int right=index*2 +2;

        if(index<=(All_tasks.size()-1) && All_tasks[left].Task_periority > All_tasks[largest].Task_periority)
            largest=left;

        if(index <=(All_tasks.size()-1)   && All_tasks[right].Task_periority > All_tasks[largest].Task_periority)
            largest=right;


        if(largest!=index)
        {
            swap(All_tasks[largest],All_tasks[index]);
            heapify_down(largest);
        }

    }

    void insertion(int periority, string name)
    {
        
        Task task1(periority,name);
        All_tasks.push_back(task1);
        // if(All_tasks.size()-1 == 0)
        //     return

        heapify_up(All_tasks.size()-1);

    }


    void First_by_periority()
    {
        if(All_tasks.empty())
        {
            throw runtime_error("The heap is empty!!!!");
        }

        Task deleting_task=All_tasks[0];
        All_tasks[0]=All_tasks.back();
        All_tasks.pop_back();
        heapify_down(0);
        cout<<"\n********************************************"<<endl;
            cout<<"Task name:"<<deleting_task.task_name<<endl;
            cout<<"Task Periority:"<<deleting_task.Task_periority<<endl;
            cout<<"********************************************"<<endl;

    }

    void Remove(int index)
    {
        if(All_tasks.empty())
        {
            throw runtime_error("The heap is empty");
        }

        All_tasks[index]=All_tasks[All_tasks.size()-1];
        All_tasks.pop_back();
        heapify_down(index);

    }

    void Display()
    {
        for(auto i = All_tasks.begin(); i != All_tasks.end(); ++i)
        {
            cout<<"\n********************************************"<<endl;
            cout<<"Task name:"<<i->task_name<<endl;
            cout<<"Task Periority:"<<i->Task_periority<<endl;
            cout<<"********************************************"<<endl;

        }
    }

   void Decreasing_periority(string task_name, int periority_decrease) {
    bool found = false;
    for (size_t i = 0; i < All_tasks.size(); ++i) {
        if (All_tasks[i].task_name == task_name) {
            All_tasks[i].Task_periority -= periority_decrease;
            found = true;
            heapify_down(i);
            cout << "\nThe periority is changed successfully...\n";
            return;
        }
    }
    if (!found) {
        cout << "\nTask not found...\n";
    }
}
     void Increase_periority(string task_name, int periority_increase)
    {
        int i=0;
        bool found=false;
        while(i < All_tasks.size())
        {
            if(All_tasks[i].task_name == task_name)
            {
                All_tasks[i].Task_periority+=periority_increase;
                found=true;
                heapify_up(i);
                cout<<"\nThe periority is changed successfully...\n";
                return;
            }
            i++;
        }
        if(!found)
        {
            cout<<"\n!!!!!!!The task name is not found in the heap!!!!!!!\n"<<endl;
            return;
        }
    }

};


int main(void)
{
    Periority_queue Data;
    
    Data.insertion(1,"Khan");
    Data.insertion(4,"asd");
    Data.insertion(5,"zxc");
    Data.insertion(2,"klj");
    Data.insertion(3,"xch");
    cout<<"Before the Fetching\n";
    Data.Display();
    cout<<"After the Fetching\n";

    // while(!Data.All_tasks.empty())
    // {
    //     Data.First_by_periority();
    // }

    //Decreasing the periority of particular task 

    string task;
    cout<<"Enter the name of the task whose periority you want to increase or decrease:";
    cin>>task;
    cout<<"How much you want to increase the periority from range(1,10):"<<endl;
    int amount;
    cin>>amount;
    cout<<"Want to increace or decrease by the given amount:\n1)Increase\n2)Decrease\n"<<endl;
    int input;
    cin>>input;
    if(input==1)
        Data.Increase_periority(task,amount);
    else 
        Data.Decreasing_periority(task,amount);


    cout<<"\nAfter the periority is changed\n";
    Data.Display();

    cout<<"Removing the task:"<<endl;
    Data.Remove(2);
    Data.Display();


        


    return 0;
}


// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// class Task {
// public:
//     int Task_periority;
//     string Task_name;

//     Task(int p, string n) : Task_periority(p), Task_name(n) {}
// };

// class Periority_queue {
// public:
//     vector<Task> All_tasks;

//     void heapify_up(int index) {
//         if (index <= 0) return;
//         int parent = (index - 1) / 2;

//         if (All_tasks[parent].Task_periority < All_tasks[index].Task_periority) {
//             swap(All_tasks[parent], All_tasks[index]);
//             heapify_up(parent);
//         }
//     }

//     void heapify_down(int index) {
//         int largest = index;
//         int left = index * 2 + 1;
//         int right = index * 2 + 2;

//         if (left < All_tasks.size() && All_tasks[left].Task_periority > All_tasks[largest].Task_periority)
//             largest = left;

//         if (right < All_tasks.size() && All_tasks[right].Task_periority > All_tasks[largest].Task_periority)
//             largest = right;

//         if (largest != index) {
//             swap(All_tasks[largest], All_tasks[index]);
//             heapify_down(largest);
//         }
//     }

// public:
//     void insertion(int p, string n) {
//         Task newTask(p, n);
//         All_tasks.push_back(newTask);
//         heapify_up(All_tasks.size() - 1);
//     }

//     void Display() {
//         for (const auto& task : All_tasks) {
//             cout << "********************************************\n";
//             cout << "Task name: " << task.Task_name << endl;
//             cout << "Task Periority: " << task.Task_periority << endl;
//             cout << "********************************************\n";
//         }
//     }

//     void First_by_periority() {
//         if (!All_tasks.empty()) {
//             cout << "Highest priority task: " << All_tasks.front().Task_name << endl;
//             swap(All_tasks.front(), All_tasks.back());
//             All_tasks.pop_back();
//             heapify_down(0);
//         }
//     }
// };

// int main() {
//     Periority_queue Data;

//     Data.insertion(1, "Khan");
//     Data.insertion(4, "asd");
//     Data.insertion(5, "zxc");
//     Data.insertion(2, "klj");
//     Data.insertion(3, "xch");

//     cout << "Before the Fetching\n";
//     Data.Display();

//     while (!Data.All_tasks.empty()) {
//         Data.First_by_periority();
//     }

//     return 0;
// }