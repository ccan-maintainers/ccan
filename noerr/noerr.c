#include "noerr.h"
#include <unistd.h>
#include <errno.h>

int close_noerr(int fd)
{
	int saved_errno = errno, ret;

	if (close(fd) != 0)
		ret = errno;
	else
		ret = 0;

	errno = saved_errno;
	return ret;
}

int unlink_noerr(const char *pathname)
{
	int saved_errno = errno, ret;

	if (unlink(pathname) != 0)
		ret = errno;
	else
		ret = 0;

	errno = saved_errno;
	return ret;
}