/* -*- c++ -*- */

%include "std_common.i"                            // the common stuff
%include "exception.i"
%include "gnuradio.i"                            // the common stuff
%{
#include "gnuradio_swig_bug_workaround.h"       // mandatory bug fix
#include "afsk1200.h"
#include "hdlc.h"
#include <stdexcept>
%}

// ----------------------------------------------------------------

/*
 * First arg is the package prefix.
 * Second arg is the name of the class minus the prefix.
 *
 * This does some behind-the-scenes magic so we can
 * access howto_square_ff from python as howto.square_ff
 */
GR_SWIG_BLOCK_MAGIC(multimon, afsk1200);

multimon_afsk1200_sptr make_multimon_afsk1200 ();

class multimon_afsk1200 : public gr::block
{
private:
  multimon_afsk1200 ();
};

GR_SWIG_BLOCK_MAGIC(multimon, hdlc);

multimon_hdlc_sptr make_multimon_hdlc ();

class multimon_hdlc : public gr::block
{
private:
  multimon_hdlc ();
};

