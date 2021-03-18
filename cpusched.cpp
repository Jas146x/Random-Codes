#include <bits/stdc++.h>
using namespace std;
void fcfs(int process[], int at[], int bt[], int n)
{
    int i, j, time, wt[n], queue[n];
    float awt = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                int t = at[j];
                at[j] = at[j + 1];
                at[j + 1] = t;

                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = process[j];
                process[j] = process[j + 1];
                process[j + 1] = t;
            }
        }
    }

    time = 0;
    for (i = 0; i < n; i++)
    {
        if (time < at[i])
            time += at[i] + bt[i];
        else
            time += bt[i];

        wt[i] = time - at[i] - bt[i];
        awt += wt[i];
        queue[i] = process[i];
    }

    awt /= n;

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\n";
    }

    cout << "Average Waiting Time: " << awt << "\n";

    cout << "Execution Queue: ";
    for (i = 0; i < n; i++)
    {
        cout << "P" << queue[i] << "->";
    }
    cout << "\b\b";
}

void sjf(int process[], int at[], int bt[], int n)
{
    int i, temp, val, mat[n][6];
    float awt = 0;

    for (i = 0; i < n; i++)
    {
        mat[i][0] = process[i];
        mat[i][1] = at[i];
        mat[i][2] = bt[i];
    }

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mat[j][1] > mat[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                {
                    int t = mat[j][k];
                    mat[j][k] = mat[j + 1][k];
                    mat[j + 1][k] = t;
                }
            }
        }
    }

    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];

    for (int i = 1; i < n; i++)
    {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        for (int j = i; j < n; j++)
        {
            if (temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for (int k = 0; k < 6; k++)
        {
            swap(mat[val][k], mat[i][k]);
        }
    }

    for (i = 0; i < n; i++)
    {
        awt += mat[i][4];
    }
    awt /= n;

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\n";
    for (i = 0; i < n; i++)
    {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t\t" << mat[i][2] << "\t\t" << mat[i][4] << "\n";
    }

    cout << "Average Waiting Time: " << awt << "\n";

    cout << "Execution Queue: ";
    for (i = 0; i < n; i++)
    {
        cout << "P" << mat[i][0] << "->";
    }
    cout << "\b\b";
}

void srtf(int process[], int at[], int bt[], int n)
{
    int i, j = 0, k, q, count = 0, time, wt[n], temp[n], queue[100];
    float awt = 0;

    for (i = 0; i < n; i++)
    {
        temp[i] = bt[i];
    }
    temp[9] = INT_MAX;

    cout << "Enter time quantum: ";
    cin >> q;

    for (time = 0; count < n; time += q)
    {
        k = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && temp[i] < temp[k] && temp[i] > 0)
            {
                k = i;
            }
        }
        temp[k]--;
        if (queue[j - 1] != process[k])
            queue[j++] = process[k];
        if (temp[k] == 0)
        {
            count++;

            wt[k] = time + 1 - at[k] - temp[k];
            awt += wt[k];
        }
    }

    awt /= n;

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\n";
    }

    cout << "Average Waiting Time: " << awt << "\n";

    cout << "Execution Queue: ";
    for (i = 0; i < j; i++)
    {
        cout << "P" << queue[i] << "->";
    }
    cout << "\b\b";
}

void priority(int process[], int bt[], int n)
{
    int i, j, priority[n], wt[n];
    float awt = 0;
    cout << "Enter priority number of each process\n";
    for (i = 0; i < n; i++)
    {
        cin >> priority[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (priority[j] > priority[j + 1])
            {
                int t = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = t;

                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = process[j];
                process[j] = process[j + 1];
                process[j + 1] = t;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        awt += wt[i];
    }
    awt /= n;

    cout << "Process\tPriority Number\tBurst Time\tWaiting Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << priority[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\n";
    }

    cout << "Average Waiting Time: " << awt << "\n";

    cout << "Execution Queue: ";
    for (i = 0; i < n; i++)
    {
        cout << "P" << process[i] << "->";
    }
    cout << "\b\b";
}

void roundRobin(int process[], int at[], int bt[], int n)
{
    int i, j, time, flag, q, count, temp_bt[n], wt[n], queue[100];
    float awt;
    count = n;
    time = flag = j = awt = 0;
    for (i = 0; i < n; i++)
    {
        temp_bt[i] = bt[i];
    }

    cout << "Enter the value of time quantum: ";
    cin >> q;
    i = 0;
    while (count > 0)
    {
        if (temp_bt[i] <= q && temp_bt[i] > 0)
        {
            time += temp_bt[i];
            temp_bt[i] = 0;
            flag = 1;
            if (queue[j - 1] != process[i])
                queue[j++] = process[i];
        }
        else if (temp_bt[i] > 0)
        {
            temp_bt[i] = temp_bt[i] - q;
            time += q;
            if (queue[j - 1] != process[i])
                queue[j++] = process[i];
        }

        if (temp_bt[i] == 0 && flag == 1)
        {
            count--;
            wt[i] = time - at[i] - bt[i];
            awt += wt[i];
            flag = 0;
        }

        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= time)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    awt /= n;

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\n";
    }

    cout << "Average Waiting Time: " << awt << "\n";

    cout << "Execution Queue: ";
    for (i = 0; i < j; i++)
    {
        cout << "P" << queue[i] << "->";
    }
    cout << "\b\b";
}

int main()
{
    int n, i, ch;

    do
    {
        cout << "\n1. FCFS Scheduling\n";
        cout << "2. SJF Scheduling\n";
        cout << "3. SRTF Scheduling\n";
        cout << "4. Priority Scheduling\n";
        cout << "5. Round Robin Scheduling\n";
        cout << "6. Exit\n";
        cout << "Enter option: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
        {
            cout << "Enter no of processes: ";
            cin >> n;
            int process[n], bt[n], at[n];

            cout << "Enter Process numbers: ";
            for (i = 0; i < n; i++)
                cin >> process[i];
            cout << "Enter Arrival Time: ";
            for (i = 0; i < n; i++)
                cin >> at[i];
            cout << "Enter Burst Time: ";
            for (i = 0; i < n; i++)
                cin >> bt[i];

            fcfs(process, at, bt, n);
        }
        break;
        case 2:
        {
            cout << "Enter no of processes: ";
            cin >> n;
            int process[n], bt[n], at[n];

            cout << "Enter Process numbers: ";
            for (i = 0; i < n; i++)
                cin >> process[i];
            cout << "Enter Arrival Time: ";
            for (i = 0; i < n; i++)
                cin >> at[i];
            cout << "Enter Burst Time: ";
            for (i = 0; i < n; i++)
                cin >> bt[i];

            sjf(process, at, bt, n);
        }
        break;
        case 3:
        {
            cout << "Enter no of processes: ";
            cin >> n;
            int process[n], bt[n], at[n];

            cout << "Enter Process numbers: ";
            for (i = 0; i < n; i++)
                cin >> process[i];
            cout << "Enter Arrival Time: ";
            for (i = 0; i < n; i++)
                cin >> at[i];
            cout << "Enter Burst Time: ";
            for (i = 0; i < n; i++)
                cin >> bt[i];

            srtf(process, at, bt, n);
        }
        break;
        case 4:
        {
            cout << "Enter no of processes: ";
            cin >> n;
            int process[n], bt[n], at[n];

            cout << "Enter Process numbers: ";
            for (i = 0; i < n; i++)
                cin >> process[i];
            cout << "Enter Burst Time: ";
            for (i = 0; i < n; i++)
                cin >> bt[i];

            priority(process, bt, n);
        }
        break;
        case 5:
        {
            cout << "Enter no of processes: ";
            cin >> n;
            int process[n], bt[n], at[n];

            cout << "Enter Process numbers: ";
            for (i = 0; i < n; i++)
                cin >> process[i];
            cout << "Enter Arrival Time: ";
            for (i = 0; i < n; i++)
                cin >> at[i];
            cout << "Enter Burst Time: ";
            for (i = 0; i < n; i++)
                cin >> bt[i];

            roundRobin(process, at, bt, n);
        }
        break;
        default:
            cout << "Invalid Option\n";
            break;
        }
    } while (ch != 6);
}

