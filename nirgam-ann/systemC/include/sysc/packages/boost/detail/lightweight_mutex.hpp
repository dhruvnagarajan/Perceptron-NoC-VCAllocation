#ifndef BOOST_DETAIL_LIGHTWEIGHT_MUTEX_HPP_INCLUDED
#define BOOST_DETAIL_LIGHTWEIGHT_MUTEX_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  boost/detail/lightweight_mutex.hpp - lightweight mutex
//
//  Copyright (c) 2002, 2003 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  typedef <unspecified> boost::detail::lightweight_mutex;
//
//  boost::detail::lightweight_mutex is a header-only implementation of
//  a subset of the Mutex concept requirements:
//
//  http://www.boost.org/doc/html/threads/concepts.html#threads.concepts.Mutex
//
//  It maps to a CRITICAL_SECTION on Windows or a pthread_mutex on POSIX.
//

#include <sysc/packages/boost/config.hpp>

#if !defined(BOOST_HAS_THREADS)
# include <sysc/packages/boost/detail/lwm_nop.hpp>
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#  include <sysc/packages/boost/detail/lwm_win32_cs.hpp>
#elif defined(BOOST_HAS_PTHREADS)
#  include <sysc/packages/boost/detail/lwm_pthreads.hpp>
#else
// Use #define BOOST_DISABLE_THREADS to avoid the error
#  error Unrecognized threading platform
#endif

#endif // #ifndef BOOST_DETAIL_LIGHTWEIGHT_MUTEX_HPP_INCLUDED
