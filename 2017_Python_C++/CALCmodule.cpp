#include <Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_10_API_VERSION
#include <numpy/arrayobject.h>
#include "CALC.h"



struct module_state {
    PyObject *error;
};

#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))

static PyObject* CALC(PyObject* self, PyObject* args)
{
	PyArrayObject *data_obj;
	PyArrayObject *result_obj;
	double treshold;
	int N;

	if (!PyArg_ParseTuple(args, "OOid", &data_obj, &result_obj, &N, &treshold))
	{
		Py_INCREF(Py_None);
		return Py_None;
	}

	double *DATA = static_cast<double *>(PyArray_DATA(data_obj));
	int *RESULT = static_cast<int *>(PyArray_DATA(result_obj));

	_CALC(DATA, RESULT, N, treshold);

	Py_INCREF(Py_None);
	return Py_None;
}

static PyMethodDef CALCMethods[] = {
    {"CALC", CALC, METH_VARARGS, "..."},
    {NULL, NULL, 0, NULL}
};

static int CALC_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int CALC_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}


static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "CALC",
        NULL,
        sizeof(struct module_state),
        CALCMethods,
        NULL,
        CALC_traverse,
        CALC_clear,
        NULL
};

extern "C" PyObject * PyInit_CALC(void)
{
	PyObject *module = PyModule_Create(&moduledef);
	if (module == NULL)
        return NULL;
    struct module_state *st = GETSTATE(module);

    st->error = PyErr_NewException("CALC.Error", NULL, NULL);
    if (st->error == NULL) 
    {
        Py_DECREF(module);
        return NULL;
    }
	import_array();
	Py_INCREF(module);
    return module;

}