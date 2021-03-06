#ifndef _ZLIB_EXTRA_H
#define _ZLIB_EXTRA_H

#include "util.h"
#include <zlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Like getline, but read from a gzFile. Allocation is with talloc.
 * Returns:
 *
 *   UTIL_SUCCESS, UTIL_OUT_OF_MEMORY, UTIL_ERRNO, UTIL_GZERROR
 *			Consult util.h for description
 *
 *   UTIL_EOF		End of file encountered before
 *			any characters read
 */
util_status_t
gz_getline (void *ctx, char **lineptr, ssize_t *bytes_read, gzFile stream);

/* return a suitable error string based on the return status
 *  from gz_readline
 */

const char *
gz_error_string (util_status_t status, gzFile stream);

/* Call gzerror with a dummy errno argument, the docs don't promise to
 * support the NULL case */
inline const char *
gzerror_str(gzFile file) { int dummy; return gzerror (file, &dummy); }

#ifdef __cplusplus
}
#endif

#endif
