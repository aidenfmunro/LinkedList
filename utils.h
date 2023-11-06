#ifndef UTILS_H
#define UTILS_H

#define CheckPointerValidation(pointer)     \
    do                                      \
      {                                     \
        if (!isPointerValid(&pointer))      \
            return INVALID_PTR;             \
      } while(0);

#define SafeCalloc(var, type, nmemb)                    \
    var = (type*)calloc(nmemb, sizeof(type));           \
                                                        \
    if (!var)                                           \
        return NO_MEMORY_AVAILABLE;

#define AssertSoft(expression, error, ...)                                                                   \
if (!(expression))                                                                                           \
{                                                                                                            \
  do                                                                                                         \
    {                                                                                                        \
      fprintf(stderr, "%s in %s in %s in line: %d\n", #error, __FILE__, __PRETTY_FUNCTION__, __LINE__);      \
      __VA_ARGS__;                                                                                           \
      return error;                                                                                          \
    } while(0);                                                                                              \
}

#endif 