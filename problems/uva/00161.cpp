#include <cstdio>
#include <cstring>
#include <cstdlib>

int pick_one(int *cycle_times, int *counter_arr, int len) {
    int min = 2 * cycle_times[0] * (counter_arr[0] + 1),
        index = 0;
    for (int i = 1; i < len; i++) {
        if (min > 2 * cycle_times[i] * (counter_arr[i] + 1)) {
            min = 2 * cycle_times[i] * (counter_arr[i] + 1);
            index = i;
        }
    }
    counter_arr[index] += 1;

    return min;
}

bool all_green(int cur_time, int *cycle_times, int len) {
    for (int i = 0; i < len; i++) {
        int rem = cur_time % (2 * cycle_times[i]);
        if (rem >= cycle_times[i] - 5) {
            return false;
        }
    }
    return true;
}

void print_time(int time) {
    if (time > 18000)
        printf("Signals fail to synchronise in 5 hours\n");
    else {
        int hours = time / 3600,
            minutes = time % 3600 / 60,
            seconds = time % 60;
        printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    }
}

void solve(int *times, int *counter, int n) {
    for (int i = 0; i < n; i++) {
        counter[i] = 0;
    }

    int cur_time;
    do {
        cur_time = pick_one(times, counter, n);
    } while (cur_time <= 18000 && !all_green(cur_time, times, n));

    print_time(cur_time);
}

int main() {
    char line[105];
    int times[105], counter[105];
    int n = 0;

    while (fgets(line, 104, stdin) != NULL) {
        if (!strcmp("0 0 0\n", line))
            break;
        for (char *tok = strtok(line, " \n");
                tok != NULL; tok = strtok(NULL, " ")) {
            int t = atoi(tok);
            if (t == 0) {
                solve(times, counter, n);
                n = 0;
            } else {
                times[n++]  = t;
            }
        }
    }

    return 0;
}
