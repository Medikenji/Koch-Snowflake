#include "raylib.h"  
#include <vector>  
#include <cmath>
#include <iostream>

class LineSegment  
{  
public:
    Vector2 a;
    Vector2 b;

  LineSegment(Vector2 a, Vector2 b)  
  {  
      this->a = a;  
      this->b = b;  
  };  
  ~LineSegment() {};

  void draw() {  
      DrawLine(a.x, a.y, b.x, b.y, WHITE);  
  };  

  std::vector<LineSegment*> generate()  
  {
      LineSegment* segmentArray[4];

        Vector2 v = { (b.x - a.x), (b.y - a.y) };
	  v = { v.x / 3, v.y / 3 };

	  // Segment 0
	  Vector2 b1 = { a.x + v.x, a.y + v.y };
	  segmentArray[0] = new LineSegment(a, b1);

      // Segment 3
      Vector2 a1 = { b.x - v.x, b.y - v.y };
      segmentArray[3] = new LineSegment(a1, b);

	  // Segment 1
      float angleRad = -PI/3;
      float cosA = std::cos(angleRad);
      float sinA = std::sin(angleRad);
      Vector2 vRot = { v.x * cosA - v.y * sinA, v.x * sinA + v.y * cosA };
      Vector2 c = { b1.x + vRot.x, b1.y + vRot.y };
	  segmentArray[1] = new LineSegment(b1, c);
	  segmentArray[2] = new LineSegment(c, a1);

      std::vector<LineSegment*> segments;
	  for (int i = 0; i < 4; i++)
	  {
		  segments.push_back(segmentArray[i]);
	  }
      return segments;  
  }  
};