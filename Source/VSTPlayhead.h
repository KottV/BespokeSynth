/**
    bespoke synth, a software modular synthesizer
    Copyright (C) 2021 Ryan Challinor (contact: awwbees@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
//
//  VSTPlayhead.h
//  Bespoke
//
//  Created by Ryan Challinor on 1/20/16.
//
//

#ifndef __Bespoke__VSTPlayhead__
#define __Bespoke__VSTPlayhead__

#include "juce_audio_basics/juce_audio_basics.h"

class VSTPlayhead : public juce::AudioPlayHead::PositionInfo
{
public:
   bool getPosition(PositionInfo& result);
   juce::AudioPlayHead::TimeSignature timeSignature;
   juce::AudioPlayHead::LoopPoints loopPoint;
};

#endif /* defined(__Bespoke__VSTPlayhead__) */
