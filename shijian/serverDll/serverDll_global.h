#ifndef SERVERDLL_GLOBAL_H
#define SERVERDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SERVERDLL_LIBRARY)
#  define SERVERDLL_EXPORT Q_DECL_EXPORT
#else
#  define SERVERDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // SERVERDLL_GLOBAL_H
