#include <lanelet2_extension/utility/utilities.hpp>

#include <boost/python.hpp>

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
  export_utilities();
}

BOOST_PYTHON_FUNCTION_OVERLOADS(
  generateFineCenterline_overload, lanelet::utils::generateFineCenterline, 1,
  2)  // for handling default arguments

void export_utilities()
{
  namespace bp = boost::python;
  bp::object utilities_module(
    bp::handle<>(bp::borrowed(PyImport_AddModule("lanelet2_extension.utility.utilities"))));
  auto package = boost::python::scope();
  package.attr("__path__") = "utility";  // TODO: replace PYTHON_API_MODULE_NAME
  bp::scope().attr("utilities") = utilities_module;
  bp::scope utilities_scope = utilities_module;
  bp::def(
    "generateFineCenterline", lanelet::utils::generateFineCenterline,
    generateFineCenterline_overload());
}
