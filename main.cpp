#include <iostream>
#include "vector.h"


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
