#include "suspect.h"

#include <iostream>


void function_one(float x)
{
  SUSPECT_STATIC(int, count, 0,);
  SUSPECT_STATIC(float, mult, 1.0f,);

  ++count;
  mult *= x;
}

struct FancyModule;
void function_two()
{
  SUSPECT_STATIC(int, fancy_count, 0, FancyModule);
  ++fancy_count;
}


namespace std
{
  template <typename T>
  std::ostream & operator<<(std::ostream &out, const std::vector<T> &v)
  {
    out << "{";
    for (auto it = v.begin(), end = v.end(); it != end; ++it)
     out << (it != v.begin() ? " " : "") << *it;
    out << "}";
    return out;
  }
}


int main()
{
  function_one(2.0f);
  function_one(3.0f);
  function_one(4.0f);

  function_two();
  function_two();

  std::vector<int> list = {5};

  spct::add("ref", list);
  spct::add("moved", std::move(list));
  std::cout << "after inserting, list==" << list << "\n";
  list.push_back(7);
  std::cout << "after pushing, list==" << list << "\n";

  spct::report(std::cout);
  spct::report<FancyModule>(std::cout);

  std::cout << spct::name(0) << " === " << spct::ref(0, spct::to<int>) << "\n";
  std::cout << "\"mult\"" << " === " << spct::ref("mult", spct::to<float>) << "\n";

  auto fancy_module = spct::tagged<FancyModule>();
  std::cout << "\"fancy_count\" === " << fancy_module.ref("fancy_count", spct::to<int>) << "\n";

  return 0;
}

