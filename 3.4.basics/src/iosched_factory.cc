//
// Created by lukemartinlogan on 7/7/23.
//

#include <memory>

class IoSched {
 public:
  virtual void PushRequest() = 0;
  virtual void PopRequest() = 0;
};

class RoundRobinSched : public IoSched {
 public:
  void PushRequest() override {}
  void PopRequest() override {}
};

class DeadlineSched : public IoSched {
 public:
  DeadlineSched(int a, int b) {}
  void PushRequest() override {}
  void PopRequest() override {}
};

enum class IoSchedType {
  kRoundRobin,
  kDeadline
};

class IoSchedFactory {
 public:
  static std::unique_ptr<IoSched> Get(IoSchedType type) {
    switch (type) {
      case IoSchedType::kRoundRobin: {
        return std::make_unique<RoundRobinSched>();
      }
      case IoSchedType::kDeadline: {
        return std::make_unique<DeadlineSched>(0, 1);
      }
    }
  }
};

int main(int argc, char **argv) {
  IoSchedType sched_type = static_cast<IoSchedType>(std::stoi(argv[1]));
  auto sched = IoSchedFactory::Get(sched_type);
  sched->PushRequest();
  sched->PopRequest();
}