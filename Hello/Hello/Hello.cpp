#include <Python.h>

int Add(int x, int y)
{
	return x + y;
}

static PyObject* WrappAdd(PyObject *self, PyObject *args)
{
	int x, y;
	if (!PyArg_ParseTuple(args, "ii", &x, &y))
	{
		return NULL;
	}
	return Py_BuildValue("i", Add(x, y));
}

static PyMethodDef test_methods[] = {
	{"Add", WrappAdd, METH_VARARGS, "something"},
	{NULL, NULL , 0, NULL}
};

static struct PyModuleDef PCmodule =
{
	PyModuleDef_HEAD_INIT,
	"Hello",
	NULL,
	-1,
	test_methods
};

PyMODINIT_FUNC
PyInit_Hello(void)
{
	return PyModule_Create(&PCmodule);
}