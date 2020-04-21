#!/bin/bash
export SVGA_VGPU10=0
export GAZEBO_PLUGIN_PATH=$(pwd)/builds:/usr/local/lib/gazebo-9/plugins:$GAZEBO_PLUGIN_PATH
export GAZEBO_MODEL_PATH=$(pwd)/models/sdf:$GAZEBO_MODEL_PATH
