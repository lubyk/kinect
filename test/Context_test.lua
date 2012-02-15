--[[------------------------------------------------------

  kinect.Context test
  -------------------

  Obviously, only run these tests with hardware connected.

--]]------------------------------------------------------
require 'lubyk'

local should = test.Suite('kinect.Context')

function should.initializeContext()
  local ctx
  assertPass(function()
    ctx = kinect.Context()
  end)
  assertEqual('kinect.Context', ctx.type)
end

test.all()
