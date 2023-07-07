//
// Created by lukemartinlogan on 7/6/23.
//

class Vec2x1 {
 public:
  int x, y;

 public:
  Vec2x1 operator+(const Vec2x1 &other) {
    Vec2x1 result;
    result.x_ = x_ + other.x_;
    result.y_ = y_ + other.y_;
    return result;
  }
};
