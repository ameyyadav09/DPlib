#include <iostream>
#include <string>
#include <climits>
#include <stdexcept>
#include <set>
#include <cmath>
using namespace std;


double area_of(double x1, double y1, double x2, double y2, double x3, double y3) {
    double area = abs(((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)))/2.0);
    return area;
}

double distance_of(double x1, double y1, double x2, double y2) {
    double distance = sqrt((pow((x2-x1), 2) + pow((y2-y1), 2)));
    return distance;
}
int main() {
	// ios_base::sync_with_stdio (false);
	// cin.tie(NULL)
    double x1, y1, x2, y2, x3, y3;
    double tarea, area1, area2, area3, a, b, c;

    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;

    a = distance_of(x1, y1, x2, y2);
    b = distance_of(x2, y2, x3, y3);
    c = distance_of(x1, y1, x3, y3);
    if ((a+b)>c && (b+c)>a && (a+c)>b) {
        tarea = area_of(x1, y1, x2, y2, x3, y3);
        area1 = area_of(x1, y1, x2, y2, 0, 0);
        area2 = area_of(x2, y2, x3, y3, 0, 0);
        area3 = area_of(x3, y3, x1, y1, 0, 0);

        if((area1 + area2 + area3)  == tarea)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
    else {
        cout << "Invalid" << "\n";
    }
	return 0;
}
