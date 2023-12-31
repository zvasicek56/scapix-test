// Generated by Scapix Language Bridge
// https://www.scapix.com

#include <scapix/bridge/python/init.h>
#include <T:/cpp_multiplatform/test2/src/lib.h>

void scapix_python_export_lib(pybind11::module& m)
{
	pybind11::class_<demo::device, std::shared_ptr<demo::device>> scapix_demo_device(m, "Device");

	scapix_demo_device
		.def(pybind11::init<>())
		.def<void(demo::device::*)(std::function<std::vector<std::uint8_t> ()>)>("initialize", &demo::device::initialize, pybind11::call_guard<pybind11::gil_scoped_release>())
	;
}
