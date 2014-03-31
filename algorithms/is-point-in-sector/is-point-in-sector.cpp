#include<cstdio>
#include<cmath>

const float PI = atan(1) * 4;

bool IsPointInCircularSector(float cx, float cy, float ux, float uy, float r, float theta,
    float px, float py)
{
    // D = P - C
    float dx = px - cx;
    float dy = py - cy;
 
    // |D| = (dx^2 + dy^2)^0.5
    float length = sqrt(dx * dx + dy * dy);
 
    // |D| > r
    if (length > r)
        return false;
 
    // Normalize D
    dx /= length;
    dy /= length;
 
    // acos(D dot U) < theta
    printf("alpha=%f, theta=%f\n", acos(dx * ux + dy * uy), theta);
    return acos(dx * ux + dy * uy) < theta;
}

int main() {
    bool in = IsPointInCircularSector(0.0, 0.0, 0.0, 1.0, 1.0, PI / 2, 0.0, -1.0);
    printf("in = %d\n", in);

    return 0;
}
