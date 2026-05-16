#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n;

    cin >> n;

    Job jobs[10];

    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    cout << "Job Order:\n";

    for(int i = 0; i < n; i++)
    {
        cout << jobs[i].id << " ";
    }

    return 0;
}