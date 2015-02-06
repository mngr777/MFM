/*                                              -*- mode:C++ -*-
  Element_Xtal_R12.h Right-tipped, knight's-J-move crystal
  Copyright (C) 2014 The Regents of the University of New Mexico.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
  USA
*/

/**
  \file Element_Xtal_R12.h Right-tipped, knight's-J-move crystal
  \author David H. Ackley.
  \date (C) 2014 All rights reserved.
  \lgpl
 */
#ifndef ELEMENT_XTAL_R12_H
#define ELEMENT_XTAL_R12_H

#include "Element.h"
#include "EventWindow.h"
#include "ElementTable.h"
#include "Element_Xtal_L12.h"
#include "itype.h"

namespace MFM
{

  template <class EC>
  class Element_Xtal_R12 : public Element_Xtal_L12<EC>
  {
    enum {  ELT_VERSION = 2 };

    // Extract short names for parameter types
    typedef typename EC::ATOM_CONFIG AC;
    typedef typename AC::ATOM_TYPE T;

  public:

    static Element_Xtal_R12 THE_INSTANCE;

    Element_Xtal_R12() : Element_Xtal_L12<EC>(MFM_UUID_FOR("XtalR12", ELT_VERSION))
    {
      Element<EC>::SetAtomicSymbol("Xr");
      Element<EC>::SetName("R1,2 crystal");
    }

    virtual u32 GetSymI(T &atom, EventWindow<EC>& window) const
    {
      return (u32) PSYM_FLIPY;
    }
  };

  template <class EC>
  Element_Xtal_R12<EC> Element_Xtal_R12<EC>::THE_INSTANCE;

}

#endif /* ELEMENT_XTAL_R12_H */
