#-----------------------------------------------
#                        
#  Keith McMillen Instruments 2013        
#                        
#  Authors:                   
#    Sarah Howe  sarah@keithmcmillen.com   
#                        
#-----------------------------------------------

from __future__ import with_statement

import Live #Now the Live API is available
import time #Now we can use time functions for time-stamping our log file outputs

from _Framework.ButtonElement import ButtonElement
from _Framework.ControlSurface import ControlSurface
from _Framework.ControlSurfaceComponent import ControlSurfaceComponent
from _Framework.InputControlElement import *
from _Framework.MixerComponent import MixerComponent
from _Framework.EncoderElement import EncoderElement
from _Framework.TransportComponent import TransportComponent

#define global variables
CHANNEL = 0  #channels are numbered 0 - 15
is_momentary = True

class SoftStepMixer(ControlSurface):
  __module__ = __name__
  __doc__ = "SoftStep controller script"
  
  def __init__(self, c_instance):
    ControlSurface.__init__(self, c_instance)
    with self.component_guard():
      self._setup_mixer_control()
      self._setup_transport_control()
      
  def _setup_transport_control(self):
    self._transport = TransportComponent()
    self._transport.set_stop_button(ButtonElement(is_momentary,MIDI_CC_TYPE,CHANNEL,67))
    self._transport.set_record_button(ButtonElement(is_momentary,MIDI_CC_TYPE,CHANNEL,68))
    self._transport.set_play_button(ButtonElement(is_momentary,MIDI_CC_TYPE,CHANNEL,66))
    self._transport.set_seek_forward_button(ButtonElement(is_momentary,MIDI_CC_TYPE,CHANNEL,70))
    self._transport.set_seek_backward_button(ButtonElement(is_momentary,MIDI_CC_TYPE,CHANNEL,69))
    

  def _setup_mixer_control(self):
    num_tracks = 5
    yincrements = [61,62,63,64,65]
    mastercc = 60
    #set up the mixer
    self.mixer = MixerComponent(num_tracks, 2)  #(num_tracks, num_returns, with_eqs, with_filters)
    self.mixer.set_track_offset(0)  #sets start point for mixer strip (offset from left)
    #set the selected strip to the first track, so that we don't, for example, try to assign a button to arm the master track, which would cause an assertion error
    self.song().view.selected_track = self.mixer.channel_strip(0)._track
    #set volume controls
    for index in range(num_tracks):
    	self.mixer.channel_strip(index).set_volume_control(EncoderElement(MIDI_CC_TYPE,CHANNEL,yincrements[index],Live.MidiMap.MapMode.absolute))

    self.mixer.master_strip().set_volume_control(EncoderElement(MIDI_CC_TYPE,CHANNEL,mastercc,Live.MidiMap.MapMode.absolute))
        
    
  def disconnect(self):
    #clean things up on disconnect
    
    #create entry in log file
    self.log_message(time.strftime("%d.%m.%Y %H:%M:%S", time.localtime()) + "----------SoftStep Basic log closed----------")
    
    ControlSurface.disconnect(self)
    return None
