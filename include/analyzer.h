

#ifndef __ANALYZER_H__
#define __ANALYZER_H__

typedef void (*analyzer_map)(const char *);

#ifdef __clang__
void str_split(const char *str, char delimiter, void(^map_function)(const char *));
#else
void str_split(const char *str, char delimiter, void (*map_function)(const char *));
#endif




#endif