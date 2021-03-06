/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2006 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  sc_trace.cpp - Functions for tracing signals and variables.

  Original Author: Abhijit Ghosh, Synopsys, Inc.

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

/*****************************************************************************

   Acknowledgement: The tracing mechanism is based on the tracing
   mechanism developed at Infineon (formerly Siemens HL). Though this
   code is somewhat different, the basics are identical to what was
   originally contributed by Infineon.  The contribution of Infineon
   in the development of this tracing technology is hereby
   acknowledged.

 *****************************************************************************/

#include <stdarg.h>
#include <stdio.h>

#include "sysc/utils/sc_iostream.h"
#include "sysc/tracing/sc_trace.h"
#include "sysc/communication/sc_signal_ifs.h"
#include "sysc/utils/sc_utils_ids.h"

namespace sc_core
{

// Trace file common functions.

sc_trace_file::sc_trace_file()
{
    /* Intentionally blank */
}

void
put_error_message(const char* msg, bool just_warning)
{
    if (just_warning)
    {
        ::std::cout << "Trace Warning:\n" << msg << "\n" << ::std::endl;
    }
    else
    {
        ::std::cout << "Trace ERROR:\n" << msg << "\n" << ::std::endl;
    }
}


void sc_trace_file::set_time_unit(double v, sc_time_unit tu)
{
    if (initialized)
    {
        put_error_message(
            "Trace timescale unit cannot be changed once tracing has begun.",
            false
        );
        std::cout << "To change the scale, create a new trace file."
                  << std::endl;
        return;
    }

    switch ( tu )
    {
    case SC_FS:
        v = v * 1e-15;
        break;
    case SC_PS:
        v = v * 1e-12;
        break;
    case SC_NS:
        v = v * 1e-9;
        break;
    case SC_US:
        v = v * 1e-6;
        break;
    case SC_MS:
        v = v * 1e-3;
        break;
    case SC_SEC:
        break;
    default:
        put_error_message("Unknown time unit specified ",true);
        std::cout << tu << std::endl;
        break;
    };

    timescale_unit = v;

    // EMIT ADVISORY MESSAGE ABOUT CHANGE IN TIME SCALE:

    char buf[200];
    std::sprintf(buf,
                 "Note: VCD trace timescale unit is set by user to %e sec.\n",
                 timescale_unit);
    ::std::cout << buf << ::std::flush;

    timescale_set_by_user = true;
}

void sc_trace_file::set_time_unit(int exponent10_seconds)
{
    sc_time_unit tu;
    double       v;

    if     (exponent10_seconds == -15)
    {
        v = 1.0;
        tu = SC_FS;
    }
    else if (exponent10_seconds == -14)
    {
        v = 10.0;
        tu = SC_FS;
    }
    else if (exponent10_seconds == -13)
    {
        v = 100.0;
        tu = SC_FS;
    }
    else if (exponent10_seconds == -12)
    {
        v = 1.0;
        tu = SC_PS;
    }
    else if (exponent10_seconds == -11)
    {
        v = 10.0;
        tu = SC_PS;
    }
    else if (exponent10_seconds == -10)
    {
        v = 100.0;
        tu = SC_PS;
    }
    else if (exponent10_seconds ==  -9)
    {
        v = 1.0;
        tu = SC_NS;
    }
    else if (exponent10_seconds ==  -8)
    {
        v = 10.0;
        tu = SC_NS;
    }
    else if (exponent10_seconds ==  -7)
    {
        v = 100.0;
        tu = SC_NS;
    }
    else if (exponent10_seconds ==  -6)
    {
        v = 1.0;
        tu = SC_US;
    }
    else if (exponent10_seconds ==  -5)
    {
        v = 10.0;
        tu = SC_US;
    }
    else if (exponent10_seconds ==  -4)
    {
        v = 100.0;
        tu = SC_US;
    }
    else if (exponent10_seconds ==  -3)
    {
        v = 1.0;
        tu = SC_MS;
    }
    else if (exponent10_seconds ==  -2)
    {
        v = 10.0;
        tu = SC_MS;
    }
    else if (exponent10_seconds ==  -1)
    {
        v = 100.0;
        tu = SC_MS;
    }
    else if (exponent10_seconds ==   0)
    {
        v = 1.0;
        tu = SC_SEC;
    }
    else if (exponent10_seconds ==   1)
    {
        v = 10.0;
        tu = SC_SEC;
    }
    else if (exponent10_seconds ==   2)
    {
        v = 100.0;
        tu = SC_SEC;
    }
    else
    {
        put_error_message(
            "set_time_unit() has valid exponent range -15...+2.", false);
        return;
    }
    set_time_unit( v, tu );
}

void tprintf(sc_trace_file* tf,  const char* format, ...)
{
    static char buffer[4096];
    va_list ap;
    va_start(ap, format);
    (void) vsprintf(buffer, format, ap);
    va_end(ap);
    if (tf) tf->write_comment(buffer);
}

void sc_trace_file::space(int)
{
    /* Intentionally blank */
}

void sc_trace_file::delta_cycles(bool)
{
    /* Intentionally blank */
}


void
sc_trace( sc_trace_file* tf,
          const sc_signal_in_if<char>& object,
          const std::string& name,
          int width )
{
    if ( tf )
    {
        tf->trace( object.read(), name, width );
    }
}

void
sc_trace( sc_trace_file* tf,
          const sc_signal_in_if<short>& object,
          const std::string& name,
          int width )
{
    if ( tf )
    {
        tf->trace( object.read(), name, width );
    }
}

void
sc_trace( sc_trace_file* tf,
          const sc_signal_in_if<int>& object,
          const std::string& name,
          int width )
{
    if ( tf )
    {
        tf->trace( object.read(), name, width );
    }
}

void
sc_trace( sc_trace_file* tf,
          const sc_signal_in_if<long>& object,
          const std::string& name,
          int width )
{
    if ( tf )
    {
        tf->trace( object.read(), name, width );
    }
}


void
sc_trace(sc_trace_file* /* not used */,
         const void* /* not used */,
         const std::string& name)
{
    ::std::cout << "Object " << name << " will not be traced" << ::std::endl;
}



void double_to_special_int64(double in, unsigned* high, unsigned* low)
{
    double invar = in;
    if (invar > 5e17) invar = 5e17; // Saturation limit
    if (invar < 0.0) invar = 0.0;
    invar += .5;
    *high = (unsigned)(invar / 1e9);
    double rest = invar - 1e9 * (*high);
    if (rest < 0) *low = 0;
    else *low = (unsigned)rest;
}


// ----------------------------------------------------------------------------

#define DEFN_TRACE_FUNC_REF_A(tp)                                             \
void                                                                          \
sc_trace( sc_trace_file* tf, const tp& object, const std::string& name ) \
{                                                                             \
    if( tf ) {                                                                \
	tf->trace( object, name );                                            \
    }                                                                         \
}

#define DEFN_TRACE_FUNC_PTR_A(tp)                                             \
void                                                                          \
sc_trace( sc_trace_file* tf, const tp* object, const std::string& name ) \
{                                                                             \
    if( tf ) {                                                                \
	tf->trace( *object, name );                                           \
    }                                                                         \
}

#define DEFN_TRACE_FUNC_A(tp)                                                 \
DEFN_TRACE_FUNC_REF_A(tp)                                                     \
DEFN_TRACE_FUNC_PTR_A(tp)


DEFN_TRACE_FUNC_A( sc_dt::sc_bit )
DEFN_TRACE_FUNC_A( sc_dt::sc_logic )

DEFN_TRACE_FUNC_A( sc_dt::sc_int_base )
DEFN_TRACE_FUNC_A( sc_dt::sc_uint_base )
DEFN_TRACE_FUNC_A( sc_dt::sc_signed )
DEFN_TRACE_FUNC_A( sc_dt::sc_unsigned )

DEFN_TRACE_FUNC_REF_A( sc_dt::sc_bv_base )
DEFN_TRACE_FUNC_REF_A( sc_dt::sc_lv_base )


#undef DEFN_TRACE_FUNC_REF_A
#undef DEFN_TRACE_FUNC_PTR_A
#undef DEFN_TRACE_FUNC_A


void
sc_trace( sc_trace_file* tf,
          const unsigned int& object,
          const std::string& name,
          const char** enum_literals )
{
    static bool warn_sc_trace_literals=true;
    if ( warn_sc_trace_literals )
    {
        warn_sc_trace_literals=false;
        SC_REPORT_INFO(SC_ID_IEEE_1666_DEPRECATION_,
                       "tracing of enumerated literals is deprecated" );
    }

    if ( tf ) tf->trace( object, name, enum_literals );
}

} // namespace sc_core

// Taf!
