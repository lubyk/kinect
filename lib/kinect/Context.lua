--[[------------------------------------------------------

  kinect.Context
  --------------

  This is usually not directly accessed by end users but
  is required by all kinect classes.

--]]------------------------------------------------------
require 'kinect.Context_core'

local constr = kinect.Context

function kinect.Context()
  return constr()
end

