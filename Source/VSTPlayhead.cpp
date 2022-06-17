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
//  VSTPlayhead.cpp
//  Bespoke
//
//  Created by Ryan Challinor on 1/20/16.
//
//

#include "VSTPlayhead.h"
#include "Transport.h"

bool VSTPlayhead::getPosition(juce::AudioPlayHead::PositionInfo& result)
{
   timeSignature.numerator = TheTransport->GetTimeSigTop();
   timeSignature.denominator = TheTransport->GetTimeSigBottom();
   loopPoint.ppqStart = 0;
   loopPoint.ppqEnd = 480 * result.getTimeSignature()->denominator;

   result.setBpm(TheTransport->GetTempo());
   result.setTimeSignature(timeSignature);
   result.setTimeInSamples(gTime* gSampleRateMs);
   result.setTimeInSeconds(gTime / 1000);

   /*
   * getMeasureTime is a float of how many measures we are through with fractional
   * measures. We want to know the number of quarter notes from the epoch which is
   * just the tsRatio times measure count, and for start of measure we simply floor
   * the measure time
   */
   double tsRatio = 4;
   if (result.getTimeSignature()->numerator > 0)
      tsRatio = 1.0 * result.getTimeSignature()->numerator / result.getTimeSignature()->denominator * 4;
   result.setPpqPosition((TheTransport->GetMeasureTime(gTime)) * tsRatio);
   result.setPpqPositionOfLastBarStart (floor(TheTransport->GetMeasureTime(gTime)) * tsRatio);

   result.setIsPlaying(true);
   result.setIsRecording(false);
   result.setIsLooping(false);
   result.setLoopPoints(loopPoint);
   result.setFrameRate(juce::AudioPlayHead::fps60);

   return true;
}
