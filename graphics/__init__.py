import os
import cppimport.import_hook
cppimport.force_rebuild()

from .graphics_bindings import *

PATH = os.path.dirname(os.path.abspath(__file__))