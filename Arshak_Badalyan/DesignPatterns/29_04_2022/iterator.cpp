
#include <iostream>
#include <string>
#include <vector>


template <typename T, typename U>
class Iterator {

  typedef typename std::vector<T>::iterator iterator_type;

private:
  U *my_privuse_data;
  iterator_type my_iteration;

public:

  Iterator(U *p_data, bool reverse = false) : my_privuse_data(p_data) {
    my_iteration = my_privuse_data->my_data.begin();
  }

  void First() {
    my_iteration = my_privuse_data->my_data.begin();
  }

  void Next() {
    my_iteration++;
  }

  bool IsDone() {
    return (my_iteration == my_privuse_data->my_data.end());
  }

  iterator_type Current() {
    return my_iteration;
  }

};


template <class T>
class Container {
  friend class Iterator<T, Container>;

private:
  std::vector<T> my_data;

public:
  void add(T data) {
    my_data.push_back(data);
  }

  Iterator<T, Container> *createIterator() {
    return new Iterator<T, Container>(this);
  }

};

class Data {
private:
  int my_data;

public:
  Data(int data = 0) : my_data(data) {};

  void set_data(int data) {
    my_data = data;
  }

  int data() {
    return my_data;
  }
};


void runIterator() {
  std::cout << "*** Iterator with int ***" << std::endl;
  Container<int> cont;

  for (int i = 0; i < 10; i++) {
    cont.add(i);
  }

  Iterator<int, Container<int>> *it = cont.createIterator();
  for (it->First(); !it->IsDone(); it->Next()) {
    std::cout << *it->Current() << " ";
  }
  std::cout << std::endl;



  std::cout << "*** Iterator with char ***" << std::endl;
  Container<std::string> cont2;
  cont2.add("a");
  cont2.add("b");
  cont2.add("c");

  Iterator<std::string, Container<std::string>> *it2 = cont2.createIterator();
  for (it2->First(); !it2->IsDone(); it2->Next()) {
    std::cout << it2->Current()->data() << " ";
  }
  std::cout <<  std::endl;
  delete it;
  delete it2;
}

int main() {
  runIterator();
  return 0;
}