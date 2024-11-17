#include <iostream>
#include <climits>

using namespace std;

struct Task
{
    int start;
    int end;
};

void sortTasks(Task tasks[], int n)
{
    for (int i = 0; i < n - 1; i++)
	{
        for (int j = 0; j < n - i - 1; j++)
		{
            if (tasks[j].start > tasks[j + 1].start)
			{
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

int minMachines(Task tasks[], int n)
{
    int machineEndTimes[100];  
    for (int i = 0; i < 100; i++)
	{
        machineEndTimes[i] = INT_MAX;  
    }

    int machineCount = 0;
    for (int i = 0; i < n; i++)
	{
        bool assigned = false;

        for (int j = 0; j < machineCount; j++)
		{
            if (machineEndTimes[j] <= tasks[i].start)
			{
                machineEndTimes[j] = tasks[i].end;
                assigned = true;
                break;
            }
        }

        if (!assigned)
		{
            machineEndTimes[machineCount] = tasks[i].end;
            machineCount++;
        }
    }

    return machineCount;  
}

int main()
{
   
    const int n = 5;
    Task tasks[n] = {
        {1, 4}, {2, 5}, {3, 7}, {5, 8}, {6, 9}
    };

    sortTasks(tasks, n);
    int result = minMachines(tasks, n);
    cout << "Minimum number of machines required: " << result << endl;

    return 0;
}



