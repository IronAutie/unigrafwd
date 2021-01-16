// unigrafwd.cpp : Implementation of Cunigrafwd
#include "stdafx.h"
#include "Test.h"
#include "unigrafwd.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>

#include <comutil.h>


/////////////////////////////////////////////////////////////////////////////
// Cunigrafwd


//
// Test conversion copies the file being pointed to by first line of
// file, to filter's requested scrap path.
//
STDMETHODIMP Cunigrafwd::Convert(BSTR path, BSTR scrap, long resolution, long top, long left, long bottom, long right, long *status)
{
    char actual [MAX_PATH + 1];
	int state  = 1;
	int bytes  = 0;

    int fd  = _wopen (path, O_RDONLY);
	if (fd < 0) goto error;

	memset (actual, 0, sizeof (actual));
    state   = 2;
	bytes   = _read (fd, (void *) actual, MAX_PATH);
	if (bytes < 0) goto error;
	_close (fd);
    
    state   = CopyFileW (_bstr_t (actual), scrap, FALSE) ? 0 : 3; 

error:
   *status = state;
	return S_OK;
}

STDMETHODIMP Cunigrafwd::Cleanup(BSTR scrap, long *status)
{
	// TODO: Add your implementation code here
    *status = ! (long) DeleteFileW (scrap);
	return S_OK;
}

STDMETHODIMP Cunigrafwd::Resolution(long *number)
{
	// TODO: Add your implementation code here

   *number = -1;
	return S_OK;
}

STDMETHODIMP Cunigrafwd::Top(long *number)
{
	// TODO: Add your implementation code here

   *number = -1;
	return S_OK;
}

STDMETHODIMP Cunigrafwd::Left(long *number)
{
	// TODO: Add your implementation code here

   *number = -1;
	return S_OK;
}

STDMETHODIMP Cunigrafwd::Bottom(long *number)
{
	// TODO: Add your implementation code here

   *number = -1;
	return S_OK;
}

STDMETHODIMP Cunigrafwd::Right(long *number)
{
	// TODO: Add your implementation code here

   *number = -1;
	return S_OK;
}
