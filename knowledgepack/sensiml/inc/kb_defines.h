#ifndef _KB_DEFINES_H_
#define _KB_DEFINES_H_
#include "kb_typedefs.h"
#include "stdio.h"
#ifdef __cplusplus
extern "C"
{
#endif

#define SML_DEBUG 1
#define SML_PROFILER 0
#ifndef SML_DEBUG
#define SML_DEBUG 0
#endif
#ifndef SML_PROFILER
#define SML_PROFILER 0
#endif

#ifdef __cplusplus
}
#endif

#endif //_KB_DEFINES_H_
