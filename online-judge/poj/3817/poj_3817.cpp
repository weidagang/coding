#include <cstdio>
#include <cmath>

const int N = 1000;
const int MAX_COST = 1000 * 100 + 1;

struct Point {
    int x;
    int y;
    int p;
    double c; //min cost
};

int n;
Point points[N + 2];
int penalties[N + 2];

void init() {
    points[0].x = 0;
    points[0].y = 0;
    points[0].p = 0;
    points[0].c = 0.0;

    points[n+1].x = 100;
    points[n+1].y = 100;
    points[n+1].p = 0;
    points[n+1].c = MAX_COST;

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].p);
        //printf("%d %d %d\n", points[i].x, points[i].y, points[i].p);
        points[i].c = MAX_COST;
    }
    
    penalties[0] = 0;
    for (int i = 1; i < n + 2; ++i) {
        penalties[i] = penalties[i-1] + points[i].p; 
    }
}

int main() {
    while (true) {
        scanf("%d", &n);

        if (n <= 0) {
            break;
        }
        
        init();

        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                double penalty = penalties[i-1] - penalties[j];
                double distance = sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x) + (points[i].y-points[j].y)*(points[i].y-points[j].y));
                double stay = 1;
                double c = points[j].c + penalty + distance  + stay;

                if (points[i].c - c > 1e-8) {
                    points[i].c = c;
                }
            }
        }

        printf("%.3f\n", points[n+1].c, ((int)(points[n+1].c * 1000 + 0.5)) / 1000.0 );
    }
    return 0;
}
