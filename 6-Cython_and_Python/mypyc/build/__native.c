#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"clip_vector", (PyCFunction)CPyPy_clip_vector, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "math_mypyc",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_math_mypyc(void)
{
    PyObject* modname = NULL;
    if (CPyModule_math_mypyc_internal) {
        Py_INCREF(CPyModule_math_mypyc_internal);
        return CPyModule_math_mypyc_internal;
    }
    CPyModule_math_mypyc_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_math_mypyc_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_math_mypyc_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_math_mypyc_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_math_mypyc_internal;
    fail:
    Py_CLEAR(CPyModule_math_mypyc_internal);
    Py_CLEAR(modname);
    return NULL;
}

PyObject *CPyDef_clip_vector(PyObject *cpy_r_a, double cpy_r_min_value, double cpy_r_max_value) {
    CPyPtr cpy_r_r0;
    int64_t cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_len_;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r4;
    char cpy_r_r5;
    int64_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    double cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    double cpy_r_r20;
    char cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    CPyTagged cpy_r_r26;
    PyObject *cpy_r_r27;
    cpy_r_r0 = (CPyPtr)&((PyVarObject *)cpy_r_a)->ob_size;
    cpy_r_r1 = *(int64_t *)cpy_r_r0;
    cpy_r_r2 = cpy_r_r1 << 1;
    cpy_r_len_ = cpy_r_r2;
    cpy_r_r3 = 0;
    CPyTagged_INCREF(cpy_r_r3);
    cpy_r_i = cpy_r_r3;
CPyL1: ;
    cpy_r_r4 = cpy_r_r3 & 1;
    cpy_r_r5 = cpy_r_r4 == 0;
    cpy_r_r6 = cpy_r_len_ & 1;
    cpy_r_r7 = cpy_r_r6 == 0;
    cpy_r_r8 = cpy_r_r5 & cpy_r_r7;
    if (!cpy_r_r8) goto CPyL3;
    cpy_r_r9 = (Py_ssize_t)cpy_r_r3 < (Py_ssize_t)cpy_r_len_;
    cpy_r_r10 = cpy_r_r9;
    goto CPyL4;
CPyL3: ;
    cpy_r_r11 = CPyTagged_IsLt_(cpy_r_r3, cpy_r_len_);
    cpy_r_r10 = cpy_r_r11;
CPyL4: ;
    if (!cpy_r_r10) goto CPyL18;
    cpy_r_r12 = CPyList_GetItem(cpy_r_a, cpy_r_i);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 8, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r13 = PyFloat_AsDouble(cpy_r_r12);
    if (cpy_r_r13 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r12); cpy_r_r13 = -113.0;
    }
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 == -113.0;
    if (unlikely(cpy_r_r14)) goto CPyL8;
CPyL7: ;
    cpy_r_r15 = cpy_r_r13 < cpy_r_min_value;
    if (cpy_r_r15) {
        goto CPyL9;
    } else
        goto CPyL10;
CPyL8: ;
    cpy_r_r16 = PyErr_Occurred();
    if (unlikely(cpy_r_r16 != NULL)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 8, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL7;
CPyL9: ;
    cpy_r_r17 = PyFloat_FromDouble(cpy_r_min_value);
    cpy_r_r18 = CPyList_SetItem(cpy_r_a, cpy_r_i, cpy_r_r17);
    CPyTagged_DECREF(cpy_r_i);
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 9, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL15;
CPyL10: ;
    cpy_r_r19 = CPyList_GetItem(cpy_r_a, cpy_r_i);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 10, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r20 = PyFloat_AsDouble(cpy_r_r19);
    if (cpy_r_r20 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r19); cpy_r_r20 = -113.0;
    }
    CPy_DECREF(cpy_r_r19);
    cpy_r_r21 = cpy_r_r20 == -113.0;
    if (unlikely(cpy_r_r21)) goto CPyL13;
CPyL12: ;
    cpy_r_r22 = cpy_r_r20 > cpy_r_max_value;
    if (cpy_r_r22) {
        goto CPyL14;
    } else
        goto CPyL21;
CPyL13: ;
    cpy_r_r23 = PyErr_Occurred();
    if (unlikely(cpy_r_r23 != NULL)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 10, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL12;
CPyL14: ;
    cpy_r_r24 = PyFloat_FromDouble(cpy_r_max_value);
    cpy_r_r25 = CPyList_SetItem(cpy_r_a, cpy_r_i, cpy_r_r24);
    CPyTagged_DECREF(cpy_r_i);
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 11, CPyStatic_globals);
        goto CPyL20;
    }
CPyL15: ;
    cpy_r_r26 = CPyTagged_Add(cpy_r_r3, 2);
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_INCREF(cpy_r_r26);
    cpy_r_r3 = cpy_r_r26;
    cpy_r_i = cpy_r_r26;
    goto CPyL1;
CPyL16: ;
    CPy_INCREF(cpy_r_a);
    return cpy_r_a;
CPyL17: ;
    cpy_r_r27 = NULL;
    return cpy_r_r27;
CPyL18: ;
    CPyTagged_DECREF(cpy_r_len_);
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL16;
CPyL19: ;
    CPyTagged_DecRef(cpy_r_len_);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL17;
CPyL20: ;
    CPyTagged_DecRef(cpy_r_len_);
    CPyTagged_DecRef(cpy_r_r3);
    goto CPyL17;
CPyL21: ;
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL15;
}

PyObject *CPyPy_clip_vector(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"a", "min_value", "max_value", 0};
    static CPyArg_Parser parser = {"OOO:clip_vector", kwlist, 0};
    PyObject *obj_a;
    PyObject *obj_min_value;
    PyObject *obj_max_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_a, &obj_min_value, &obj_max_value)) {
        return NULL;
    }
    PyObject *arg_a;
    if (likely(PyList_Check(obj_a)))
        arg_a = obj_a;
    else {
        CPy_TypeError("list", obj_a); 
        goto fail;
    }
    double arg_min_value;
    arg_min_value = PyFloat_AsDouble(obj_min_value);
    if (arg_min_value == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", obj_min_value); goto fail;
    }
    double arg_max_value;
    arg_max_value = PyFloat_AsDouble(obj_max_value);
    if (arg_max_value == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", obj_max_value); goto fail;
    }
    PyObject *retval = CPyDef_clip_vector(arg_a, arg_min_value, arg_max_value);
    return retval;
fail: ;
    CPy_AddTraceback("math_mypyc\\__init__.py", "clip_vector", 3, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL5;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[6]; /* ('List',) */
    cpy_r_r6 = CPyStatics[5]; /* 'typing' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("math_mypyc\\__init__.py", "<module>", 1, CPyStatic_globals);
        goto CPyL5;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    return 1;
CPyL5: ;
    cpy_r_r9 = 2;
    return cpy_r_r9;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_math_mypyc = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[7];
const char * const CPyLit_Str[] = {
    "\003\bbuiltins\004List\006typing",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {1, 1, 4};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_math_mypyc_internal = NULL;
CPyModule *CPyModule_math_mypyc;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
PyObject *CPyDef_clip_vector(PyObject *cpy_r_a, double cpy_r_min_value, double cpy_r_max_value);
PyObject *CPyPy_clip_vector(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
