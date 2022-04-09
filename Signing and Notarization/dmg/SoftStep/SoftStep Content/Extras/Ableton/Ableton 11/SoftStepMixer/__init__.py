#__init__.py
from .SoftStepMixer import SoftStepMixer

def create_instance(c_instance):
	return SoftStepMixer(c_instance)