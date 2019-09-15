/*cppimport

*/
#include <pybind11/pybind11.h>
//#include <pybind11/eigen.h>
#include <pybind11/stl_bind.h>
namespace py = pybind11;

#include <memory>

#include "graphics_cpp/graphics.h"

typedef graphics::mesh_traits<graphics::basic_vertex_traits,graphics::basic_triangle_traits> traits_t;
typedef graphics::mesh<traits_t> mesh_t;
typedef typename mesh_t::vertex_t vertex_t;
typedef typename mesh_t::triangle_t triangle_t;




int square(int x) {
    return x * x;
}

PYBIND11_MODULE( graphics_bindings, m) {
    m.def("square", &square);

    py::class_<vertex_t,std::unique_ptr<vertex_t,py::nodelete>>(m,"Vertex")
        .def_readwrite("id",&vertex_t::id)
    ;

    py::class_<triangle_t,std::unique_ptr<triangle_t,py::nodelete>>(m,"Triangle")
        .def_readwrite("id",&triangle_t::id)
    ;

    py::class_<mesh_t>(m,"Mesh")
        .def(py::init<>())
        .def("add_vertex",      &mesh_t::add_vertex,    py::return_value_policy::reference )
        .def("add_triangle",    &mesh_t::add_triangle,  py::return_value_policy::reference )
        .def("remove_vertex",   &mesh_t::remove_vertex )
        .def("remove_triangle", &mesh_t::remove_triangle )
    ;
}