#include <iostream>

template<typename T, typename Alloc = std::allocator<T>>
class Vector {
 private:
  T *arr;
  size_t size_;
  size_t real_size;

 public:
  Vector() {
    real_size = 1;
    size_ = 0;
    arr = new T[real_size];
  }

  Vector(size_t size) {
    real_size = size;
    size_ = size;
    arr = new T[real_size];
  }

  Vector(size_t size, T && elem) {
    real_size = size;
    size_ = size;
    arr = new T[real_size];
    for (int i = 0; i < size_; i++) {
      arr[i] = std::move(elem);
    }
  }

  Vector(size_t size, T &elem) {
    real_size = size;
    size_ = size;
    arr = new T[real_size];
    for (int i = 0; i < size_; i++) {
      arr[i] = elem;
    }
  }

  ~Vector() {
    delete[] arr;
  }

  T* Data() const {
    return arr;
  }

  Vector(Vector &other) {
    size_ = other.size();
    real_size = other.real_size;

    arr = new T[other.real_size];
    for (size_t i = 0; i < other.size(); i++)
      arr[i] = other.arr[i];
  }

  Vector(Vector &&other) {
    size_ = std::move(other.size_);
    real_size = std::move(other.real_size);
    for (int i = 0; i < real_size; i++) {
      arr[i] = std::move(other.arr[i]);
    }
  }

  Vector &operator=(const Vector<T> &other) {
    size_ = other.size();
    real_size = other.real_size;

    arr = new T[other.real_size];
    for (size_t i = 0; i < other.size(); i++)
      arr[i] = other.arr[i];
    return *this;
  }

  Vector &operator=(Vector && other) {
    size_ = std::move(other.size_);
    real_size = std::move(other.real_size);
    for (int i = 0; i < real_size; i++) {
      arr[i] = std::move(other.arr[i]);
    }
    return *this;
  }

  T &operator[](size_t &n) {
    if (n >= size_)
      throw std::out_of_range("Element is out of range");
    return arr[n];
  }

  T &operator[](size_t &&n) {
    if (n >= size_)
      throw std::out_of_range("Element is out of range");
    return arr[n];
  }

  bool operator>(const Vector other) {
    if (size_ != other.size()) return -1;

    for (int i = 0; i < other.size_; i++)
      if (arr[i] <= other[i]) return false;

    return true;
  }

  bool operator<(const Vector other) {
    if (size_ != other.size()) return -1;

    for (int i = 0; i < other.size_; i++)
      if (arr[i] >= other[i]) return false;

    return true;
  }

  bool operator==(const Vector other) {
    if (size_ != other.size()) return false;

    for (int i = 0; i < other.size_; i++)
      if (arr[i] != other[i]) return false;

    return true;
  }

  bool operator!=(const Vector other) {
    return !(other == *this);
  }

  void allocate() {
    auto *m = new T[2 * real_size];
    for (size_t i = 0; i < size_; i++)
      m[i] = arr[i];
    delete[] arr;
    arr = m;
  }

  void insert(T &&elem) {
    if (real_size <= size_) {
      allocate();
    }
    arr[size_] = std::move(elem);
    size_ += 1;
  }

  void insert(T &elem) {
    if (real_size <= size_) {
      allocate();
    }
    arr[size_] = elem;
    size_ += 1;
  }

  template<typename... _Args>
  void emplace_back(_Args &&... args) {
    return insert(T(args...));
  }

  size_t size() const {
    return size_;
  }

};

int main() {
  Vector<int> g = {10, 2};
  g.insert(10);

  Vector<Vector<int>> tbrj(2, Vector<int>(5, 7));

  tbrj[1][2] = 5;



  for (int i = 0; i < tbrj.size(); i++) {
    for (int j = 0; j < tbrj[i].size(); j++) {
      std::cout << tbrj[i][j] << " ";
    }
    std::cout << std::endl;
  }


  Vector<Vector<int>> afb(2, Vector<int>(3, 6));

  for (int i = 0; i < afb.size(); i++) {
    for (int j = 0; j < afb[i].size(); j++) {
      std::cout << afb[i][j] << " ";
    }
    std::cout << std::endl;
  }

  Vector<std::pair<int, char>> gf(2);
  gf.emplace_back(2, 'a');
  gf[0] = {1, 'g'};
  gf.insert( std::make_pair(242, 'h'));

  for (int i = 0; i < g.size(); i++) {
    std::cout << g[i] << std::endl;
  }

  for (int i = 0; i < gf.size(); i++) {
    std::cout << gf[i].first << " " << gf[i].second << std::endl;
  }

  Vector<int> i = {2};
  int a = 0;
  i[0] = a;
  i[1] = 3;
  return 0;
}
