#include <interpolation/spline_interpolation_points_2d.hpp>
#include <lanelet2_extension/utility/utilities.hpp>

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <geometry_msgs/msg/point.h>
#include <lanelet2_core/primitives/Lanelet.h>
#include <lanelet2_python/internal/converter.h>

void export_utilities();

BOOST_PYTHON_MODULE(PYTHON_API_MODULE_NAME)
{
  // __init__.py is placed under site-packages/lanelet2_extension/, so utility.so is recognized as
  // submodule
  // if the user side import lanelet2 python module, we do not need OptionalConverter()
  // TODO: or import lanelet2 in this module to ensure that the converter is registered
  namespace bp = boost::python;
  bp::class_<std::vector<double>>("std::vector<double>")
    .def(bp::vector_indexing_suite<std::vector<double>>());
  export_utilities();
}

BOOST_PYTHON_FUNCTION_OVERLOADS(
  generateFineCenterline_overload, lanelet::utils::generateFineCenterline, 1,
  2)  // for handling default arguments

std::vector<double> getCurvatures(lanelet::ConstLanelet & ll, const double resolution)
{
  const auto centerline = lanelet::utils::generateFineCenterline(ll, resolution);
  std::vector<geometry_msgs::msg::Point> points;
  for (const auto & pt : centerline) {
    geometry_msgs::msg::Point point;
    point.x = pt.x();
    point.y = pt.y();
    points.push_back(point);
  }
  SplineInterpolationPoints2d interpolation(points);
  return interpolation.getSplineInterpolatedCurvatures();
}

void export_utilities()
{
  namespace bp = boost::python;
  // TOOD: replace lanelet2_extension
  // https://stackoverflow.com/questions/18948193/is-there-a-way-to-get-the-name-of-the-parent-module-from-an-imported-module
  bp::object utilities_module(
    bp::handle<>(bp::borrowed(PyImport_AddModule("lanelet2_extension.utility.utilities"))));
  auto package = boost::python::scope();
  package.attr("__path__") = "utility";  // TODO: replace PYTHON_API_MODULE_NAME
  bp::scope().attr("utilities") = utilities_module;
  bp::scope utilities_scope = utilities_module;
  bp::def(
    "generateFineCenterline", lanelet::utils::generateFineCenterline,
    generateFineCenterline_overload());
  bp::def("getCurvatures", getCurvatures);
}
