//
// Created by lukemartinlogan on 7/7/23.
//

#ifndef SCS_TUTORIAL_3_4_BASICS_SRC_EASY_SINGLETON_H_
#define SCS_TUTORIAL_3_4_BASICS_SRC_EASY_SINGLETON_H_

#include <mutex>

namespace scs {

/**
 * A class to represent singleton pattern
 * Does not require specific initialization of the static variable
 * */
template<typename T>
class EasySingleton {
 protected:
  /** static instance. */
  static T* obj_;
  static std::mutex lock_;

 public:
  /**
   * Uses unique pointer to build a static global instance of variable.
   * @tparam T
   * @return instance of T
   */
  template<typename ...Args>
  static T* GetInstance(Args&& ...args) {
    if (obj_ == nullptr) {
      lock_.lock();
      if (obj_ == nullptr) {
        obj_ = new T(std::forward<Args>(args)...);
      }
      lock_.unlock();
    }
    return obj_;
  }
};
template <typename T>
T* EasySingleton<T>::obj_ = nullptr;
template <typename T>
std::mutex EasySingleton<T>::lock_;

}  // namespace scs

#endif //SCS_TUTORIAL_3_4_BASICS_SRC_EASY_SINGLETON_H_
