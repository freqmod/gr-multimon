 /** -*- c++ -*- */
 /*
  * Copyright 2004 Free Software Foundation, Inc.
  * 
  * This file is part of GNU Radio
  * 
  * GNU Radio is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2, or (at your option)
  * any later version.
  * 
  * GNU Radio is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  * 
  * You should have received a copy of the GNU General Public License
  * along with GNU Radio; see the file COPYING.  If not, write to
  * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
  * Boston, MA 02111-1307, USA.
  */
 #ifndef INCLUDED_AFSK1200_H
 #define INCLUDED_AFSK1200_H
 
#include <gnuradio/block.h>
extern "C"{
 #include <multimon.h>
}

 class multimon_afsk1200;
 
 /*
  * We use boost::shared_ptr's instead of raw pointers for all access
  * to gr::block's (and many other data structures).  The shared_ptr gets
  * us transparent reference counting, which greatly simplifies storage
  * management issues.  This is especially helpful in our hybrid
  * C++ / Python system.
  *
  * See http://www.boost.org/libs/smart_ptr/smart_ptr.htm
  *
  * As a convention, the _sptr suffix indicates a boost::shared_ptr
  */
 typedef boost::shared_ptr<multimon_afsk1200> multimon_afsk1200_sptr;
 
 /*!
  * \brief Return a shared_ptr to a new instance of multimon_afsk1200.
  *
  * To avoid accidental use of raw pointers, multimon_afsk1200's
  * constructor is private.  howto_make_square_ff is the public
  * interface for creating new instances.
  */
                        
__GR_ATTR_EXPORT multimon_afsk1200_sptr make_multimon_afsk1200 ();// (const std::string &args);
 
 /*!
  * \brief square a stream of floats.
  * \ingroup block
  *
  * \sa howto_square2_ff for a version that subclasses gr_sync_block.
  */
 class multimon_afsk1200 : public gr::block
 {
 private:
   // The friend declaration allows howto_make_square_ff to
   // access the private constructor.
 
   friend multimon_afsk1200_sptr make_multimon_afsk1200 ();//(const std::string &args);
 
   multimon_afsk1200 ();   // private constructor
 
  public:
   ~multimon_afsk1200 ();  // public destructor
 
   // Where all the action really happens
 
   int general_work (int noutput_items,
                     gr_vector_int &ninput_items,
                     gr_vector_const_void_star &input_items,
                     gr_vector_void_star &output_items);

private: 
    demod_state *state;
};
 
 #endif /* INCLUDED_HOWTO_SQUARE_FF_H */
