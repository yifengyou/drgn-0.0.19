/* Generated by libdrgn/build-aux/gen_constants.py. */

#include "drgnpy.h"

PyObject *Architecture_class;
PyObject *FindObjectFlags_class;
PyObject *PlatformFlags_class;
PyObject *PrimitiveType_class;
PyObject *ProgramFlags_class;
PyObject *Qualifiers_class;
PyObject *SymbolBinding_class;
PyObject *SymbolKind_class;
PyObject *TypeKind_class;

static int add_Architecture(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(8);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "UNKNOWN", DRGN_ARCH_UNKNOWN);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "X86_64", DRGN_ARCH_X86_64);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "I386", DRGN_ARCH_I386);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "AARCH64", DRGN_ARCH_AARCH64);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
        item = Py_BuildValue("sk", "ARM", DRGN_ARCH_ARM);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 4, item);
        item = Py_BuildValue("sk", "PPC64", DRGN_ARCH_PPC64);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 5, item);
        item = Py_BuildValue("sk", "RISCV64", DRGN_ARCH_RISCV64);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 6, item);
        item = Py_BuildValue("sk", "RISCV32", DRGN_ARCH_RISCV32);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 7, item);
	Architecture_class = PyObject_CallMethod(enum_module, "Enum", "sO", "Architecture", tmp);
	if (!Architecture_class)
		goto out;
	if (PyModule_AddObject(m, "Architecture", Architecture_class) == -1) {
		Py_CLEAR(Architecture_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_Architecture_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(Architecture_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_FindObjectFlags(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(4);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "CONSTANT", DRGN_FIND_OBJECT_CONSTANT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "FUNCTION", DRGN_FIND_OBJECT_FUNCTION);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "VARIABLE", DRGN_FIND_OBJECT_VARIABLE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "ANY", DRGN_FIND_OBJECT_ANY);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
	FindObjectFlags_class = PyObject_CallMethod(enum_module, "Flag", "sO", "FindObjectFlags", tmp);
	if (!FindObjectFlags_class)
		goto out;
	if (PyModule_AddObject(m, "FindObjectFlags", FindObjectFlags_class) == -1) {
		Py_CLEAR(FindObjectFlags_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_FindObjectFlags_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(FindObjectFlags_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_PlatformFlags(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(2);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "IS_64_BIT", DRGN_PLATFORM_IS_64_BIT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "IS_LITTLE_ENDIAN", DRGN_PLATFORM_IS_LITTLE_ENDIAN);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
	PlatformFlags_class = PyObject_CallMethod(enum_module, "Flag", "sO", "PlatformFlags", tmp);
	if (!PlatformFlags_class)
		goto out;
	if (PyModule_AddObject(m, "PlatformFlags", PlatformFlags_class) == -1) {
		Py_CLEAR(PlatformFlags_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_PlatformFlags_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(PlatformFlags_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_PrimitiveType(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(18);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "C_VOID", DRGN_C_TYPE_VOID);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "C_CHAR", DRGN_C_TYPE_CHAR);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "C_SIGNED_CHAR", DRGN_C_TYPE_SIGNED_CHAR);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "C_UNSIGNED_CHAR", DRGN_C_TYPE_UNSIGNED_CHAR);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
        item = Py_BuildValue("sk", "C_SHORT", DRGN_C_TYPE_SHORT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 4, item);
        item = Py_BuildValue("sk", "C_UNSIGNED_SHORT", DRGN_C_TYPE_UNSIGNED_SHORT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 5, item);
        item = Py_BuildValue("sk", "C_INT", DRGN_C_TYPE_INT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 6, item);
        item = Py_BuildValue("sk", "C_UNSIGNED_INT", DRGN_C_TYPE_UNSIGNED_INT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 7, item);
        item = Py_BuildValue("sk", "C_LONG", DRGN_C_TYPE_LONG);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 8, item);
        item = Py_BuildValue("sk", "C_UNSIGNED_LONG", DRGN_C_TYPE_UNSIGNED_LONG);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 9, item);
        item = Py_BuildValue("sk", "C_LONG_LONG", DRGN_C_TYPE_LONG_LONG);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 10, item);
        item = Py_BuildValue("sk", "C_UNSIGNED_LONG_LONG", DRGN_C_TYPE_UNSIGNED_LONG_LONG);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 11, item);
        item = Py_BuildValue("sk", "C_BOOL", DRGN_C_TYPE_BOOL);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 12, item);
        item = Py_BuildValue("sk", "C_FLOAT", DRGN_C_TYPE_FLOAT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 13, item);
        item = Py_BuildValue("sk", "C_DOUBLE", DRGN_C_TYPE_DOUBLE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 14, item);
        item = Py_BuildValue("sk", "C_LONG_DOUBLE", DRGN_C_TYPE_LONG_DOUBLE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 15, item);
        item = Py_BuildValue("sk", "C_SIZE_T", DRGN_C_TYPE_SIZE_T);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 16, item);
        item = Py_BuildValue("sk", "C_PTRDIFF_T", DRGN_C_TYPE_PTRDIFF_T);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 17, item);
	PrimitiveType_class = PyObject_CallMethod(enum_module, "Enum", "sO", "PrimitiveType", tmp);
	if (!PrimitiveType_class)
		goto out;
	if (PyModule_AddObject(m, "PrimitiveType", PrimitiveType_class) == -1) {
		Py_CLEAR(PrimitiveType_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_PrimitiveType_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(PrimitiveType_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_ProgramFlags(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(2);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "IS_LINUX_KERNEL", DRGN_PROGRAM_IS_LINUX_KERNEL);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "IS_LIVE", DRGN_PROGRAM_IS_LIVE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
	ProgramFlags_class = PyObject_CallMethod(enum_module, "Flag", "sO", "ProgramFlags", tmp);
	if (!ProgramFlags_class)
		goto out;
	if (PyModule_AddObject(m, "ProgramFlags", ProgramFlags_class) == -1) {
		Py_CLEAR(ProgramFlags_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_ProgramFlags_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(ProgramFlags_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_Qualifiers(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(5);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "NONE", 0);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "CONST", DRGN_QUALIFIER_CONST);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "VOLATILE", DRGN_QUALIFIER_VOLATILE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "RESTRICT", DRGN_QUALIFIER_RESTRICT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
        item = Py_BuildValue("sk", "ATOMIC", DRGN_QUALIFIER_ATOMIC);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 4, item);
	Qualifiers_class = PyObject_CallMethod(enum_module, "Flag", "sO", "Qualifiers", tmp);
	if (!Qualifiers_class)
		goto out;
	if (PyModule_AddObject(m, "Qualifiers", Qualifiers_class) == -1) {
		Py_CLEAR(Qualifiers_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_Qualifiers_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(Qualifiers_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_SymbolBinding(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(5);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "UNKNOWN", DRGN_SYMBOL_BINDING_UNKNOWN);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "LOCAL", DRGN_SYMBOL_BINDING_LOCAL);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "GLOBAL", DRGN_SYMBOL_BINDING_GLOBAL);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "WEAK", DRGN_SYMBOL_BINDING_WEAK);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
        item = Py_BuildValue("sk", "UNIQUE", DRGN_SYMBOL_BINDING_UNIQUE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 4, item);
	SymbolBinding_class = PyObject_CallMethod(enum_module, "Enum", "sO", "SymbolBinding", tmp);
	if (!SymbolBinding_class)
		goto out;
	if (PyModule_AddObject(m, "SymbolBinding", SymbolBinding_class) == -1) {
		Py_CLEAR(SymbolBinding_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_SymbolBinding_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(SymbolBinding_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_SymbolKind(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(8);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "UNKNOWN", DRGN_SYMBOL_KIND_UNKNOWN);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "OBJECT", DRGN_SYMBOL_KIND_OBJECT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "FUNC", DRGN_SYMBOL_KIND_FUNC);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "SECTION", DRGN_SYMBOL_KIND_SECTION);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
        item = Py_BuildValue("sk", "FILE", DRGN_SYMBOL_KIND_FILE);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 4, item);
        item = Py_BuildValue("sk", "COMMON", DRGN_SYMBOL_KIND_COMMON);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 5, item);
        item = Py_BuildValue("sk", "TLS", DRGN_SYMBOL_KIND_TLS);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 6, item);
        item = Py_BuildValue("sk", "IFUNC", DRGN_SYMBOL_KIND_IFUNC);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 7, item);
	SymbolKind_class = PyObject_CallMethod(enum_module, "Enum", "sO", "SymbolKind", tmp);
	if (!SymbolKind_class)
		goto out;
	if (PyModule_AddObject(m, "SymbolKind", SymbolKind_class) == -1) {
		Py_CLEAR(SymbolKind_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_SymbolKind_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(SymbolKind_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

static int add_TypeKind(PyObject *m, PyObject *enum_module)
{
	PyObject *tmp, *item;
	int ret = -1;

	tmp = PyList_New(12);
	if (!tmp)
		goto out;
        item = Py_BuildValue("sk", "VOID", DRGN_TYPE_VOID);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 0, item);
        item = Py_BuildValue("sk", "INT", DRGN_TYPE_INT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 1, item);
        item = Py_BuildValue("sk", "BOOL", DRGN_TYPE_BOOL);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 2, item);
        item = Py_BuildValue("sk", "FLOAT", DRGN_TYPE_FLOAT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 3, item);
        item = Py_BuildValue("sk", "STRUCT", DRGN_TYPE_STRUCT);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 4, item);
        item = Py_BuildValue("sk", "UNION", DRGN_TYPE_UNION);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 5, item);
        item = Py_BuildValue("sk", "CLASS", DRGN_TYPE_CLASS);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 6, item);
        item = Py_BuildValue("sk", "ENUM", DRGN_TYPE_ENUM);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 7, item);
        item = Py_BuildValue("sk", "TYPEDEF", DRGN_TYPE_TYPEDEF);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 8, item);
        item = Py_BuildValue("sk", "POINTER", DRGN_TYPE_POINTER);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 9, item);
        item = Py_BuildValue("sk", "ARRAY", DRGN_TYPE_ARRAY);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 10, item);
        item = Py_BuildValue("sk", "FUNCTION", DRGN_TYPE_FUNCTION);
	if (!item)
		goto out;
	PyList_SET_ITEM(tmp, 11, item);
	TypeKind_class = PyObject_CallMethod(enum_module, "Enum", "sO", "TypeKind", tmp);
	if (!TypeKind_class)
		goto out;
	if (PyModule_AddObject(m, "TypeKind", TypeKind_class) == -1) {
		Py_CLEAR(TypeKind_class);
		goto out;
	}
	Py_DECREF(tmp);
	tmp = PyUnicode_FromString(drgn_TypeKind_DOC);
	if (!tmp)
		goto out;
	if (PyObject_SetAttrString(TypeKind_class, "__doc__", tmp) == -1)
		goto out;

	ret = 0;
out:
	Py_XDECREF(tmp);
	return ret;
}

int add_module_constants(PyObject *m)
{
	PyObject *enum_module;
	int ret;

	enum_module = PyImport_ImportModule("enum");
	if (!enum_module)
		return -1;

	if (add_Architecture(m, enum_module) == -1 ||
	    add_FindObjectFlags(m, enum_module) == -1 ||
	    add_PlatformFlags(m, enum_module) == -1 ||
	    add_PrimitiveType(m, enum_module) == -1 ||
	    add_ProgramFlags(m, enum_module) == -1 ||
	    add_Qualifiers(m, enum_module) == -1 ||
	    add_SymbolBinding(m, enum_module) == -1 ||
	    add_SymbolKind(m, enum_module) == -1 ||
	    add_TypeKind(m, enum_module) == -1)
		ret = -1;
	else
		ret = 0;
	Py_DECREF(enum_module);
	return ret;
}
