#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1e9;

struct Point {
    double X, Y;

    Point(int x = 0, int y = 0) : X(x), Y(y) {

    }

    bool operator<(const Point& a) const {
        if (X == a.X) {
            return Y < a.Y;
        }
        return X < a.X;
          
    }
};

bool check(Point a, double k, double b) {
    return a.Y >= (k * a.X + b);
}

double dist(Point a, Point b) {
    return abs(a.X - b.X + a.Y + b.Y);
}

set<Point> f(set<Point>& points, bool l) {
    if (points.size() <= 2) 
        return points;

    Point pMax(-INF, -INF), pMin(INF, INF);

    for (auto& point : points) {
        pMax.X = max(pMax.X, point.X);
        pMax.Y = max(pMax.Y, point.Y);

        pMin.X = min(pMin.X, point.X);
        pMin.Y = min(pMin.Y, point.Y);
    }

    Point a = *points.begin(), b;

    for (auto& point : points) {

    }

    double k = (double)(b.Y - a.Y) / (b.X - a.X), c = b.Y - k * b.X;

    set<Point> temp;

    for (auto it = points.begin(); it != points.end(); ) {
        if (check(*it, k, c) == l) {
            temp.insert(*it);
            it = points.erase(it);
        }
        else {
            ++it;
        }
    }

    // set<Point> ans;
    // ans.insert(a);
    // ans.insert(b);

    // for (auto& el : f(temp, l)) {
    //     ans.insert(el);
    // }

    // for (auto& el : temp) {
    //     points.insert(el);
    // }

    cout << "--->" << temp.size() << ' ' << points.size() << '\n';

    cout << a.X << ' ' << a.Y << ' ' << b.X << ' ' << b.Y << '\n';

    cout << k << ' ' << c << '\n';

    return points;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;

    cin >> n;
    set<Point> points;

    for (int i = 0; i < n; ++i) {
        Point a;
        cin >> a.X >> a.Y;
        points.insert(a);
    }

    //auto l = f(points, true);
    auto r = f(points, false);

    for (auto& el : r) {
        cout << el.X << ' ' << el.Y << '\n';
    }

    return 0;
}