#include <lanelet2_extension/projection/mgrs_projector.hpp>

#include <boost/python.hpp>

#include <lanelet2_io/Projection.h>

#include <memory>

using namespace lanelet;

BOOST_PYTHON_MODULE(PYTHON_API_MODULE_NAME)
{
  using namespace boost::python;
  class_<Projector, boost::noncopyable, std::shared_ptr<Projector>>(
    "Projector", "Projects point from lat/lon to x/y and back", no_init)
    .def("forward", &Projector::forward, "Convert lat/lon into x/y")
    .def("reverse", &Projector::reverse, "Convert x/y into lat/lon")
    .def(
      "origin", &Projector::origin, "Global origin of the converter",
      return_internal_reference<>());
  class_<
    lanelet::projection::MGRSProjector, std::shared_ptr<lanelet::projection::MGRSProjector>,
    bases<Projector>>("MGRSProjector", init<Origin>("origin"));
}
