#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000
 
struct Point
{
    int x;
    int y;
};
 
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
 
// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
int main()
{
	Point a,b,c,d,p,q,r,s;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
	cin>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y>>s.x>>s.y;
    Point c1={(a.x+c.x)/2,(a.y+c.y)/2},c2={(p.x+r.x)/2,(p.y+r.y)/2};
	int xmin1=min(a.x,min(b.x,min(c.x,d.x))),xmin2=min(p.x,min(q.x,min(r.x,s.x)));
	int xmax1=max(a.x,max(b.x,max(c.x,d.x))),xmax2=max(p.x,max(q.x,max(r.x,s.x)));
	int ymin1=min(a.y,min(b.y,min(c.y,d.y))),ymin2=min(p.y,min(q.y,min(r.y,s.y)));
	int ymax1=max(a.y,max(b.y,max(c.y,d.y))),ymax2=max(p.y,max(q.y,max(r.y,s.y)));
	Point polygon1[]={{a.x,a.y},{b.x,b.y},{c.x,c.y},{d.x,d.y}};
	Point polygon2[]={{p.x,p.y},{q.x,q.y},{r.x,r.y},{s.x,s.y}};	
	// if(xmin2<=xmin1 && xmax2>=xmax1 && ymin2<=ymin1 && ymax2>=ymax1)
	// 	cout<<"yes";
 //    else if(xmin1<=xmin2 && xmax1>=xmax2 && ymin1<=ymin2 && ymax1>=ymax2)
 //        cout<<"yes";
	if(isInside(polygon1, 4, p) || isInside(polygon1, 4, q) || isInside(polygon1, 4, r) || isInside(polygon1, 4, s) || isInside(polygon2, 4, a) || isInside(polygon2, 4, b) || isInside(polygon2, 4, c) || isInside(polygon2, 4, d) || isInside(polygon1,4,c2) ||  isInside(polygon2,4,c1))
	{
		cout<<"yes";
	}
	else
		cout<<"no";
}