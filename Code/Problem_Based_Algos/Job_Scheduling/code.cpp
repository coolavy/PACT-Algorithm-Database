#include "bits/stdc++.h"
using namespace std;

struct tasks {int deadline, processing_time;};

int n;
vector<tasks> job_list;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // sort by deadline
    sort(begin(tasks), end(tasks));

    int current_time = 0;
    int total_lateness = 0;

    // schedule jobs
    for (const tasks& job : job_list) {
        current_time += job.processing_time;
        int lateness = current_time - job.deadline;
        total_lateness += max(0, lateness);
    }

    cout << total_lateness << "\n";
}