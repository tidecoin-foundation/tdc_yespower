#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *yespower_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    yespower_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    yespower_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef YespowerMethods[] = {
    { "getPoWHash", yespower_getpowhash, METH_VARARGS, "Returns the proof of work hash using yespower" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef YespowerModule = {
    PyModuleDef_HEAD_INIT,
    "yespower_hash",
    "...",
    -1,
    YespowerMethods
};

PyMODINIT_FUNC PyInit_tdc_yespower(void) {
    return PyModule_Create(&YespowerModule);
}

#else

PyMODINIT_FUNC inittdc_yespower(void) {
    (void) Py_InitModule("tdc_yespower", YespowerMethods);
}
#endif
