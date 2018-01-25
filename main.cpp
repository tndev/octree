#include <iostream>

#include <array>
#include <glm/glm.hpp>
//#include <glm/gtx/extented_min_max.hpp>
#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

#include <tndev/octree/helper.hpp>
#include <tndev/octree/octree.hpp>

namespace tndev {
namespace octree {
template <> glm::vec3 get_position(const glm::vec3 &obj) { return obj; }
} // namespace octree
} // namespace tndev

int main(void) {
  tndev::octree::octree<glm::vec3> oc(glm::vec3(0, 0, 0), 10.f);

  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(5.f, 4.f, 5.f));
  oc.push_back(glm::vec3(4.f, 4.f, 5.f));
  oc.push_back(glm::vec3(3.f, 4.f, 5.f));
  oc.push_back(glm::vec3(2.f, 4.f, 5.f));
  oc.push_back(glm::vec3(1.f, 4.f, 5.f));
  oc.push_back(glm::vec3(10.f, 4.f, 5.f));
  oc.push_back(glm::vec3(9.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));
  oc.push_back(glm::vec3(6.f, 4.f, 5.f));

  auto cell = tndev::octree::find_cell(oc, glm::vec3(6.f, 4.f, 5.f));

  std::cout << "save" << std::endl;

  std::cin.get();
}