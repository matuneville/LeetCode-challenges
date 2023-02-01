#include "iostream"
using namespace std;

int computeArea (int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area_A = abs(ax1 - ax2) * abs(ay1 - ay2);
    int area_B = abs(bx1 - bx2) * abs(by1 - by2);
    int areaIntersection = 0;

    int ix1 = max(ax1,bx1); // left side of intersection
    int iy1 = max(ay1,by1); // bottom side of intersection
    int ix2 = min(ax2,bx2); // right side of intersection
    int iy2 = min(ay2,by2); // top side of intersection

    if(ix2 > ix1 && iy2 > iy1)
        areaIntersection = ((ix1-ix2)*(iy1-iy2));
        
    return area_A + area_B - areaIntersection;
}

int main (){
    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -1, by1 = -1, bx2 = 1, by2 = 1;
    cout << computeArea(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);
    return 0;
}