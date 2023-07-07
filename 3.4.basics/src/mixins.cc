//
// Created by lukemartinlogan on 7/7/23.
//

class PrintableMixin {
 public:
  virtual void Print() = 0;
};

class SerializeableMixin {
 public:
  virtual void Serialize() = 0;
};

class Matrix : public PrintableMixin, public SerializeableMixin {
 public:
  void Print() override {}
  void Serialize() override {}
};
