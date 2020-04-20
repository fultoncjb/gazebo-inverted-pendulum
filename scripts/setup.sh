echo $(pwd)
export SVGA_VGPU10=0
export GAZEBO_PLUGIN_PATH=$(pwd)/builds/plugins:$GAZEBO_PLUGIN_PATH
export GAZEBO_MODEL_PATH=$(pwd)/models/sdf:$GAZEBO_MODEL_PATH
