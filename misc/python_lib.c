// #include <Python.h>

// static PyObject *spam_system(PyObject *self, PyObject *args)
// {
//     const char *command;
//     int sts;

//     if (!PyArg_ParseTuple(args, "s", &command))
//         return NULL;
//     sts = system(command);
//     return PyLong_FromLong(sts);
// }

// static PyMethodDef SpamMethods[] = {
//     {"system", spam_system, METH_VARARGS,
//      "Execute a shell command."},
//     {NULL, NULL, 0, NULL}        /* Sentinel */
// };

// static struct PyModuleDef spammodule = {
//     PyModuleDef_HEAD_INIT,
//     "spam",
//     NULL,
//     -1,
//     SpamMethods
// };

// PyMODINIT_FUNC PyInit_spam(void)
// {
//     return PyModule_Create(&spammodule);
// }


#include <Python.h>
#include <stdio.h>


static PyObject *mylib_add(PyObject *self, PyObject *args)
{
    int x, y, z, result;

    if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
        return NULL;
    printf("x is:- %d \n", x);
    printf("---zu---- %zu \n", args->ob_refcnt);
    printf("aa----: %s \n", args->ob_type->tp_name);

    result = x+y+z;

    return PyLong_FromLong(result);
}


static PyMethodDef mylib_methods[] = {
    {"add", mylib_add, METH_VARARGS, "Add two integers"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef mylib_module = {
    PyModuleDef_HEAD_INIT,
    "mylib",
    "Example module",
    -1,
    mylib_methods
};

PyMODINIT_FUNC PyInit_mylib(void)
{
    return PyModule_Create(&mylib_module);
}
